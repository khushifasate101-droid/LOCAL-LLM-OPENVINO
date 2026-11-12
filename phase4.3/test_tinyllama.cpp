
#include <openvino/genai/llm_pipeline.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <exception>
using namespace std;
int main()
{
    try
    {
        const string model_path = "phase4.3/models/tinyllama_int4";
        using Clock = chrono::steady_clock;
        cout << "======================================" << endl;
        cout << "   Local LLM using OpenVINO GenAI" << endl;
        cout << "======================================" << endl;
        cout << "Loading TinyLlama model on CPU..." << endl;
        auto load_start = Clock::now();
        ov::genai::LLMPipeline pipe(model_path, "CPU");
        auto load_end = Clock::now();
        double load_seconds =
            chrono::duration<double>(load_end - load_start).count();
        cout << "Model loaded successfully!" << endl;
        cout << "Model loading time: " << load_seconds
             << " seconds" << endl;
        cout << "Type 'exit' to quit." << endl;
        while (true)
        {
            string prompt;
            cout << "\nEnter your prompt: ";
            getline(cin, prompt);
            if (prompt == "exit" || prompt == "EXIT")
            {
                cout << "Exiting application. Goodbye!" << endl;
                break;
            }
            if (prompt.empty())
            {
                cout << "Please enter a prompt." << endl;
                continue;
            }
            ov::genai::GenerationConfig config;
            config.max_new_tokens = 30;
            cout << "\nGenerating response...\n"
                 << endl;
            auto generation_start = Clock::now();
            auto result = pipe.generate(prompt, config);
            auto &metrics = result.perf_metrics;

            cout << "Generated tokens: "
                 << metrics.get_num_generated_tokens() << endl;

            cout << "Input tokens: "
                 << metrics.get_num_input_tokens() << endl;

            auto throughput = metrics.get_throughput();
            if (throughput.mean > 0)
            {
                cout << "Throughput: " << throughput.mean
                     << " tokens/second" << endl;
            }
            auto generation_end = Clock::now();
            string response = result.texts.empty() ? "" : result.texts[0];
            double generation_seconds =
                chrono::duration<double>(
                    generation_end - generation_start)
                    .count();

            cout << "Response:\n"
                 << response << endl;
            cout << "\n--- Performance Results ---" << endl;
            cout << "Generation time: " << generation_seconds
                 << " seconds" << endl;
        }
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
