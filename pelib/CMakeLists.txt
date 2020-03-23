
set(RETDEC_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/retdec-install")

configure_file(
    install/CMakeLists.txt
    "${CMAKE_CURRENT_BINARY_DIR}/retdec-download/CMakeLists.txt"
)

execute_process(
    COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/retdec-download"
)

execute_process(
    COMMAND "${CMAKE_COMMAND}" --build . -- -j8
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/retdec-download"
)

list(APPEND CMAKE_PREFIX_PATH "${RETDEC_INSTALL_DIR}")

find_package(pelib 4.0 REQUIRED NAMES pelib retdec)
#find_package(RetDec 4.0 REQUIRED COMPONENTS pelib)

add_executable(pelib-example pelib-example.cpp)
#target_link_libraries(RetDec::pelib)
target_link_libraries(pelib)
