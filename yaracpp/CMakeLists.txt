
retdec_install("-D RETDEC_ENABLE_YARACPP=ON")

find_package(retdec 4.0 REQUIRED COMPONENTS yaracpp)

add_executable(yaracpp-example yaracpp-example.cpp)
target_link_libraries(yaracpp-example PUBLIC retdec::yaracpp)
