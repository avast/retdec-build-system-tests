
retdec_install("-D RETDEC_ENABLE_CTYPESPARSER=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS ctypesparser)

add_executable(ctypesparser-example ctypesparser-example.cpp)
target_link_libraries(ctypesparser-example PUBLIC retdec::ctypesparser)
