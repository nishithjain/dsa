#pragma once
#include <vector>

int MaxSubArraySumOfLengthKBruteForce(const std::vector<int>& arr, int k);
int MaxSubArraySumOfLengthKPrefixSum(const std::vector<int>& arr, int k);
int MaxSubArraySumOfLengthKSlidingWindow(const std::vector<int>& arr, int k);

int MinSwapToBringBElementsTogether(const std::vector<int>& arr, int b);