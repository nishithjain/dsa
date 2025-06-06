#include "04MinMaxSubarray.h"
#include <utility>

/*
 * Time Complexity  = O(n*n*n)
 * Space Complexity	= O(1)
 */
int MinMaxSubArrayBruteForce(const std::vector<int>& vec)
{
   const auto len = vec.size();
   const auto min_val = *std::ranges::min_element(vec);
   const auto max_val = *std::ranges::max_element(vec);
   // If all elements are the same, the smallest sub-array is the entire array
   if (min_val == max_val)
   {
      return 1;
   }
   int shortest_sub_array_length = static_cast<int>(len);
   // Iterate through all possible starting points of sub-arrays
   for (int i = 0; std::cmp_less(i, len); ++i)
   {
      // Iterate through all possible ending points of sub-arrays
      for (int j = i; std::cmp_less(j, len); ++j)
      {
         // Check if the current sub-array contains the minimum and maximum values
         const bool contains_min = std::find(vec.begin() + i,
                                       vec.begin() + j + 1,
                                       min_val) != vec.begin() + j + 1;
         const bool contains_max = std::find(vec.begin() + i,
                                       vec.begin() + j + 1,
                                       max_val) != vec.begin() + j + 1;
         // If both values are found, update the shortest sub-array length and break
         if (contains_min && contains_max)
         {
            shortest_sub_array_length = std::min(shortest_sub_array_length, 
               j - i + 1);
            break;
         }
      }
   }
   return shortest_sub_array_length;
}

/*
While traversing the array from left to right, keep track of:
  Last seen index of min_val
  Last seen index of max_val
Whenever you find a new min_val or max_val, check if you've seen
the other one already and compute the sub-array length.
Time Complexity	= O(n)
Space Complexity= O(1)
*/
int MinMaxSubArray(const std::vector<int>& vec)
{
   const auto len = vec.size();
   const auto min_val = *std::ranges::min_element(vec);
   const auto max_val = *std::ranges::max_element(vec);
   if (min_val == max_val)
      return 1;

   int shortest_sub_array_length = static_cast<int>(len);
   int min_index = -1;
   int max_index = -1;

   for (int i = 0; i < len; i++)
   {
      if (vec[i] == min_val)
      {
         if (max_index != -1)
         {
            shortest_sub_array_length = std::min(shortest_sub_array_length,
               i - max_index + 1);
         }
         min_index = i;
      }
      else if (vec[i]==max_val)
      {
         if (min_index != -1)
         {
            shortest_sub_array_length = std::min(shortest_sub_array_length,
               i - min_index + 1);
         }
         max_index = i;
      }
   }
   return shortest_sub_array_length;
}