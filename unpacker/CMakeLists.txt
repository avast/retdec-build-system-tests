
retdec_install("-D RETDEC_ENABLE_UNPACKER=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS unpacker)

add_executable(unpacker-example unpacker-example.cpp)
target_link_libraries(unpacker-example PUBLIC retdec::unpacker)
