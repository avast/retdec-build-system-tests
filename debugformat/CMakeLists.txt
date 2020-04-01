
retdec_install("-D RETDEC_ENABLE_DEBUGFORMAT=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS debugformat)

add_executable(debugformat-example debugformat-example.cpp)
target_link_libraries(debugformat-example PUBLIC retdec::debugformat)
