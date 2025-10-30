cmake_minimum_required(VERSION 3.10)
project(TestGMPModule)

set(GMP_INCLUDE_DIR "$ENV{BUILD_ROOT}/deps/${CMAKE_OSX_ARCHITECTURES}/gmp-6.3.0/include")
set(GMP_LIBRARY "$ENV{BUILD_ROOT}/deps/${CMAKE_OSX_ARCHITECTURES}/gmp-6.3.0/lib/libgmp.a")
include_directories(${GMP_INCLUDE_DIR})
add_library(hello MODULE hello_pure_gmp.cpp)
target_link_libraries(hello ${GMP_LIBRARY})
set_target_properties(hello PROPERTIES PREFIX "" SUFFIX ".so")
