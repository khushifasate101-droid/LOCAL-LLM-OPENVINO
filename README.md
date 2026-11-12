# Local LLM Inference on OpenVINO

## Project Overview
This project demonstrates local Large Language Model (LLM) inference using **OpenVINO GenAI and C++**. It focuses on model conversion, quantization, performance benchmarking, multi-turn conversations, and KV-cache investigation.

## Objectives
- Run LLMs locally using OpenVINO GenAI.
- Develop inference applications using C++.
- Convert Hugging Face models into OpenVINO IR.
- Compare FP16, INT8, and INT4 quantization.
- Measure inference performance and memory usage.
- Explore ChatHistory and KV-cache concepts.

## Technologies
- C++17
- OpenVINO GenAI 2026.4.1
- OpenVINO Runtime
- Optimum Intel
- NNCF
- Python
- CMake
- Hugging Face

## Hardware
- MacBook Air 2022
- Apple M2
- 16 GB Unified Memory
- macOS Tahoe
- OpenVINO CPU device

## Completed Phases

| Phase | Description |
|---|---|
| 1 | Environment Setup |
| 4 | Initial Model Testing |
| 4.3 | TinyLlama INT4 Testing |
| 6 | Pre-converted Llama Model |
| 7 | Self-conversion of Llama Model |
| 8 | Quantization and Benchmarking |
| 9 | Multi-turn Conversation and KV-cache Investigation |

## Quantization Results

| Metric | FP16 | INT8 | INT4 |
|---|---:|---:|---:|
| Loading Time (s) | 10.258 | 101.579 | 21.170 |
| Generation Time (s) | 6.756 | 12.069 | 10.736 |
| Throughput (tokens/s) | 6.555 | 7.026 | 6.905 |

## Phase 9 Summary
- Developed a C++ chat application.
- Implemented multi-turn conversation using ChatHistory.
- Verified conversational context retention.
- Investigated Continuous Batching and KV-cache metrics.
- Direct KV-cache metrics could not be measured because of a PagedAttention initialization error in the available environment.

## Model Download
Large model weights are excluded from this repository.

Download the original Llama 3.2 3B Instruct model from Hugging Face:

https://huggingface.co/meta-llama/Llama-3.2-3B-Instruct

Convert it to OpenVINO INT4 using Optimum Intel:

```bash
optimum-cli export openvino \
  --model phase7/original_model \
  --task text-generation-with-past \
  --weight-format int4 \
  phase7/converted_model
```

## Build and Run

```bash
cmake -S phase9 -B phase9/build
cmake --build phase9/build -j2
./phase9/build/phase9_chat
```

Ensure OpenVINO GenAI is installed and the converted model is available.

## Conclusion
This project demonstrates local LLM inference using OpenVINO GenAI and C++. It covers model conversion, quantization, CPU performance benchmarking, multi-turn conversation, and KV-cache investigation.
