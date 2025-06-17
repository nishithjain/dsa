#include "Matrices2D.h"
#include <iostream>

using namespace std;

int main()
{
   {
      const std::vector<std::vector<int>> matrix = {
           {11, 32, 43, 75, -4, 55},
           {-7, 77, 22, 39, 16, -9},
           {65, 31, 66, 40, -7, 67},
           {47, 12, -3, -6, 30, 80},
           {97, 87, 12, -2, -4, 39},
           {-5, 99, 43, 12, 10, 34}
      };
      PrintMatrix(matrix);
      PrintMajorDiagonalElements(matrix);
      PrintMinorDiagonalElements(matrix);
      cout << "----------------------------------------\n";
   }
   {
      const std::vector<std::vector<int>> matrix = {
           {11, 32, 43, 75, -4},
           {-7, 77, 22, 39, 16},
           {65, 31, 66, 40, -7},
           {47, 12, -3, -6, 30},
           {97, 87, 12, -2, -4},
           {-5, 99, 43, 12, 10}
      };
      PrintMatrix(matrix);
      PrintAllDiagonals(matrix);
      cout << "----------------------------------------\n";
   }

   {
      const std::vector<std::vector<int>> matrix = {
           {11, 32, 43, 75, -4},
           {-7, 77, 22, 39, 16},
           {65, 31, 66, 40, -7},
           {47, 12, -3, -6, 30},
           {97, 87, 12, -2, -4},
           {-5, 99, 43, 12, 10}
      };

      PrintMatrix(matrix);
      const auto result = FindTransposeOfMatrix(matrix);
      cout << "Transpose of Matrix NxM: \n";
      PrintMatrix(result);
      cout << "----------------------------------------\n";
   }

   {
      std::vector<std::vector<int>> matrix = {
           {11, 32, 43, 75, -4, 55},
           {-7, 77, 22, 39, 16, -9},
           {65, 31, 66, 40, -7, 67},
           {47, 12, -3, -6, 30, 80},
           {97, 87, 12, -2, -4, 39},
           {-5, 99, 43, 12, 10, 34}
      };

      PrintMatrix(matrix);
      FindTransposeOfSquareMatrixInPlace(matrix);
      cout << "Transpose of Square Matrix In-place: \n";
      PrintMatrix(matrix);
      cout << "----------------------------------------\n";
   }

   {
      std::vector<std::vector<int>> matrix = {
           {11, 32, 43, 75, -4, 55},
           {-7, 77, 22, 39, 16, -9},
           {65, 31, 66, 40, -7, 67},
           {47, 12, -3, -6, 30, 80},
           {97, 87, 12, -2, -4, 39},
           {-5, 99, 43, 12, 10, 34}
      };

      PrintMatrix(matrix);
      RotateMatrixBy90Degree(matrix);
      cout << "After 90Degree Rotation: \n";
      PrintMatrix(matrix);
      cout << "----------------------------------------\n";
   }
}