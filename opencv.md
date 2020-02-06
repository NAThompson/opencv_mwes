# Learning OpenCV

---

# Install on Mac 

```bash
$ brew install opencv@4
Warning: opencv dependency gcc was built with a different C++ standard
library (libstdc++ from clang). This may cause problems at runtime.
```

This warning is *somewhat* misleading, but still useful! It causes linker errors (due to ABI problems), not runtime errors.

Make sure to compile with `clang++` on Mac, or expect to suffer!

---

# Ridiculous

The latest version of OpenCV is 4.2, but here's how you `#include` files:

```cpp
#include <opencv2/core/core.hpp>
```

and your `INCFLAGS` need to have `-I/usr/local/include/opencv4`.

What a mess.


---

# Linking is a mess too

```bash
$ ls -l /usr/local/lib/libopencv_* | wc -l
     196
```

If you only link what you need, your linkflags will looks ridiculous: 

```
-lopencv_video -lopencv_videostab -lopencv_core ...
```

Recommendation: Use

```
$ pkg-config --cflags --libs opencv4
-I/usr/local/Cellar/opencv/4.2.0_1/include/opencv4/opencv -L/usr/local/Cellar/opencv/4.2.0_1/lib -lopencv_gapi -lopencv_stitching ...
```

and just put everything in your linkflags.

---

## `cv::Mat`: The basic object

You must understand `cv::Mat` to use opencv.

This is the basic container that holds images.

Point of confusion: `cv::Mat` supports everything. `std::vector`, `cuda::GpuMat`, `ogl::Buffer`.

---

## `cv::Mat`

These matrices are more general than a mathematical matrix. Namely, they have *channels*.

So we can have 1 channel of floats (a regular matrix), 2 channels (complex matrix), 3 channels of 8 bit uchar (RGB image).

---

## `cv::Mat` types

The data held in an element of the matrix is specified by a code:

- `CV_8UC1`: 8 but unsigned chars with 1 channel
- `CV_16S3`: 3 channels of 16 bit signed integers
- `CV_32FC2`: 32 bit floats with 2 channels
- `CV_64FC4`: 64 bit floats in 4 channels

---

### Initializing `cv::Mat`

```cpp
#include <opencv2/core/core.hpp>
// ...
int rows = 3;
int cols = 5;
cv::Mat m(rows, cols, CV_8UC1);
std::cout << "We have " << m.channels() << " channel.\n";
for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
        m.at<uchar>(i, j) = static_cast<uchar>(i+j);
    }
}
std::cout << m << "\n";
```

```bash
$ ./a.out
We have 1 channel.
[  0,   1,   2,   3,   4;
   1,   2,   3,   4,   5;
   2,   3,   4,   5,   6]
```

---

## `cv::Mat`: Initializing 2 channel matrix

```cpp
cv::Mat m(rows, cols, CV_32FC2);
std::cout << "We have " << m.channels() << " channels.\n";

for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
        m.at<cv::Point_<float>>(i, j) = cv::Point_<float>(i+j, i*i+j*j);
    }
}
std::cout << m << "\n";
```

```bash
$ ./a.out
We have 2 channels.
[0, 0, 1, 1, 2, 4, 3, 9, 4, 16;
 1, 1, 2, 2, 3, 5, 4, 10, 5, 17;
 2, 4, 3, 5, 4, 8, 5, 13, 6, 20]
```

---

## Intializing `cv::Mat`: 3 channels

```cpp
cv::Mat m(rows, cols, CV_8UC3);
for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
        m.at<cv::Point3_<uchar>>(i, j) = cv::Point3_<uchar>(i+j, i*i+j*j, i*i*i+j*j*j);
    }
}
```

