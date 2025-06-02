#include "EquilibriumIndex.h"

int countEquilibriumIndexNaive(const vector<int>& vec)
{
   int count = 0;
   auto len = vec.size();

   for (size_t i = 0; i < len; i++) {
      int right_sum = 0;
      for (size_t j = 0; j < i; j++)
      {
         right_sum += vec[j];
      }
      int left_sum = 0;
      for (size_t j = i + 1; j < len; j++)
      {
         left_sum += vec[j];
      }
      if (right_sum == left_sum)
         count++;
   }
   return count;
}

int countEquilibriumIndex(const vector<int>& vec)
{
   auto len = vec.size();
   vector<int> ps(len);

   ps[0] = vec[0];
   for (size_t i = 1; i < len; i++)
      ps[i] = vec[i] + ps[i - 1];

   int count = 0;
   for (size_t i = 0; i < len; i++)
   {
      auto sum_left = i == 0 ? 0 : ps[i - 1];
      auto sum_right = ps[len - 1] - ps[i];
      if (sum_left == sum_right)
         count++;
   }
   return count;
}
