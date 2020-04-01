
retdec_install("-D RETDEC_ENABLE_CAPSTONE2LLVMIR=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS capstone2llvmir)

add_executable(capstone2llvmir-example capstone2llvmir-example.cpp)
target_link_libraries(capstone2llvmir-example PUBLIC retdec::capstone2llvmir)
