#include "Question04.h"

void reverseSubArray(vector<int>& vec, size_t start, size_t end) {
   while (start < end) {
      std::swap(vec[start], vec[end]);
      start++;
      end--;
   }
}