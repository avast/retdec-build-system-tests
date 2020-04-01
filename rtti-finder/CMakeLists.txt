
retdec_install("-D RETDEC_ENABLE_RTTI_FINDER=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS rtti-finder)

add_executable(rtti-finder-example rtti-finder-example.cpp)
target_link_libraries(rtti-finder-example PUBLIC retdec::rtti-finder)
