#include <iostream>
#include <string>
#include <vector>

#include "01Count_Pairs.h"
#include "02FindTriplets.h"
#include "03Leaders.h"
#include "04MinMaxSubarray.h"

using namespace std;

int main() {
   {
      const string s = "baagdcag";
      const auto ans = count_pairs_naive(s);
      cout << "Number of pairs (a, g) Naive: " << ans << "\n";
   }
   {
      const string s = "baagdcag";
      const auto ans = count_pairs_naive_optimized(s);
      cout << "Number of pairs (a, g) Naive Optimized: " << ans << "\n";
   }
   {
      const string s = "baagdcag";
      const auto ans = count_pairs_optimized_right_to_left(s);
      cout << "Number of pairs (a, g) Optimized Right to Left: " << ans << "\n";
   }
   {
      const string s = "baagdcag";
      const auto ans = count_pairs_optimized_left_to_right(s);
      cout << "Number of pairs (a, g) Optimized Left to Right: " << ans << "\n";
   }
   {
      const string s = "baagdcag";
      const auto ans = count_pairs_prefix_sum(s);
      cout << "Number of pairs (a, g) Prefix Sum: " << ans << "\n";
   }
   {
      const string s = "axaaxgxgaax";
      const auto ans = CountTripletsBruteForceApproach(s);
      cout << "Number of Triplets (a, x, g) Naive: " << ans << "\n";
   }
   {
      const string s = "axaaxgxgaax";
      const auto ans = CountTripletsPrefixSuffixSum(s);
      cout <<  "Number of Triplets (a, x, g) PrefixSuffix: " << ans << "\n";
   }

   {
      const string s = "axaaxgxgaax";
      const auto ans = CountTriplets(s);
      cout << "Number of Triplets (a, x, g): " << ans << "\n";
   }
   {
      const vector vec = { 15, -1, 7, 2, 5, 4, 2, 3 };
      const auto ans = CountLeadersNaive(vec);
      cout << "Number of Leaders Naive: " << ans << "\n";
   }
   {
      const vector vec = { 15, -1, 7, 2, 5, 4, 2, 3 };
      const auto ans = CountLeadersOptimized(vec);
      cout << "Number of Leaders Optimized: " << ans << "\n";
   }
   {
      const vector vec = { 1, 3, 6, 1, 3, 1, 6, 4, 6 };
      const auto ans = MinMaxSubArrayBruteForce(vec);
      cout << "Shortest Sub-array with Both Min and Max BruteForce:" << ans << "\n";
   }
   {
      const vector vec = { 1, 3, 6, 1, 3, 1, 6, 4, 6 };
      const auto ans = MinMaxSubArray(vec);
      cout << "Shortest Sub-array with Both Min and Max:" << ans << "\n";
   }
}
