cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_BUILD_TYPE Debug )

project(doudizhu)

include_directories(
  include
  )

# aux_source_directory(main.cpp SRC_DIR)

set(SRC_FILE src)

aux_source_directory(src SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST} main.cpp)


