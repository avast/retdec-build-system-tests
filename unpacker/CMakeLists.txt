
retdec_install("-D RETDEC_ENABLE_UNPACKER=ON")

find_package(retdec 4.0 REQUIRED COMPONENTS unpacker)

add_executable(unpacker-example unpacker-example.cpp)
target_link_libraries(unpacker-example PUBLIC retdec::unpacker)
