
retdec_install("-D RETDEC_ENABLE_MACHO_EXTRACTOR=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS macho-extractor)

add_executable(macho-extractor-example macho-extractor-example.cpp)
target_link_libraries(macho-extractor-example PUBLIC retdec::macho-extractor)
