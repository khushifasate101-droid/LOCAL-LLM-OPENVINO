cmake_minimum_required(VERSION 3.16)
project(local_llm)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(OpenVINO REQUIRED)
find_package(OpenVINOGenAI REQUIRED)
add_executable(local_llm
    src/main.cpp
)
target_link_libraries(local_llm
    PRIVATE
    openvino::runtime
    openvino::genai
)