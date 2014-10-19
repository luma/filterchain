filterchain
===========

A small project to allow a chain of filters to be executed, broadly modeled after the filters from Mantis. In this case the filters are actually written in JS and executed from C++ via V8. The idea being that it should be possible to add and remove filters safely while the system is running.

This is just a messy experiment right now.


## Building

### MacOS
```
brew install cmake openssl log4cxx v8

sudo mkdir /var/log/tokbox
sudo chown -R $(whoami):$(ls -ld ~/ | awk '{print $4}') /var/log/tokbox

mkdir build
cd build
cmake ..
make
```
