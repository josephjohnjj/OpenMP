Profiling is a method by which we measure the performance of an application. We will be concentrating on score-p tool (http://www.vi-hps.org/projects/score-p/) for profiling the OpenMP code. 
![Alt text](profiling.png?raw=true "Image taken from https://silc.zih.tu-dresden.de/scorep-current/")

Installations steps

1. Install QT. QT can installed using the command  apt-get install qt4-dev-tools libqt4-dev libqt4-core libqt4-gui.
2. Install cube4
3. Install score-p

Each individual installation above will have its own depdendencies. For exammple cube4 will have a dependency for zlib and that will have to be installed first before we install cube4.

The architecture of score-p is as given below.
![Alt text](architecture.png?raw=true "Image taken from https://silc.zih.tu-dresden.de/scorep-current/")

To instrument an openmp code use the following command

scorep gcc first.c --openmp

After compiling we can run the executable. When the executable is run, a folder with the profile will be created. To view the profiling information we can use the command 

cube profile.cubex

The command displays three tree browsers, each of them representing a different dimension of the aspect of the performance. Left tree displays the metric dimension, the middle tree displays the program dimension, and the right tree displays the system dimension. The nodes in the system dimension represent machines, nodes, processes, or threads from top to bottom.


