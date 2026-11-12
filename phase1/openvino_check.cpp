#include <openvino/openvino.hpp>
#include <iostream>

int main() {
    ov::Core core;

    std::cout << "OpenVINO is working!" << std::endl;

    std::cout << "Available devices:" << std::endl;

    for (const auto& device : core.get_available_devices()) {
        std::cout << "  " << device << std::endl;
    }

    return 0;
}
