#include "Question02.h"

bool hasPairWithSum1(const vector<int>& vec, int k) {
   const size_t n = vec.size();
   for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
         if (i != j) {
            if (vec[i] + vec[j] == k) {
               return true;
            }
         }
      }
   }
   return false; 
}

bool hasPairWithSum2(const vector<int>& vec, int k) {
   const size_t n = vec.size();
   for (size_t i = 1; i < n; i++) {
      for (size_t j = 0; j < i; j++) {
         if (k == vec[i] + vec[j]) {
            return true;
         }
      }
   }
   return false;
}
