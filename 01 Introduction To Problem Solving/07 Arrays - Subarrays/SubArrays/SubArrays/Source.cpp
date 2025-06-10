#include <iostream>

#include "SubArraysBasics.h"
#include <vector>

using namespace std;

int main()
{
   {
      cout << "--------------------------------\n";
      const vector<int> vec = { 4, 5, 2 };
      PrintAllSubArrays(vec);
   }
   {
      cout << "--------------------------------\n";
      const vector<int> vec = { 3, 5, 7, 2 };
      SumOfAllSubArrays(vec);
   }
   {
      cout << "--------------------------------\n";
      const vector<int> vec = { 3, 5, 7, 2 };
      SumOfAllSubArraysAt2(vec);
   }
   {
      cout << "--------------------------------\n";
      const vector<int> vec = { 3, 5, 7, 2 };
      SumOfAllSubArraysOptimized(vec);
   }
   {
      cout << "--------------------------------\n";
      const vector<int> vec = { 3, -7, 4, 2, -5, 7 };
      std::cout << "Original Array: ";
      for (const auto i : vec)
         std::cout << i << " ";
      std::cout << '\n';

      cout << "Max SubArray Sum: " << MaxSubArraySum(vec) << '\n';
   }

   {
      cout << "--------------------------------\n";
      const vector<int> vec = { 1, 3, 5 };
      std::cout << "Original Array: ";
      for (const auto i : vec)
         std::cout << i << " ";
      std::cout << '\n';

      cout << "Sum of Sum of all SubArrays: " << SumOfSumOfAllSubArrays(vec) << '\n';
   }

   {
      cout << "--------------------------------\n";
      const vector<int> vec = { 1, 3, 5 };
      std::cout << "Original Array: ";
      for (const auto i : vec)
         std::cout << i << " ";
      std::cout << '\n';

      cout << "Sum of Sum of all SubArrays: " << 
         SumOfSumOfAllSubArraysContributionTechnique(vec) << '\n';
   }
}
