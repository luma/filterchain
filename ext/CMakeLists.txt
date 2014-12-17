include (ExternalProject)

# dependencies will end up in a shared library so the objects must be relocatable
set (EXT_CXX_FLAGS "-g -O2 -fPIC")

externalproject_add (gtest-1.7.0
  URL http://googletest.googlecode.com/files/gtest-1.7.0.zip
  CMAKE_ARGS -DBUILD_SHARED_LIBS:BOOL=0 -DCMAKE_CXX_FLAGS=${EXT_CXX_FLAGS}
  BUILD_IN_SOURCE 1
  INSTALL_COMMAND "")

externalproject_add (gmock-1.7.0
  URL http://googlemock.googlecode.com/files/gmock-1.7.0.zip
  CMAKE_ARGS -DBUILD_SHARED_LIBS:BOOL=0 -DCMAKE_CXX_FLAGS=${EXT_CXX_FLAGS}
  BUILD_IN_SOURCE 1
  INSTALL_COMMAND "")
