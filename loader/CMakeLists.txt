
retdec_install("-D RETDEC_ENABLE_LOADER=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS loader)

add_executable(loader-example loader-example.cpp)
target_link_libraries(loader-example PUBLIC retdec::loader)
