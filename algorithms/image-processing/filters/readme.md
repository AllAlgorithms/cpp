In this one I would like to present you some digital image processing algorithms implemented with C++ and OpenCV.
Although, OpenCV supports most of these algorithms out-of-the-box what I am trying to show you actually is how you could implement these manually with C++. So, OpenCV is used here just only for opening and manipulating an image as a Mat object (OpenCV’s basic image container).
Below, are the digital image processing algorithms:
A. Adding noise to images
Gaussian noise
Salt & Pepper noise
B. Removing noise from images (using filters)
Mean filter
Median filter
C. Detecting edges in images (using detectors)
Prewitt detector
Sobel detector
D. Segmenting an image
Adaptive thresholding
