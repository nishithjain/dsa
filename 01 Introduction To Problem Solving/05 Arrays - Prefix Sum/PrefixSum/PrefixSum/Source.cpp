#include <iostream>
#include "PrefixSumApproach01.h"
#include "PrefixSumApproach02.h"
#include "EquilibriumIndex.h"
#include "SumOfEvenElements.h"

using namespace std;

int main(void) 
{
   {
      cout << "------------------- Naive Approach -------------------\n";
      vector vec = { -3, 6, 2, 7, 5, 2, 8, -9, 3, 1 };
      vector<pair<size_t, size_t>> queries = {
         {4, 8},
         {6, 9},
         {0, 4},
         {7, 7}
      };

      auto ans = prefixSumNaive(vec, queries);
      for (size_t i = 0; i < ans.size(); i++) {
         const auto& [l, r] = queries[i];
         cout << "For query [" << l << ", " << r
            << "]: " << ans[i] << endl;
      }
   }
   {
      cout << "------------------- PrefixSum Array ------------------\n";
      vector vec = { -3, 6, 2, 7, 5, 2, 8, -9, 3, 1 };
      vector<pair<size_t, size_t>> queries = {
         {4, 8},
         {6, 9},
         {0, 4},
         {7, 7}
      };

      auto ans = prefixSumSaperatePSArray(vec, queries);
      for (size_t i = 0; i < ans.size(); i++) {
         const auto& [l, r] = queries[i];
         cout << "For query [" << l << ", " << r
            << "]: " << ans[i] << endl;
      }
   }
   {
      cout << "--------------------- In-place ----------------------\n";
      vector vec = { -3, 6, 2, 7, 5, 2, 8, -9, 3, 1 };
      vector<pair<size_t, size_t>> queries = {
         {4, 8},
         {6, 9},
         {0, 4},
         {7, 7}
      };
      cout << "Original Array: ";
      for (size_t i = 0; i < vec.size(); i++) {
         cout << vec[i] << " ";
      }
      cout << endl;
      auto ans = prefixSumInplace(vec, queries);
      for (size_t i = 0; i < ans.size(); i++) {
         const auto& [l, r] = queries[i];
         cout << "For query [" << l << ", " << r
            << "]: " << ans[i] << endl;
      }
      cout << "Original Array modified as PS Array: ";
      for (size_t i = 0; i < vec.size(); i++) {
         cout << vec[i] << " ";
      }
      cout << endl;
   }
   {
      cout << "--------------------- Restore ----------------------\n";
      vector vec = { -3, 6, 2, 7, 5, 2, 8, -9, 3, 1 };
      vector<pair<size_t, size_t>> queries = {
         {4, 8},
         {6, 9},
         {0, 4},
         {7, 7}
      };
      cout << "Original Array: ";
      for (size_t i = 0; i < vec.size(); i++) {
         cout << vec[i] << " ";
      }
      cout << endl;
      auto ans = prefixSumInplaceRestore(vec, queries);
      for (size_t i = 0; i < ans.size(); i++) {
         const auto& [l, r] = queries[i];
         cout << "For query [" << l << ", " << r
            << "]: " << ans[i] << endl;
      }
      cout << "Restored Array: ";
      for (size_t i = 0; i < vec.size(); i++) {
         cout << vec[i] << " ";
      }
      cout << endl;
   }
   cout << "------------------ Equilibrium Index -------------------\n";
   {
      vector<int> vec = { 0, -3, 5, -4, -2, 3, 1, 0, -1, 1 };
      cout << "Original Array: ";
      for (size_t i = 0; i < vec.size(); i++) {
         cout << vec[i] << " ";
      }
      cout << endl;

      auto count = countEquilibriumIndexNaive(vec);
      cout << "Number of Equilibrium Indices (Naive):" << count << endl;
   }
   {
      vector<int> vec = { 0, -3, 5, -4, -2, 3, 1, 0, -1, 1 };
      cout << "Original Array: ";
      for (size_t i = 0; i < vec.size(); i++) {
         cout << vec[i] << " ";
      }
      cout << endl;

      auto count = countEquilibriumIndex(vec);
      cout << "Number of Equilibrium Indices (PrefixSum):" << count << endl;
   }

   {
      cout << "---------- Sum of Even Elements in a Range ----------\n";
      vector vec = { 2, 3, 2, 4, 2, 9, 8, 7, 7, 6 };
      vector<pair<size_t, size_t>> queries = {
         {0, 5},
         {5, 5},
         {3, 7},
         {7, 7}
      };

      auto ans = SumOfEvenElements(vec, queries);
      for (size_t i = 0; i < ans.size(); i++) {
         const auto& [l, r] = queries[i];
         cout << "For query [" << l << ", " << r
            << "]: " << ans[i] << endl;
      }
   }
}



