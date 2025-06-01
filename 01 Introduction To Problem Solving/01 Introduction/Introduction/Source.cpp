#include <iostream>
#include <chrono>

using namespace std;

int countFactorsNaiveApproach(long long int n) {
   int count = 0;
   for (long long int i = 1; i <= n; i++) {
      if (n % i == 0) {
         count++;
      }
   }
   return count;
}

int countFactorsOptimizedApproach(long long int n) {
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

bool isPrime(long long int n) {
   if (n <= 1) return false;
   int count = 0;
   for (long long int i = 2; i * i <= n; i++) {
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

bool isPrimeOptimized(long long int n) {
   if (n <= 1) return false;
   if (n <= 3) return true;
   if (n % 2 == 0 || n % 3 == 0) return false;
   for (long long int i = 5; i * i <= n; i += 6) {
      if (n % i == 0 || n % (i + 2) == 0) 
         return false;
   }
   return true;
}

// Square Root Calculation Without Library 
// of a Perfect Square Number
long long int squareRootOfPerfectSquare(long long int n) {
   for (long long int i = 1; i * i <= n; i++) {
      if (i * i == n) {
         return i;
      }
   }
}

// Floor of Square Root (for any positive integer)

long long int floorOfSqrt(long long int n) {
   int potential_ans = 0;
   for (long long int i = 1; i <= n; i++) {
      if (i * i <= n) {
         potential_ans = i;
      }
      else 
         break;
   }
   return potential_ans;
}

int main()
{
   long long number_to_test = 10'000'000'000LL;
   auto start_time = chrono::high_resolution_clock::now();
   int factor_count = countFactorsNaiveApproach(number_to_test);
   auto end_time = chrono::high_resolution_clock::now();
   auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);

   cout << "Time taken to count factors of " << number_to_test <<
      " using naive approach: " << duration.count() << " seconds\n";
   cout << "Number of factors of " << number_to_test <<
      " is: " << factor_count << "\n";

   start_time = chrono::high_resolution_clock::now();
   factor_count = countFactorsOptimizedApproach(number_to_test);
   end_time = chrono::high_resolution_clock::now();
   duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);
   cout << "Time taken to count factors of " << number_to_test <<
      " using optimized approach: " << duration.count() << " seconds\n";
   cout << "Number of factors of " << number_to_test <<
      " is: " << factor_count << "\n";

   // Testing prime checking functions
   long long prime_test_number = 29;
   cout << "Is " << prime_test_number << " prime? (Naive): "
      << (isPrime(prime_test_number) ? "Yes" : "No") << "\n";
}
/*
Time taken to count factors of 1000000002 using naive approach: 3 seconds
Number of factors of 1000000002 is: 32
Time taken to count factors of 1000000002 using optimized approach: 0 seconds
Number of factors of 1000000002 is: 32
*/