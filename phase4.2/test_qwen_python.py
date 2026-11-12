import openvino_genai as ov_genai

model_path = "phase4.2/models_clean"

print("Loading Qwen model on CPU...")
pipe = ov_genai.LLMPipeline(model_path, "CPU")

prompt = "What is artificial intelligence? Answer in two short sentences."

config = ov_genai.GenerationConfig()
config.max_new_tokens = 60
config.do_sample = False
config.repetition_penalty = 1.0

print("\nGenerating response...\n")
result = pipe.generate(prompt, config)

print("Qwen Python response:\n")
print(result)
