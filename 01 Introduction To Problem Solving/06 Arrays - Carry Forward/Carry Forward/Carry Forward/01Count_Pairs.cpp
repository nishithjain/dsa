#include "01Count_Pairs.h"

#include <vector>

int count_pairs_naive(const std::string& s) {
   const size_t len = s.length();
   int count = 0;
   for (size_t i = 0; i < len; i++) {
      // j = i + 1 because problem says i < j
      for (auto j = i + 1; j < len; j++) {
         if (s[i] == 'a' && s[j] == 'g') {
            count++;
         }
      }
   }
   return count;
}

int count_pairs_naive_optimized(const std::string& s) {
   const size_t len = s.length();
   int count = 0;
   for (size_t i = 0; i < len; i++) {
      if (s[i] == 'a') {  // I want to stand only at s[i] = 'a'
         for (auto j = i + 1; j < len; j++) {
            if (s[j] == 'g') {
               count++;
            }
         }
      }
   }
   return count;
}

int count_pairs_optimized_right_to_left(const std::string& s) {
   int number_of_gs = 0;
   int count = 0;
   const size_t len = s.length();

   for (auto i = len - 1; i > 0; i--) {
      if (s[i] == 'g')
         number_of_gs++;
      else if (s[i] == 'a')
         count += number_of_gs;
   }
   return count;
}

int count_pairs_optimized_left_to_right(const std::string& s) {
   int number_of_as = 0;
   int count = 0;
   const size_t len = s.length();

   for (size_t i = 0; i < len; i++) {
      if (s[i] == 'a')
         number_of_as++;
      else if (s[i] == 'g')
         count += number_of_as;
   }
   return count;
}

int count_pairs_prefix_sum(const std::string& s) {
   const size_t len = s.length();
   std::vector ps(len, 0);
   if (s[0] == 'a') ps[0] = 1;

   for (size_t i = 1; i < len; i++) {
      ps[i] = (s[i] == 'a') ? ps[i - 1] + 1 : ps[i - 1];
   }
   int count = 0;
   for (size_t i = 1; i < len; i++) {
      if (s[i] == 'g') count += ps[i];
   }
   return count;
}