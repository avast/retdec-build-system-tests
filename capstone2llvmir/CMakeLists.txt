
retdec_install("-D RETDEC_ENABLE_CAPSTONE2LLVMIR=ON")

find_package(retdec 4.0 REQUIRED COMPONENTS capstone2llvmir)

add_executable(capstone2llvmir-example capstone2llvmir-example.cpp)
target_link_libraries(capstone2llvmir-example PUBLIC retdec::capstone2llvmir)
