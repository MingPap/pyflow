# Author: Deepak Pathak (c) 2016
# Additional changes by Phil Ferriere
# To install and compile to your anaconda/python site-packages, simply run:
# $ pip install git+https://github.com/philferriere/pyflow.git

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

from distutils.core import setup
from Cython.Build import cythonize
from distutils.extension import Extension
from glob import glob
import sys
import numpy

sourcefiles = ['pyflow.pyx', ]
sourcefiles.extend(glob("src/*.cpp"))
if sys.platform.startswith("win"):
  extensions = [Extension("pyflow", sourcefiles, include_dirs=[numpy.get_include()])]
else:
  extensions = [Extension("pyflow", sourcefiles, include_dirs=[numpy.get_include()], extra_compile_args=["-D_LINUX_MAC"])]

setup(
  name="pyflow",
  version="1.0",
  description="Python wrapper for the Coarse2Fine Optical Flow code.",
  author="Deepak Pathak",
  ext_modules=cythonize(extensions),
  include_dirs=[numpy.get_include()]
)
