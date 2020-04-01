
retdec_install("-D RETDEC_ENABLE_LLVMIR2HLL=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS llvmir2hll)

add_executable(llvmir2hll-example llvmir2hll-example.cpp)
target_link_libraries(llvmir2hll-example PUBLIC retdec::llvmir2hll)
