## Fork of https://github.com/pathak22/pyflow.git

This fork modifies Deepak Pathak's ([@pathak22](https://github.com/pathak22))original implementation so that it can properly build on Windows. Based on the OS, `setup.py` sets the proper compiler flags. If setting up on Windows, make sure the Visual C++ build tools are on your path (see below).

This fork also picks up changes made by Michael Williams ([@mpwillia](https://github.com/mpwillia)). See [here](https://github.com/mpwillia/pyflow/commit/41ec6793e8e244850540bfaa3eaa097b2ac2f3d2) for details.

## Python Dense Optical Flow

This is a **Python** wrapper for Ce Liu's [C++ implementation](https://people.csail.mit.edu/celiu/OpticalFlow/) of Coarse2Fine Optical Flow. It's **super fast and accurate** optical flow method based on Coarse2Fine warping method from Thomas Brox. This python wrapper has minimal dependencies, and it also eliminates the need for C++ OpenCV library. For real time performance, one can additionally resize the images to a smaller size. 

For more information about Deepak's wrapper, see [here](https://github.com/pathak22/pyflow.git).

## Setup instructions (all platforms)

Run the following steps to download, install and demo the library:

To install this package, use `pip` as follows:

```shell
(dlwin36coco) pferr@MSI e:\repos
$ pip install git+https://github.com/philferriere/pyflow.git
TODO - copy log here
```

## Additional setup instructions (Windows 10)

For this package to build, you must have the Visual C++ 2015 build tools on your path. If you don't, install them from [here](http://landinghub.visualstudio.com/visual-cpp-build-tools):

![](img/download.png)

Then, run `visualcppbuildtools_full.exe` and select default options:

![](img/install.png)