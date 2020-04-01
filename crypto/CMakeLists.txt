
retdec_install("-D RETDEC_ENABLE_CRYPTO=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS crypto)

add_executable(crypto-example crypto-example.cpp)
target_link_libraries(crypto-example PUBLIC retdec::crypto)
