#include "PrefixSumApproach01.h"

vector<int> prefixSumNaive(const vector<int>& vec,
   const vector<pair<size_t, size_t>> queries)
{
   vector<int> answer;
   for (const auto& [l, r] : queries) {
      int sum = 0;
      for (auto i = l; i <= r; i++) {
         sum += vec[i];
      }
      answer.push_back(sum);
   }
   return answer;
}
