#include "CountFactors.h"

int CountFactorsNaiveApproach(const long long int n) {
   int count = 0;
   for (long long int i = 1; i <= n; i++) {
      if (n % i == 0) {
         count++;
      }
   }
   return count;
}

int CountFactorsOptimizedApproach(const long long int n) {
   int count = 0;
   for (long long int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
         if (i == n / i) {
            count += 1;
         }
         else {
            count += 2;
         }
      }
   }
   return count;
}