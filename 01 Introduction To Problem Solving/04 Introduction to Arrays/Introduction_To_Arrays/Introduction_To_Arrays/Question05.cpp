#include "Question05.h"
#include "Question04.h"

vector<int> rotateK_TimesExtraSpace(vector<int>& vec, size_t k)
{
   size_t n = vec.size();
   vector<int> newVec(n);
   for (size_t i = 0; i < k; i++) {
      newVec[i] = vec[n - k + i];
   }
   for (size_t i = k; i < n; i++) {
      newVec[i] = vec[i - k];
   }
   return newVec;
}

void rotateK_Times(vector<int>& vec, size_t k)
{
   if (k == 0)
      return;
   size_t n = vec.size();
   if (k >= n)
      k = k % n;

   reverseSubArray(vec, 0, n - 1);
   reverseSubArray(vec, 0, k - 1);
   reverseSubArray(vec, k, n - 1);
}
