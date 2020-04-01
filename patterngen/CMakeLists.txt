
retdec_install("-D RETDEC_ENABLE_PATTERNGEN=ON")

find_package(retdec ${RETDEC_VERSION} REQUIRED COMPONENTS patterngen)

add_executable(patterngen-example patterngen-example.cpp)
target_link_libraries(patterngen-example PUBLIC retdec::patterngen)
