#include <iostream>
#include "Question01.h"
#include "Question02.h"
#include "Question03.h"
#include "Question04.h"
#include "Question05.h"


int main() {
   {
      vector vec = { -3, -2, 6, 8, 4, 8, 5 };
      cout << "Question1:Approach1: " << Approach1(vec) << endl;
   }
   {
      vector vec = { -3, -2, 6, 8, 4, 8, 5 };
      cout << "Question1:Approach2: " << Approach2(vec) << endl;
   }
   {
      vector vec = { 3, -2, 1, 4, 3, 6, 8 };
      int k = 10;
      cout << "Has pair with sum (Approach1):== " << k << ": "
         << std::boolalpha << hasPairWithSum1(vec, k) << endl;
   }
   {
      vector vec = { 3, -2, 1, 4, 3, 6, 8 };
      int k = 10;
      cout << "Has pair with sum (Approach2):== " << k << ": "
         << std::boolalpha << hasPairWithSum2(vec, k) << endl;
   }

   {
      vector vec = { 3, -2, 1, 4, 3, 6, 8 };
      cout << "Before reversal:";
      for (auto i : vec)
         cout << i << " ";
      cout << endl;
      reverseArray(vec);
      cout << "After reversal: ";
      for (auto i : vec)
         cout << i << " ";
      cout << endl;
   }

   {
      vector vec = { 1, 2, 3, 4, 3, 1, 2 };
      size_t start = 2;
      size_t end = 6;
      cout << "Before reversal:";
      for (auto i : vec)
         cout << i << " ";
      cout << endl;
      reverseSubArray(vec, start, end);
      cout << "After reversal: ";
      for (auto i : vec)
         cout << i << " ";
      cout << endl;
   }

   {
      vector vec = { 3, -2, 1, 4, 6, 9, 8 };
      size_t k = 2;
      cout << "Before Rotate Extra Space:";
      for (auto i : vec)
         cout << i << " ";
      cout << endl;
      vec = rotateK_TimesExtraSpace(vec, k);
      cout << "After Rotate Extra Space: ";
      for (auto i : vec)
         cout << i << " ";
      cout << endl;
   }
   {
      vector vec = { 3, -2, 1, 4, 6, 9, 8 };
      size_t k = 2;
      cout << "Before Rotate:";
      for (auto i : vec)
         cout << i << " ";
      cout << endl;
      rotateK_Times(vec, k);
      cout << "After Rotate: ";
      for (auto i : vec)
         cout << i << " ";
      cout << endl;
   }
}
