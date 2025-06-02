#pragma once
#include <vector>
using namespace std;

// 01 Separate Array
// 02 In-place
// 03 Retrieve the original array (In-place)

vector<int> prefixSumSaperatePSArray(const vector<int>& vec,
   const vector<pair<size_t, size_t>> queries);

vector<int> prefixSumInplace(vector<int>& vec,
   const vector<pair<size_t, size_t>> queries);

vector<int> prefixSumInplaceRestore(vector<int>& vec,
   const vector<pair<size_t, size_t>> queries);