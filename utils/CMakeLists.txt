
retdec_install("-D RETDEC_ENABLE_UTILS=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS utils)

add_executable(utils-example utils-example.cpp)
target_link_libraries(utils-example PUBLIC retdec::utils)
