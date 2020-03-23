cmake_minimum_required(VERSION 3.6)
project(pelib NONE)

include(ExternalProject)

ExternalProject_Add(retdec
    DOWNLOAD_COMMAND ""
    SOURCE_DIR ${RETDEC_PATH}
    CMAKE_ARGS
        # Install on passed location.
        -D CMAKE_INSTALL_PREFIX=${RETDEC_INSTALL_DIR}
        # Enable only those RetDec components that are actually used.
        -D RETDEC_ENABLE_PELIB=ON
        # Propagate some basic defines.
        -D CMAKE_BUILD_TYPE=Release
        -D CMAKE_C_COMPILER=${CMAKE_C_COMPILER}
        -D CMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
)
