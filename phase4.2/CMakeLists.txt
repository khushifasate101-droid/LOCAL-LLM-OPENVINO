
cmake_minimum_required(VERSION 3.16)

project(phase42_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenVINO REQUIRED)
find_package(OpenVINOGenAI REQUIRED)

add_executable(phase42_test
    src/main.cpp
)

target_link_libraries(phase42_test
    PRIVATE
    openvino::runtime
    openvino::genai
)
