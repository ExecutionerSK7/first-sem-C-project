cmake_minimum_required(VERSION 3.19.2)

project(prms)

add_subdirectory(include)
#add_subdirectory(src)

add_executable(prms src/source.c)

target_link_libraries(prms PRIVATE rlutil)
set_target_properties(rlutil PROPERTIES LINKER_LANGUAGE CXX)

