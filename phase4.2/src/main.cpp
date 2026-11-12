
#include "openvino/genai/llm_pipeline.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    try {
        string model_path = "./phase4.2/models_clean";

        cout << "Loading fresh OpenVINO model..." << endl;

        ov::genai::LLMPipeline pipe(model_path, "CPU");

        ov::genai::GenerationConfig config = pipe.get_generation_config();
        config.max_new_tokens = 40;
        config.do_sample = false;

        cout << "\nTest 1: " << endl;
        cout << pipe.generate("The capital of France is", config) << endl;

        cout << "\nTest 2: " << endl;
        cout << pipe.generate("What is OpenVINO?", config) << endl;

        cout << "\nTest 3: " << endl;
        cout << pipe.generate("Explain AI in simple words:", config) << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
