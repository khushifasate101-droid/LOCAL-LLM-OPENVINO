#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "openvino/genai/continuous_batching_pipeline.hpp"

using namespace std;

void print_metrics(const ov::genai::PipelineMetrics& metrics) {
    cout << "\n--- KV Cache Metrics ---\n";

    cout << "Current cache usage: "
         << metrics.cache_usage << "%\n";

    cout << "Maximum cache usage: "
         << metrics.max_cache_usage << "%\n";

    cout << "Average cache usage: "
         << metrics.avg_cache_usage << "%\n";

    double cache_mb =
        static_cast<double>(metrics.cache_size_in_bytes) /
        (1024.0 * 1024.0);

    cout << "Allocated cache size: " << cache_mb << " MB\n";
}

int main() {
    const string model_path = "phase7/converted_model";

    try {
        ov::genai::SchedulerConfig scheduler;
        scheduler.enable_prefix_caching = true;

        cout << "Loading Llama 3.2 3B INT4 model...\n";

        auto start_load = chrono::high_resolution_clock::now();

        ov::genai::ContinuousBatchingPipeline pipe(
            model_path, scheduler, "CPU"
        );

        auto end_load = chrono::high_resolution_clock::now();

        cout << "Model loaded successfully!\n";
        cout << "Loading time: "
             << chrono::duration<double>(
                    end_load - start_load
                ).count()
             << " seconds\n";

        auto config = pipe.get_config();
        config.max_new_tokens = 48;

        string prompt =
            "Explain artificial intelligence, its applications, "
            "advantages, and limitations in simple language.";

        vector<string> prompts = {prompt};
        vector<ov::genai::GenerationConfig> configs = {config};

        for (int i = 1; i <= 2; i++) {
            cout << "\n========== Request " << i << " ==========\n";

            auto start = chrono::high_resolution_clock::now();

            auto results = pipe.generate(prompts, configs);

            auto end = chrono::high_resolution_clock::now();

            cout << "Generation time: "
                 << chrono::duration<double>(end - start).count()
                 << " seconds\n";

            if (!results.empty() &&
                !results[0].m_generation_ids.empty()) {
                cout << "\nModel response:\n";
                cout << results[0].m_generation_ids[0] << "\n";
            }

            print_metrics(pipe.get_metrics());
        }

        cout << "\nKV-cache experiment completed.\n";

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
