#include <iostream>
#include <chrono>

#include "CountFactors.h"
#include "Prime.h"
#include "SquareRoot.h"

using namespace std;

int main()
{
   {
      constexpr long long number_to_test = 10'000'000LL;
      const auto start_time = chrono::high_resolution_clock::now();
      const int factor_count = CountFactorsNaiveApproach(number_to_test);
      const auto end_time = chrono::high_resolution_clock::now();
      const auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);

      cout << "Time taken to count factors of " << number_to_test <<
         " using naive approach: " << duration.count() << " seconds\n";
      cout << "Number of factors of " << number_to_test <<
         " is: " << factor_count << "\n";
   }
   {
      constexpr long long number_to_test = 10'000'000LL;
      const auto start_time = chrono::high_resolution_clock::now();
      const auto factor_count = CountFactorsOptimizedApproach(number_to_test);
      const auto  end_time = chrono::high_resolution_clock::now();
      const auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);
      cout << "Time taken to count factors of " << number_to_test <<
         " using optimized approach: " << duration.count() << " seconds\n";
      cout << "Number of factors of " << number_to_test <<
         " is: " << factor_count << "\n";
   }

   {
      // Testing prime checking functions
      constexpr long long prime_test_number = 999'983;
      cout << "Is " << prime_test_number << " prime? (Naive): "
         << (IsPrime(prime_test_number) ? "Yes" : "No") << "\n";
   }
   {
      constexpr long long perfect_square = 144;
      constexpr long long non_square = 150;
      constexpr long long prime_test_number = 999'983;
      constexpr long long non_prime = 1'000'000;

      // Test SquareRootOfPerfectSquare
      cout << "Square root of " << perfect_square << " (perfect square): "
         << SquareRootOfPerfectSquare(perfect_square) << "\n";
      cout << "Square root of " << non_square << " (non-perfect square): "
         << SquareRootOfPerfectSquare(non_square) << "\n";

      // Test FloorOfSqrt
      cout << "Floor of square root of " << non_square << ": "
         << FloorOfSqrt(non_square) << "\n";

      // Test IsPrimeOptimized
      cout << "Is " << prime_test_number << " prime? (Optimized): "
         << (IsPrimeOptimized(prime_test_number) ? "Yes" : "No") << "\n";
      cout << "Is " << non_prime << " prime? (Optimized): "
         << (IsPrimeOptimized(non_prime) ? "Yes" : "No") << "\n";
   }

}
