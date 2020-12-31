cmake_minimum_required(VERSION 3.10)

project(mm_benchmarks CXX)

set (CMAKE_CXX_STANDARD 11)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(neon-gemm-kernel-benchmark neon-gemm-kernel-benchmark.cc)
set ( EIGEN3_INCLUDE_DIR "$ENV{EIGEN3_INCLUDE_DIR}" )
IF( NOT EIGEN3_INCLUDE_DIR )
    message( FATAL_ERROR "Please set the environment variable EIGEN3_INCLUDE_DIR")
ENDIF()

message("${CMAKE_MODULE_PATH}")
message("${EIGEN3_INCLUDE_DIR}")

add_executable(eigen_mm_benchmark eigen_mm_benchmark.cc)
target_include_directories(eigen_mm_benchmark PUBLIC "${EIGEN3_INCLUDE_DIR}")
