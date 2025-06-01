#include "Question01.h"

size_t Approach1(const vector<int>& vec) {
   int maxElement = INT_MIN;
   for (size_t i = 0; i < vec.size(); i++) {
      if (vec[i] > maxElement)
         maxElement = vec[i];
   }
   size_t count = 0;
   for (size_t i = 0; i < vec.size(); i++) {
      if (vec[i] == maxElement)
         count++;
   }

   return vec.size() - count;
}

size_t Approach2(const vector<int>& vec) {
   size_t count = 0;
   int maxElement = INT_MIN;

   for (size_t i = 0; i < vec.size(); i++) {
      if (maxElement < vec[i]) {
         maxElement = vec[i];
         count = 1;
      }
      else if (maxElement == vec[i]) {
         count++;
      }
   }
   return vec.size() - count;
}


