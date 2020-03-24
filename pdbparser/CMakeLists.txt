
retdec_install("-D RETDEC_ENABLE_PDBPARSER=ON")

find_package(retdec 4.0 REQUIRED COMPONENTS pdbparser)

add_executable(pdbparser-example pdbparser-example.cpp)
target_link_libraries(pdbparser-example PUBLIC retdec::pdbparser)
