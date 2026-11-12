cmake_minimum_required(VERSION 3.16)
project(TinyLlamaTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenVINO REQUIRED COMPONENTS Runtime)
find_package(OpenVINOGenAI REQUIRED)

add_executable(test_tinyllama test_tinyllama.cpp)

target_link_libraries(test_tinyllama PRIVATE openvino::runtime openvino::genai)
