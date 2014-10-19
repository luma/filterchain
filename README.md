filterchain
===========

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
