import tensorflow as tf
import horovod.tensorflow as hvd

def solve():
  hvd.init()
  gpus = tf.config.experimental.list_physical_devices('GPU')
  for gpu in gpus:
    tf.config.experimental.set_memory_growth(gpu, True)
  if gpus:
    tf.config.experimental.set_visible_devices(gpus[hvd.local_rank()], 'GPU')

  (mnist_images, mnist_labels), _ = \
    tf.keras.datasets.mnist.load_data(path='mnist-%d.npz' % hvd.rank())

  dataset = tf.data.Dataset.from_tensor_slices(
    (tf.cast(mnist_images[..., tf.newaxis] / 255.0, tf.float32),
             tf.cast(mnist_labels, tf.int64))
  )
  dataset = dataset.repeat().shuffle(10000).batch(128)

  mnist_model = tf.keras.Sequential([
    tf.keras.layers.Conv2D(32, [3, 3], activation='relu'),
    tf.keras.layers.Conv2D(64, [3, 3], activation='relu'),
    tf.keras.layers.MaxPooling2D(pool_size=(2, 2)),
    tf.keras.layers.Dropout(0.25),
    tf.keras.layers.Flatten(),
    tf.keras.layers.Dense(128, activation='relu'),
    tf.keras.layers.Dropout(0.5),
    tf.keras.layers.Dense(10, activation='softmax')
  ])

  loss = tf.losses.SparseCategoricalCrossentropy()

  # Horovod: adjust learning rate based on number of GPUs.
  opt = tf.optimizers.Adam(0.001 * hvd.size())

  checkpoint_dir = './checkpoints'
  checkpoint = tf.train.Checkpoint(model=mnist_model, optimizer=opt)


def training_step(images, labels, first_batch):
    with tf.GradientTape() as tape:
        probs = mnist_model(images, training=True)
        loss_value = loss(labels, probs)

    # Horovod: add Horovod Distributed GradientTape.
    tape = hvd.DistributedGradientTape(tape)

    grads = tape.gradient(loss_value, mnist_model.trainable_variables)
    opt.apply_gradients(zip(grads, mnist_model.trainable_variables))

    # Horovod: broadcast initial variable states from rank 0 to all other processes.
    # This is necessary to ensure consistent initialization of all workers when
    # training is started with random weights or restored from a checkpoint.
    #
    # Note: broadcast should be done after the first gradient step to ensure optimizer
    # initialization.
    if first_batch:
        hvd.broadcast_variables(mnist_model.variables, root_rank=0)
        hvd.broadcast_variables(opt.variables(), root_rank=0)

    return loss_value
    
def mnist_train(clustr,ser):

  print("This is worker’s job!!")
  with tf.device(tf.train.replica_device_setter(worker_device = "/job:worker/task:%d" % 0,cluster = clstr)):
    solve()
  hooks = [tf.train.StopAtStepHook(last_step = 10000)]
  with tf.train.MonitoredTrainingSession(master = srv.target,is_chief = True,checkpoint_dir = "/tmp/log_dir",hooks = hooks):
    for batch, (images, labels) in enumerate(dataset.take(10000 // hvd.size())):
      loss_value = training_step(images, labels, batch == 0)
      if batch % 10 == 0 and hvd.local_rank() == 0:
        print('Step #%d\tLoss: %.6f' % (batch, loss_value))

def dist():
    cluster=tf.train.ClusterSpec({"ps": ["172.28.0.2:2222"],"worker": ["172.28.0.2:2233"]})
    server = tf.train.Server(cluster, job_name="worker", task_index=1)
    mnist_train(cluster, server)

if __name__ == "_main_":
    dist()
  
