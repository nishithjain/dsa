#include <vector>
#include "02FindTriplets.h"

/*
* Time Complexity: O(n*n*n) → very slow for large strings
*/
int CountTripletsBruteForceApproach(const std::string& s)
{
   int count = 0;
   const auto n = s.length();
   for (size_t i = 0; i < n; i++)
      for (size_t j = i + 1; j < n; j++)
         for (size_t k = j + 1; k < n; k++)
            if (s[i] == 'a' && s[j] == 'x' && s[k] == 'g')
               count++;
   return count;
}

/*
 *Time Complexity		O(n)
 *Space Complexity	O(n) (2 arrays)
 */
int CountTripletsPrefixSuffixSum(const std::string& s)
{
   int count = 0;
   const auto n = s.length();
   std::vector ps(n, 0);
   std::vector ss(n, 0);
   ps[0] = s[0] == 'a' ? 1 : 0;
   ss[n - 1] = s[n - 1] == 'g' ? 1 : 0;

   for (size_t i = 1, j = n - 2; i < n; i++, j--)
   {
      ps[i] = s[i] == 'a' ? ps[i - 1] + 1 : ps[i - 1];
      ss[j] = s[j] == 'g' ? ss[j + 1] + 1 : ss[j + 1];
   }

   for (size_t i = 0; i < n; i++)
   {
      if (s[i] == 'x')
         count += ps[i] * ss[i];
   }
   return count;
}


int CountTriplets(const std::string& s) {
   int count_g = 0;
   int count_xg = 0;
   int answer = 0;
   auto const n = s.length();

   for (auto i = n - 1; i--> 0;) {
      if (s[i] == 'g') {
         count_g++;
      }
      else if (s[i] == 'x') {
         count_xg += count_g;
      }
      else if (s[i] == 'a') {
         answer += count_xg;
      }
   }
   return answer;
}