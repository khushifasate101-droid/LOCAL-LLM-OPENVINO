import openvino_genai

model_path = "phase4.3/models/tinyllama_int4"

pipe = openvino_genai.LLMPipeline(model_path, "CPU")

prompt = "What is artificial intelligence? Answer in two short sentences."

config = openvino_genai.GenerationConfig()
config.max_new_tokens = 80

result = pipe.generate(prompt, config)

print("\nGenerated response:\n")
print(result)
