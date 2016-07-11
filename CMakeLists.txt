
cmake_minimum_required(VERSION 3.3)
enable_language(CXX) # SINCE Compiler/Platform variables do not normally exist before a project command in CMake.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
include(cmake-tools/scripts/generator-key.cmake)

#set(LOCAL_HEADER 1)
include(local-config.cmake OPTIONAL)

get_filename_component(PARENT_DIR ${CMAKE_BINARY_DIR} DIRECTORY)

if (NOT MINGW)
  project(ground)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PARENT_DIR}/bin)
else ()
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PARENT_DIR}/build/mingw/bin)
endif ()


include(cmake-tools/cmake-tools.cmake)

add_subdirectory(projects/ground_engine)
add_subdirectory(projects/ground_cli)

include(local-config.cmake OPTIONAL)
