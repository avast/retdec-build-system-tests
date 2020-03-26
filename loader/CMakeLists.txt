
retdec_install("-D RETDEC_ENABLE_LOADER=ON")

find_package(retdec 4.0 REQUIRED COMPONENTS loader)

add_executable(loader-example loader-example.cpp)
target_link_libraries(loader-example PUBLIC retdec::loader)
