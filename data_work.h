#pragma once // or use include guards

struct Dataset {
    torch::Tensor x;
    torch::Tensor y;


    // Method to get a batch for a given epoch and batch size
    std::pair<torch::Tensor, torch::Tensor> getBatch(size_t epoch, size_t batchSize) const {
        // Calculate the starting index of the batch
        size_t startIndex = epoch * batchSize;

        // Extract a batch from the dataset
        torch::Tensor batchX = x.index({torch::indexing::Slice(startIndex, startIndex + batchSize)});
        torch::Tensor batchY = y.index({torch::indexing::Slice(startIndex, startIndex + batchSize)});

        return {batchX, batchY};
    }
};


Dataset prepData(std::string path, float prop);