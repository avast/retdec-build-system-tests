
retdec_install("-D RETDEC_ENABLE_CONFIG=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS config)

add_executable(config-example config-example.cpp)
target_link_libraries(config-example PUBLIC retdec::config)
