
retdec_install("-D RETDEC_ENABLE_COMMON=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS common)

add_executable(common-example common-example.cpp)
target_link_libraries(common-example PUBLIC retdec::common)
