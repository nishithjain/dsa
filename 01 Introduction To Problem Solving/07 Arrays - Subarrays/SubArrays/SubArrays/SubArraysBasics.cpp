#include "SubArraysBasics.h"

#include <algorithm>
#include <iostream>

/*
 * There are O(N*N) sub-arrays
 * Each sub-array takes O(N) to print on average
 * Hence, total = O(N*N*N)
 */
void PrintAllSubArrays(const std::vector<int>& vec)
{
   const auto len = vec.size();
   std::cout << "Original Array: ";
   for (const auto i : vec)
      std::cout << i << " ";
   std::cout << '\n';
   std::cout << "Printing all SubArrays:\n";

   for (size_t l = 0; l < len; l++)
   {
      for (auto r = l; r < len; r++)
      {
         for (auto i = l; i <= r; i++)
            std::cout << vec[i] << " ";
         std::cout << '\n';
      }
   }
}

void SumOfAllSubArrays(const std::vector<int>& vec)
{
   const auto len = vec.size();
   std::vector<int> ps(len);

   ps[0] = vec[0];
   for (size_t i = 1; i < len; i++)
      ps[i] = vec[i] + ps[i - 1];

   std::cout << "Original Array: ";
   for (const auto i : vec)
      std::cout << i << " ";
   std::cout << '\n';

   std::cout << "Sum Of All Sub Arrays:\n";
   for (size_t l = 0; l < len; l++)
   {
      for (auto r = l; r < len; r++)
      {
         const auto sum = ps[r] - (l > 0 ? ps[l - 1] : 0);
         std::cout << "Sum[" << l << ", " <<
            r << "]: " << sum << '\n';
      }
   }
}

void SumOfAllSubArraysAt2(const std::vector<int>& vec)
{
   std::cout << "Original Array: ";
   for (const auto i : vec)
      std::cout << i << " ";
   std::cout << '\n';

   const auto len = vec.size();
   std::cout << "Sum Of All Sub Arrays Starting At Index 2:\n";

   int sum = 0;
   for (size_t r = 2; r < len; r++)
   {
      sum += vec[r];
      std::cout << "Sum[2, " << r << "]: "
         << sum << '\n';
   }
}

void SumOfAllSubArraysOptimized(const std::vector<int>& vec)
{
   std::cout << "Original Array: ";
   for (const auto i : vec)
      std::cout << i << " ";
   std::cout << '\n';

   const auto len = vec.size();
   std::cout << "Sum Of All Sub Arrays Optimized:\n";

   for (size_t l = 0; l < len; l++)
   {
      int sum = 0;
      for (auto r = l; r < len; r++)
      {
         sum += vec[r];
         std::cout << "Sum[" << l << ", " << r << "]: "
            << sum << '\n';
      }
   }
}

int MaxSubArraySum(const std::vector<int>& vec)
{
   const auto len = vec.size();
   int max_sum = INT_MIN;

   for (size_t l = 0; l < len; l++)
   {
      int sum = 0;
      for (auto r = l; r < len; r++)
      {
         sum += vec[r];
         max_sum = std::max(max_sum, sum);
      }
   }
   return max_sum;
}

int SumOfSumOfAllSubArrays(const std::vector<int>& vec)
{
   const auto len = vec.size();
   int ans = 0;

   for (size_t l = 0; l < len; l++)
   {
      int sum = 0;
      for (auto r = l; r < len; r++)
      {
         sum += vec[r];
         ans += sum;
      }
   }
   return ans;
}
/*
   Total Number of Sub-arrays that include A[i]
   To form a sub-array that includes A[i], you need to choose two things:
      A starting point that is at or before index i.
         0.... i-1 -> number of elements = r - l + 1 = i-1 + 0 + 1 = i + 1
         There are (i+1) choices for this.
      An ending point that is at or after i.
         i.... N-1 -> number of elements = r - l + 1 = N-1 - i + 1 = N - i
         There are (N-i) choices for this.
 */
int SumOfSumOfAllSubArraysContributionTechnique(const std::vector<int>& vec)
{
   const size_t len = vec.size();
   int total_sum = 0;
   for (size_t i = 0; i < len; ++i)
   {
      const int contribution = vec[i] * static_cast<int>(i + 1)
         * static_cast<int>(len - i);
      total_sum += contribution;
   }
   return total_sum;
}

