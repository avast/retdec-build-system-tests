
retdec_install("-D RETDEC_ENABLE_CRYPTO=ON")

find_package(retdec 4.0 REQUIRED COMPONENTS crypto)

add_executable(crypto-example crypto-example.cpp)
target_link_libraries(crypto-example PUBLIC retdec::crypto)
