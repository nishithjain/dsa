#include "PrefixSumApproach02.h"

// 01 Separate Array
vector<int> prefixSumSaperatePSArray(const vector<int>& vec, 
   const vector<pair<size_t, size_t>> queries)
{
   size_t len = vec.size();
   // First create prefix sum.
   vector<int> ps(len); // Allocate memory
   ps[0] = vec[0];
   for (size_t i = 1; i < len; i++) {
      ps[i] = vec[i] + ps[i - 1];
   }

   vector<int> answer;
   for (const auto& [l, r] : queries) {
      if (l == 0)
         answer.push_back(ps[r]);
      else
         // sum[4, 8] = sum[0, 8] - sum[0, 3]
         // sum[4, 8] = ps[8] - ps[3] = ps[r] - ps[l -1]
         answer.push_back(ps[r] - ps[l - 1]);
   }

   return answer;
}

// 02 In-place
vector<int> prefixSumInplace(vector<int>& vec, 
   const vector<pair<size_t, size_t>> queries)
{
   size_t len = vec.size();
   for (size_t i = 1; i < len; i++) {
      vec[i] = vec[i] + vec[i - 1];
   }

   vector<int> answer;
   for (const auto& [l, r] : queries) {
      if (l == 0)
         answer.push_back(vec[r]);
      else
         answer.push_back(vec[r] - vec[l - 1]);
   }

   return answer;
}

// 03 Retrieve the original array (In place)
vector<int> prefixSumInplaceRestore(vector<int>& vec, 
   const vector<pair<size_t, size_t>> queries)
{
   size_t len = vec.size();

   // In-place Prefix Sum Calculation
   for (size_t i = 1; i < len; i++) {
      vec[i] = vec[i] + vec[i - 1];
   }
   
   // Answer the queries
   vector<int> answer;
   for (const auto& [l, r] : queries) {
      if (l == 0)
         answer.push_back(vec[r]);
      else
         answer.push_back(vec[r] - vec[l - 1]);
   }

   // Restore the Original Array
   for (size_t i = len -1 ; i >= 1 ; i--) {
      vec[i] = vec[i] - vec[i - 1];
   }
   return answer;
}
