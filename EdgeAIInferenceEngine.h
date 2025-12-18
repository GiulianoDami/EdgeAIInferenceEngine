
#ifndef EDGE_AI_INFERENCE_ENGINE_H
#define EDGE_AI_INFERENCE_ENGINE_H

#include <vector>
#include <string>

class EdgeAIEngine {
public:
    /**
     * @brief Load quantized 8-bit ONNX model
     * @param model_path Path to quantized model file
     */
    explicit EdgeAIEngine(const std::string& model_path);

    /**
     * @brief Run inference on tokenized input
     * @param input Tokenized input sequence (uint8_t)
     * @return Output tokens and probabilities (uint8_t)
     */
    std::vector<uint8_t> run(const std::vector<uint8_t>& input);

private:
    std::vector<uint8_t> model_data_;
    size_t input_size_;
    size_t output_size_;
};

#endif // EDGE_AI_INFERENCE_ENGINE_H
