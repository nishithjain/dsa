#include "Prime.h"

bool IsPrime(const long long int n) {
   if (n <= 1) return false;
   int count = 0;
   for (long long int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
         if (n / i == i) {
            count += 1;
         }
         else {
            count += 2;
         }
         if (count > 2) {
            return false;
         }
      }
   }
   return count == 2;
}

bool IsPrimeOptimized(const long long int n) {
   if (n <= 1) return false;
   if (n <= 3) return true;
   if (n % 2 == 0 || n % 3 == 0) return false;
   for (long long int i = 5; i * i <= n; i += 6) {
      if (n % i == 0 || n % (i + 2) == 0)
         return false;
   }
   return true;
}