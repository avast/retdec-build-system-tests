
retdec_install("-D RETDEC_ENABLE_LLVM_SUPPORT=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS llvm-support)

add_executable(llvm-support-example llvm-support-example.cpp)
target_link_libraries(llvm-support-example PUBLIC retdec::llvm-support)
