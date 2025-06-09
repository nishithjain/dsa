#include "SquareRoot.h"

// Square Root Calculation Without Library 
// of a Perfect Square Number
long long int SquareRootOfPerfectSquare(const long long int n) {
   for (long long int i = 1; i * i <= n; i++) {
      if (i * i == n) {
         return i;
      }
   }
   return - 1;
}

// Floor of Square Root (for any positive integer)
long long int FloorOfSqrt(const long long int n) {
   long long int potential_ans = 0;
   for (long long int i = 1; i <= n; i++) {
      if (i * i <= n) {
         potential_ans = i;
      }
      else
         break;
   }
   return potential_ans;
}