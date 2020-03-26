
retdec_install("-D RETDEC_ENABLE_FILEFORMAT=ON")

find_package(retdec 4.0 REQUIRED COMPONENTS fileformat)

add_executable(fileformat-example fileformat-example.cpp)
target_link_libraries(fileformat-example PUBLIC retdec::fileformat)
