
retdec_install("-D RETDEC_ENABLE_CPDETECT=ON")

find_package(retdec 4.0 REQUIRED COMPONENTS cpdetect)

add_executable(cpdetect-example cpdetect-example.cpp)
target_link_libraries(cpdetect-example PUBLIC retdec::cpdetect)
