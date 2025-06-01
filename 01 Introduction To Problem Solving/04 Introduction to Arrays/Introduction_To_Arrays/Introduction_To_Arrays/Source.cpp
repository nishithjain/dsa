#include <iostream>
#include "Question01.h"

int main() {
   {
      vector vec = { -3, -2, 6, 8, 4, 8, 5 };
      cout << "Question1:Approach1: " << Approach1(vec) << endl;
   }
   {
      vector vec = { -3, -2, 6, 8, 4, 8, 5 };
      cout << "Question1:Approach2: " << Approach2(vec) << endl;
   }
}