#include "SlidingWindow.h"
#include <iostream>

using namespace std;

int main()
{
   {
      const vector<int> arr = { -3, 4, 5, 7, 2, 1, 4, 3, 9 };
      constexpr int k = 4;
      const auto result = MaxSubArraySumOfLengthKBruteForce(arr, k);
      cout << "Maximum Sub-Array Sum of length " << k <<
         " :" << result << '\n';
   }

   {
      const vector<int> arr = { -3, 4, 5, 7, 2, 1, 4, 3, 9 };
      constexpr int k = 4;
      const auto result = MaxSubArraySumOfLengthKPrefixSum(arr, k);
      cout << "Maximum Sub-Array Sum of length " << k <<" :PrefixSum"  <<
         ":" << result << '\n';
   }

   {
      const vector<int> arr = { -3, 4, 5, 7, 2, 1, 4, 3, 9 };
      constexpr int k = 4;
      const auto result = MaxSubArraySumOfLengthKSlidingWindow(arr, k);
      cout << "Maximum Sub-Array Sum of length " << k << " :Sliding Window" <<
         ":" << result << '\n';
   }

   {
      const vector<int> arr = { -3, 4, 5, 7, 2, 1, 4, 3, 9 };
      constexpr int b = 3;
      const auto result = MinSwapToBringBElementsTogether(arr, b);
      cout << "MINIMUM number of swaps required to bring all" <<
         " the elements <= " << b << " together: " << result;
   }
}