#include <openvino/genai/llm_pipeline.hpp>
#include <chrono>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <sys/resource.h>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cerr << "Usage: ./phase8_benchmark <model_path>\n";
        return 1;
    }

    const string model_path = argv[1];
    const string prompt =
        "Explain artificial intelligence in simple words.";

    try
    {
        using Clock = chrono::steady_clock;

        cout << "Model: " << model_path << '\n';
        cout << "Device: CPU\n";

        cout << "\nLoading model...\n";
        auto load_start = Clock::now();

        ov::genai::LLMPipeline pipeline(model_path, "CPU");

        auto load_end = Clock::now();
        double load_seconds =
            chrono::duration<double>(load_end - load_start).count();

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
            cout << "\nModel response:\n" << result.texts[0] << '\n';

        struct rusage usage;
        double memory_mb = 0.0;

        if (getrusage(RUSAGE_SELF, &usage) == 0)
            memory_mb = usage.ru_maxrss / (1024.0 * 1024.0);

        auto &metrics = result.perf_metrics;

        cout << fixed << setprecision(3);
        cout << "\n--- Phase 8 Benchmark Results ---\n";
        cout << "Model path: " << model_path << '\n';
        cout << "Device: CPU\n";
        cout << "Loading time: " << load_seconds << " seconds\n";
        cout << "Generation time: " << generation_seconds << " seconds\n";
        cout << "Input tokens: " << metrics.get_num_input_tokens() << '\n';
        cout << "Generated tokens: "
             << metrics.get_num_generated_tokens() << '\n';
        cout << "TTFT: " << metrics.get_ttft().mean << " ms\n";
        cout << "Throughput: "
             << metrics.get_throughput().mean << " tokens/second\n";
        cout << "TPOT: " << metrics.get_tpot().mean << " ms\n";
        cout << "Peak process memory: " << memory_mb << " MB\n";
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
