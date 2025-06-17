#include "SlidingWindow.h"
/*
 Array:        0     1     2     3     4     5     6     7     8
            +-----+-----+-----+-----+-----+-----+-----+-----+-----+
arr[i]:     | -3  |  4  |  5  |  7  |  2  |  1  |  4  |  3  |  9  |
            +-----+-----+-----+-----+-----+-----+-----+-----+-----+
Index:                     ^                 ^
                           l                 r               n = 9
Window:                 [--------->]
Sub-array:              [ 5, 7, 2, 1 ]   (indices 2 to 5)
Sum of the sub-array:   5 + 7 + 2 + 1 = 15
 */
int MaxSubArraySumOfLengthKBruteForce(const std::vector<int>& arr, int k)
{
   int l = 0;
   int r = k - 1;
   const int n = static_cast<int>(arr.size());
   int max_sub_array_sum = INT_MIN;

   // There will be N-K+1 sub-arrays will be there!
   while (r < n)
   {
      // [l, r] a valid sub array k
      int sum = 0;
      for (int i = l; i <= r; i++)
      {
         sum += arr[i];
      }
      max_sub_array_sum = std::max(sum, max_sub_array_sum);

      // Move to the next sub-array, increment l and r
      l++;
      r++;
   }
   return max_sub_array_sum;
}

int MaxSubArraySumOfLengthKPrefixSum(const std::vector<int>& arr, int k)
{
   const int n = static_cast<int>(arr.size());
   std::vector<int> prefix_sum(n);
   prefix_sum[0] = arr[0];
   for (int i = 1; i < n; i++)
   {
      prefix_sum[i] = arr[i] + prefix_sum[i - 1];
   }

   int l = 0;
   int r = k - 1;
   int max_sub_array_sum = INT_MIN;
   while (r < n)
   {
      int sum = 0;
      if (l == 0)
      {
         sum = prefix_sum[l];
      }
      else
      {
         sum = prefix_sum[r] - prefix_sum[l - 1];
      }
      max_sub_array_sum = std::max(sum, max_sub_array_sum);
      l++;
      r++;
   }
   return max_sub_array_sum;
}

int MaxSubArraySumOfLengthKSlidingWindow(const std::vector<int>& arr, int k)
{
   const int n = static_cast<int>(arr.size());
   int sum = 0;

   // Calculate the first window sum
   for (int i = 0; i < k; i++)
      sum += arr[i];

   int max_sub_array_sum = sum;

   int l = 1; // Start from 2nd sub-array
   int r = k; // The 2nd sub-array ends at k
   while (r < n)
   {
      // One element leaves the sub-array which is arr[l-1]
      // One element enters the sub-array which is arr[r]
      sum = sum - arr[l - 1] + arr[r];
      max_sub_array_sum = std::max(max_sub_array_sum, sum);
      l++;
      r++;
   }
   return max_sub_array_sum;
}

/*
 Given an array A and int B, find the MINIMUM number of
 swaps required to bring all the elements <=B together.
 */
int MinSwapToBringBElementsTogether(const std::vector<int>& arr, int b)
{
   const int n = static_cast<int>(arr.size());
   int k = 0;
   // Find number of elements <= B
   for (int i = 0; i < n; i++)
   {
      if (arr[i] <= b)
         k++;
   }
   // k is the window size.

   // Find number of elements <= b in the first window
   int green_elements = 0;
   for (int i = 0; i < k; i++)
   {
      if (arr[i] <= b)
         green_elements++;
   }
   // If there are k elements <= b, then minimum swaps required
   // for the first window is k - green_elements
   int min_swaps = k - green_elements;
   int l = 1;
   int r = k;
   while (r < n)
   {
      if (arr[l - 1] <= b) 
         green_elements--; // One element which is <= b is leaving the window
      if (arr[r] <= b)
         green_elements++; // One element which is <= b is entering the window

      min_swaps = std::min(min_swaps, k - green_elements);

      l++;
      r++;
   }
   return min_swaps;
}
