
cmake_minimum_required(VERSION 3.6)

project(retdec-build-system-tests
    LANGUAGES C CXX
)

# Check that all required variables are set.
#
if(NOT RETDEC_PATH)
    message(FATAL_ERROR "Path to RetDec was not specified. \
Use -DRETDEC_PATH=<path>.")
endif()

# RetDec installation macro.
# ARGV0 : RETDEC_ENABLE_OPTIONS
#
macro(retdec_install)
    set(RETDEC_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/retdec-install")

    # Configure RetDec installation script.
    set(RETDEC_ENABLE_OPTIONS "${ARGV0}")
    configure_file(
        "${PROJECT_SOURCE_DIR}/retdec-install.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/retdec-download/CMakeLists.txt"
    )

    # Configure RetDec build.
    execute_process(
        COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/retdec-download"
    )

    # Build and install RetDec.
    if(MSVC)
        execute_process(
            COMMAND "${CMAKE_COMMAND}" --build . --config Release -- -m
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/retdec-download"
        )
    else()
        include(ProcessorCount)
        ProcessorCount(N)
        execute_process(
            COMMAND "${CMAKE_COMMAND}" --build . -- -j${N}
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/retdec-download"
        )
    endif()

    # Add RetDec installation directory to CMake prefix
    # -> find_package() will be able to find RetDec and its components.
    list(APPEND CMAKE_PREFIX_PATH "${RETDEC_INSTALL_DIR}")
endmacro()

# Add all the examples.
#

#add_subdirectory(common)
add_subdirectory(crypto)
#add_subdirectory(ctypes)
#add_subdirectory(pdbparser)
#add_subdirectory(pelib)
#add_subdirectory(serdes)
#add_subdirectory(utils)
#add_subdirectory(yaracpp)
