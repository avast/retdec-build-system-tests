
retdec_install("-D RETDEC_ENABLE_DEMANGLER=ON")

find_package(retdec 4.0 REQUIRED COMPONENTS demangler)

add_executable(demangler-example demangler-example.cpp)
target_link_libraries(demangler-example PUBLIC retdec::demangler)
