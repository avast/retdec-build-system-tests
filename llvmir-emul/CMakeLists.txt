
retdec_install("-D RETDEC_ENABLE_LLVMIR_EMUL=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS llvmir-emul)

add_executable(llvmir-emul-example llvmir-emul-example.cpp)
target_link_libraries(llvmir-emul-example PUBLIC retdec::llvmir-emul)
