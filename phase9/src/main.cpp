#include <iostream>
#include <string>
#include <chrono>

#include "openvino/genai/llm_pipeline.hpp"

using namespace std;

int main() {
    const string model_path = "phase7/converted_model";

    cout << "====================================\n";
    cout << "   PHASE 9 - KV CACHE INVESTIGATION\n";
    cout << "====================================\n";

    try {
        cout << "\nLoading Llama 3.2 3B INT4 model...\n";

        auto load_start = chrono::high_resolution_clock::now();

        ov::genai::LLMPipeline pipe(model_path, "CPU");

        auto load_end = chrono::high_resolution_clock::now();

        double loading_time =
            chrono::duration<double>(
                load_end - load_start
            ).count();

        cout << "Model loaded successfully!\n";
        cout << "Loading time: " << loading_time << " seconds\n";

        ov::genai::GenerationConfig config =
            pipe.get_generation_config();

        config.max_new_tokens = 80;

        ov::genai::ChatHistory chat_history;
        string prompt;

        while (true) {
            cout << "\nYou: ";

            if (!getline(cin, prompt))
                break;

            if (prompt == "exit")
                break;

            if (prompt.empty())
                continue;

            chat_history.push_back({
                {"role", "user"},
                {"content", prompt}
            });

            auto start = chrono::high_resolution_clock::now();

            auto result = pipe.generate(chat_history, config);

            auto end = chrono::high_resolution_clock::now();

            double generation_time =
                chrono::duration<double>(
                    end - start
                ).count();

            string response = result.texts[0];

            chat_history.push_back({
                {"role", "assistant"},
                {"content", response}
            });

            cout << "\nAssistant: " << response << endl;

            cout << "\nPerformance Details:\n";
            cout << "Generation time: "
                 << generation_time << " seconds\n";
        }

        cout << "\nChat session completed.\n";

    } catch (const exception& e) {
        cerr << "\nError: " << e.what() << endl;
        return 1;
    }

    return 0;
}
