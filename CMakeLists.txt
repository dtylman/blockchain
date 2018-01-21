project(BloockChain)

cmake_minimum_required(VERSION 2.8.12)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

conan_basic_setup()

add_subdirectory(src)

include_directories("include")

add_executable(blockchain BlockChainApp.cpp)

target_link_libraries(blockchain bclib ${CONAN_LIBS})
