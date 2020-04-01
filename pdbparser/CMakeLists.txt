
retdec_install("-D RETDEC_ENABLE_PDBPARSER=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS pdbparser)

add_executable(pdbparser-example pdbparser-example.cpp)
target_link_libraries(pdbparser-example PUBLIC retdec::pdbparser)
