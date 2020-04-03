
cmake_minimum_required(VERSION 3.8)

project(retdec-build-system-tests
    LANGUAGES C CXX
)

set(RETDEC_VERSION ${RETDEC_VERSION})

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
    set(RETDEC_DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/retdec-download")
    set(RETDEC_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/retdec-install")

    # Configure RetDec installation script.
    set(RETDEC_ENABLE_OPTIONS "${ARGV0}")
    configure_file(
        "${PROJECT_SOURCE_DIR}/retdec-install.cmake.in"
        "${RETDEC_DOWNLOAD_DIR}/CMakeLists.txt"
    )

    # Configure RetDec build.
    execute_process(
        COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${RETDEC_DOWNLOAD_DIR}"
    )

    # Build and install RetDec.
    if(MSVC)
        execute_process(
            COMMAND "${CMAKE_COMMAND}" --build . --config Release -- -m
            WORKING_DIRECTORY "${RETDEC_DOWNLOAD_DIR}"
        )
    else()
        include(ProcessorCount)
        ProcessorCount(N)
        execute_process(
            COMMAND "${CMAKE_COMMAND}" --build . -- -j${N}
            WORKING_DIRECTORY "${RETDEC_DOWNLOAD_DIR}"
        )
    endif()

    # Move installed directory to test that installed RetDec movable.
    # I.e. no absolute paths, etc.
    set(RETDEC_INSTALL_DIR_MOVED "${CMAKE_CURRENT_BINARY_DIR}/retdec-install-moved")
    file(RENAME "${RETDEC_INSTALL_DIR}" "${RETDEC_INSTALL_DIR_MOVED}")

    # Remove build direcotry to test that no build artifacts are needed by
    # installed RetDec.
    # I.e. no absolute paths to build directory.
    file(REMOVE_RECURSE "${RETDEC_DOWNLOAD_DIR}")

    # Add RetDec installation directory to CMake prefix
    # -> find_package() will be able to find RetDec and its components.
    # NOTE:
    #   This may cause confusion between multiple installed RetDecs.
    #   E.g. utils & yaracpp installed, retdec-config.cmake from utils tries
    #   to find yaracpp config because it thinks it is its component.
    #list(APPEND CMAKE_PREFIX_PATH "${RETDEC_INSTALL_DIR_MOVED}")
    # This does not have the same problem.
    set(retdec_DIR "${RETDEC_INSTALL_DIR_MOVED}/share/retdec/cmake")
endmacro()

# Add all the examples.
#

#add_subdirectory(all)
#add_subdirectory(ar-extractor)
#add_subdirectory(ar-extractortool)
#add_subdirectory(bin2llvmir)
#add_subdirectory(bin2llvmirtool)
#add_subdirectory(bin2pat)
#add_subdirectory(capstone2llvmir)
#add_subdirectory(capstone2llvmirtool)
#add_subdirectory(common)
#add_subdirectory(config)
#add_subdirectory(configtool)
#add_subdirectory(cpdetect)
#add_subdirectory(crypto)
#add_subdirectory(ctypes)
#add_subdirectory(ctypesparser)
#add_subdirectory(debugformat)
#add_subdirectory(demangler)
#add_subdirectory(demanglertool)
#add_subdirectory(doc)
#add_subdirectory(fileformat)
#add_subdirectory(fileinfo)
#add_subdirectory(getsig)
#add_subdirectory(idr2pat)
#add_subdirectory(llvm-support)
#add_subdirectory(llvmir-emul)
#add_subdirectory(llvmir2hll)
#add_subdirectory(llvmir2hlltool)
#add_subdirectory(loader)
#add_subdirectory(macho-extractor)
#add_subdirectory(macho-extractortool)
#add_subdirectory(pat2yara)
#add_subdirectory(patterngen)
#add_subdirectory(pdbparser)
#add_subdirectory(pelib)
#add_subdirectory(retdec)
#add_subdirectory(retdectool)
#add_subdirectory(rtti-finder)
#add_subdirectory(serdes)
#add_subdirectory(stacofin)
#add_subdirectory(stacofintool)
#add_subdirectory(unpacker)
#add_subdirectory(unpackertool)
#add_subdirectory(utils)
#add_subdirectory(yaracpp)
