#include "SumOfEvenElements.h"

vector<int> SumOfEvenElements(const vector<int>& vec,
   const vector<pair<size_t, size_t>> queries)
{
   auto len = vec.size();
   vector<int> ps(len);

   ps[0] = vec[0] % 2 == 0 ? vec[0] : 0;
   for (size_t i = 1; i < len; i++) {
      ps[i] = ps[i - 1] + (vec[i] % 2 == 0 ? vec[i] : 0);
   }
   vector<int> answer;
   for (const auto& [l, r] : queries) {
      if (l == 0)
         answer.push_back(ps[r]);
      else
         answer.push_back(ps[r] - ps[l - 1]);
   }
   return answer;
}
