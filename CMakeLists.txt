
cmake_minimum_required(VERSION 3.6)

project(retdec-build-system-tests
    LANGUAGES C CXX
)

if(NOT RETDEC_PATH)
    message(FATAL_ERROR "Path to RetDec was not specified. \
Use -DRETDEC_PATH=<path>.")
endif()

add_subdirectory(pelib)
