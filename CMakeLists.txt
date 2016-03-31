cmake_minimum_required(VERSION 3.5)
project(sysop)

set(CMAKE_C_FLAGS "-O3 ${CMAKE_C_FLAGS}")

file(GLOB SOURCE_FILES source/*.c)
foreach (source_file ${SOURCE_FILES})
    get_filename_component(executable_name ${source_file} NAME_WE)
    add_executable(${executable_name} ${source_file})
endforeach (source_file ${SOURCE_FILES})