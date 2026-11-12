cmake_minimum_required(VERSION 3.20)
project(Phase6Llama LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OV_ROOT "/opt/intel/openvino_genai_2026.4.1/runtime")
set(OV_LIB "${OV_ROOT}/lib/arm64/Release")

find_package(OpenVINOGenAI REQUIRED CONFIG
    PATHS "${OV_ROOT}/cmake"
    NO_DEFAULT_PATH
)

add_executable(phase6_llama src/main.cpp)

target_include_directories(phase6_llama PRIVATE
    "${OV_ROOT}/include"
)

target_link_libraries(phase6_llama PRIVATE
    "${OV_LIB}/libopenvino_genai.dylib"
    openvino::runtime
)

set_target_properties(phase6_llama PROPERTIES
    BUILD_RPATH "${OV_LIB}"
)
