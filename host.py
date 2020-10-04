import tensorflow as tf
import argparse
import sys

def dist():
    cluster=tf.train.ClusterSpec({"ps": ["172.28.0.2:2222"],"worker": ["172.28.0.2:2233"]})
    server = tf.train.Server(cluster, job_name="ps", task_index=0)
    server.join()

if __name__ == "_main_":
    dist()
