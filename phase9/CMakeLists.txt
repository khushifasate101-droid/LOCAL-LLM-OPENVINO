cmake_minimum_required(VERSION 3.20)

project(Phase9KVCache LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OV_ROOT
    "/opt/intel/openvino_genai_2026.4.1/runtime"
)

set(OpenVINO_DIR "${OV_ROOT}/cmake")

find_package(OpenVINO REQUIRED COMPONENTS Runtime)

add_executable(phase9_chat
    src/main.cpp
)

add_executable(kv_cache_experiment
    src/kv_cache_experiment.cpp
)

foreach(TARGET phase9_chat kv_cache_experiment)

    target_include_directories(${TARGET} PRIVATE
        "${OV_ROOT}/include"
    )

    target_link_libraries(${TARGET} PRIVATE
        openvino::runtime
        "${OV_ROOT}/lib/arm64/Release/libopenvino_genai.dylib"
    )

    set_target_properties(${TARGET} PROPERTIES
        BUILD_RPATH
        "${OV_ROOT}/lib/arm64/Release;${OV_ROOT}/3rdparty/tbb/lib"
    )

endforeach()