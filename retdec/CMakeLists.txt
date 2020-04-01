
retdec_install("-D RETDEC_ENABLE_RETDEC=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS retdec)

add_executable(retdec-example retdec-example.cpp)
target_link_libraries(retdec-example PUBLIC retdec::retdec)
