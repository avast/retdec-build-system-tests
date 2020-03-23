
retdec_install("-D RETDEC_ENABLE_PELIB=ON")

find_package(retdec 4.0 REQUIRED COMPONENTS pelib)

add_executable(pelib-example pelib-example.cpp)
target_link_libraries(pelib-example PUBLIC retdec::pelib)
