
retdec_install("-D RETDEC_ENABLE_BIN2LLVMIR=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS bin2llvmir)

add_executable(bin2llvmir-example bin2llvmir-example.cpp)
target_link_libraries(bin2llvmir-example PUBLIC retdec::bin2llvmir)
