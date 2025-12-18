
#include <EdgeAIInferenceEngine.h>
#include <iostream>
#include <vector>

int main() {
    try {
        // Load quantized model (8-bit ONNX)
        EdgeAIEngine engine("tiny_llm_quantized.onnx");
        
        // Input: tokenized sentence (e.g., [101, 213, 456])
        std::vector<uint8_t> input = {101, 213, 456};
        
        // Run inference (1ms on Cortex-M7)
        auto output = engine.run(input);
        
        // Process output (e.g., top-5 tokens)
        for (int i = 0; i < 5; ++i) {
            std::cout << "Token: " << static_cast<int>(output[i]) 
                      << " | Prob: " << static_cast<int>(output[i + 5]) << "\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}