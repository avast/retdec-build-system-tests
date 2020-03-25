
retdec_install("-D RETDEC_ENABLE_AR_EXTRACTOR=ON")

find_package(retdec 4.0 REQUIRED COMPONENTS ar-extractor)

add_executable(ar-extractor-example ar-extractor-example.cpp)
target_link_libraries(ar-extractor-example PUBLIC retdec::ar-extractor)
