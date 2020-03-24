
retdec_install("-D RETDEC_ENABLE_SERDES=ON")

find_package(retdec 4.0 REQUIRED COMPONENTS serdes)

add_executable(serdes-example serdes-example.cpp)
target_link_libraries(serdes-example PUBLIC retdec::serdes)
