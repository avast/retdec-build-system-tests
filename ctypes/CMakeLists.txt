
retdec_install("-D RETDEC_ENABLE_CTYPES=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS ctypes)

add_executable(ctypes-example ctypes-example.cpp)
target_link_libraries(ctypes-example PUBLIC retdec::ctypes)
