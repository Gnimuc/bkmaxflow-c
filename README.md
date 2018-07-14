# bkmaxflow-c
C bindings for Vladimir Kolmogorov's Max-flow/min-cut library([Boykov-Kolmogorov algorithm](http://www.csd.uwo.ca/faculty/yuri/Abstracts/pami04-abs.shtml)).

## Usage
### Download and unzip the source code
The maxflow-v3.01 library: http://vision.csd.uwo.ca/code/maxflow-v3.01.zip

The file hierarchy looks like this:
```
bkmaxflow-c |
            | CMakeLists.txt
            | bk.cpp
            | bk.h
            | block.h
            | graph.cpp
            | graph.h
            | instances.inc
            | maxflow.cpp
            ...
```

### Build
Comment the last line of `maxflow.cpp` firstly:
```c
// #include "instances.inc"
```
then
```shell
mkdir build && cd build
cmake ..
make
```

## LICENSE
Only the wrapper in this repo is licensed under MIT license, note the maxflow-v3.01 library has its own license.
