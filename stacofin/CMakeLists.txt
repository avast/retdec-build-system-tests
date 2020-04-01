
retdec_install("-D RETDEC_ENABLE_STACOFIN=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS stacofin)

add_executable(stacofin-example stacofin-example.cpp)
target_link_libraries(stacofin-example PUBLIC retdec::stacofin)
