
#include <openvino/genai/llm_pipeline.hpp>

#include <chrono>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string model_path =
        "phase6/models/llama-3.2-3b-instruct-ov";

    const string prompt =
        "Explain artificial intelligence in simple words.";

    try
    {
        using Clock = chrono::steady_clock;

        cout << "Loading Phase 6 INT4 model...\n";

        auto load_start = Clock::now();
        ov::genai::LLMPipeline pipeline(model_path, "CPU");
        auto load_end = Clock::now();

        double load_seconds =
            chrono::duration<double>(
                load_end - load_start).count();

        ov::genai::GenerationConfig config;
        config.max_new_tokens = 30;

        cout << "Generating response...\n";

        auto generation_start = Clock::now();
        auto result = pipeline.generate(prompt, config);
        auto generation_end = Clock::now();

        double generation_seconds =
            chrono::duration<double>(
                generation_end - generation_start).count();

        if (!result.texts.empty())
            cout << "\nModel response:\n"
                 << result.texts[0] << '\n';
        else
            cout << "\nNo text returned.\n";

        auto &metrics = result.perf_metrics;

        cout << fixed << setprecision(3);

        cout << "\n--- Phase 6 Performance Results ---\n";
        cout << "Model: " << model_path << '\n';
        cout << "Device: CPU\n";
        cout << "Loading time: "
             << load_seconds << " seconds\n";
        cout << "Generation time: "
             << generation_seconds << " seconds\n";

        cout << "Input tokens: "
             << metrics.get_num_input_tokens() << '\n';

        cout << "Generated tokens: "
             << metrics.get_num_generated_tokens() << '\n';

        cout << "TTFT: "
             << metrics.get_ttft().mean << " ms\n";

        cout << "Throughput: "
             << metrics.get_throughput().mean
             << " tokens/second\n";

        cout << "TPOT: "
             << metrics.get_tpot().mean << " ms\n";
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
