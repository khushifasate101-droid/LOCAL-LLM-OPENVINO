
#include "openvino/genai/llm_pipeline.hpp"
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

int main()
{
    try
    {
        string model_path = "./phase4/models";
        string prompt = "What is OpenVINO? Explain in simple words.";

        cout << "\n";
        cout << "============================================\n";
        cout << "       LOCAL LLM USING OPENVINO\n";
        cout << "============================================\n";

        cout << "\n[PROJECT DETAILS]\n";
        cout << "Model  : Qwen2.5-1.5B-Instruct INT4\n";
        cout << "Device : CPU\n";
        cout << "Format : OpenVINO IR\n";

        cout << "\n[STATUS] Loading model...\n";

        auto start_load = chrono::high_resolution_clock::now();

        ov::genai::LLMPipeline pipe(model_path, "CPU");

        auto end_load = chrono::high_resolution_clock::now();

        double load_time =
            chrono::duration<double>(end_load - start_load).count();

        cout << "[SUCCESS] Model loaded successfully!\n";
        cout << "Loading Time : " << load_time << " seconds\n";

        ov::genai::GenerationConfig config =
            pipe.get_generation_config();

        config.max_new_tokens = 40;
        config.do_sample = false;

        cout << "\n============================================\n";
        cout << "             MODEL TESTING\n";
        cout << "============================================\n";

        cout << "\n[QUESTION]\n";
        cout << prompt << "\n";

        cout << "\n[GENERATING RESPONSE...]\n";

        auto start_gen = chrono::high_resolution_clock::now();

        string response = pipe.generate(prompt, config);

        auto end_gen = chrono::high_resolution_clock::now();

        double generation_time =
            chrono::duration<double>(end_gen - start_gen).count();

        cout << "\n[MODEL RESPONSE]\n";
        cout << "--------------------------------------------\n";
        cout << response << "\n";
        cout << "--------------------------------------------\n";

        cout << "\n[PERFORMANCE DETAILS]\n";
        cout << "Generation Time : " << generation_time << " seconds\n";

        cout << "\n============================================\n";
        cout << "          TESTING COMPLETED\n";
        cout << "============================================\n\n";
    }
    catch (const exception& e)
    {
        cerr << "\n[ERROR] " << e.what() << endl;
        return 1;
    }

    return 0;
}
