#include "03Leaders.h"

int CountLeadersNaive(const std::vector<int>& vec)
{
   int count = 0;
   const auto len = vec.size();
   for (size_t i = 0; i < len; i++)
   {
      auto is_leader = true;
      for (auto j = i + 1; j < len; j++)
      {
         if (vec[j] >= vec[i]) {
            is_leader = false;
            break;
         }
      }
      if (is_leader)
         count++;
   }
   return count;
}

int CountLeadersOptimized(const std::vector<int>& vec)
{
   int count = 0;
   const auto len = vec.size();
   int mc = INT_MIN;
   for (auto i = len -1; i-->0;)
   {
      if (vec[i] > mc)
      {
         count++;
         mc = vec[i];
      }
   }
   return count;
}
