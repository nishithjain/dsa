#include "Question03.h"

void reverseArray(vector<int>& vec) {
   size_t i = 0;
   size_t j = vec.size() - 1;

   while (i < j) {
      std::swap(vec[i], vec[j]);
      i++;
      j--;
   }
}
