#include <iostream>
#include "Matrices2D.h"

using namespace std;

void PrintMatrix(const vector<vector<int>>& matrix)
{
   cout << "Matrix: \n";
   const auto row = matrix.size();
   const size_t col = row > 0 ? matrix[0].size() : 0;

   for (size_t i = 0; i < row; ++i) {
      for (size_t j = 0; j < col; ++j) {
         cout << matrix[i][j] << " ";
      }
      cout << '\n';
   }
}

void PrintMajorDiagonalElements(const vector<vector<int>>& matrix)
{
   const auto n = matrix.size();
   cout << "Major Diagonal Elements: ";
   for (size_t i = 0; i < n; ++i) {
      if (i < matrix[i].size()) {
         cout << matrix[i][i] << " ";
      }
   }
   cout << '\n';
}

/*
 n = 6
       j=0    j=1    j=2    j=3    j=4    j=5
     +------+------+------+------+------+------+
i=0  |  x   |  x   |  x   |  x   |  x   |  5   | <- i=0, j=5
     +------+------+------+------+------+------+
i=1  |  x   |  x   |  x   |  x   | 16   |  x   | <- i=1, j=4
     +------+------+------+------+------+------+
i=2  |  x   |  x   |  x   | 40   |  x   |  x   | <- i=2, j=3
     +------+------+------+------+------+------+
i=3  |  x   |  x   | -3   |  x   |  x   |  x   | <- i=3, j=2
     +------+------+------+------+------+------+
i=4  |  x   |  7   |  x   |  x   |  x   |  x   | <- i=4, j=1
     +------+------+------+------+------+------+
i=5  | -54  |  x   |  x   |  x   |  x   |  x   | <- i=5, j=0
     +------+------+------+------+------+------+
     The i is incrementing and j is decrementing, we can put
     i = 0 and j = n-1, i++ and j--.
     Also, if we observer, i + j = n - 1;
     So, j = n - 1 - i;
 */
void PrintMinorDiagonalElements(const vector<vector<int>>& matrix)
{
   const auto n = matrix.size();
   cout << "Minor Diagonal Elements (Approach 1): ";

   size_t i = 0, j = n - 1;
   while (i < n)
   {
      cout << matrix[i][j] << " ";
      i++;
      j--;
   }
   cout << '\n';

   cout << "Minor Diagonal Elements (Approach 2): ";
   for (size_t i = 0; i < n; i++)
   {
      auto j = n - 1 - i;
      cout << matrix[i][j] << " ";
   }
   cout << '\n';
}

/*
 * Given a 2D array of size N*M, print all the diagonals from Right
 * to Left and top to bottom.
 *n = 6     (N = rows = 6, M = columns = 6)
        j=0   j=1   j=2   j=3   j=4   j=5
      +-----+-----+-----+-----+-----+-----+
i=0   |  *  |  *  |  *  |  *  |  *  |  *  |  <- Start diagonal: i=0, j=5
      +-----+-----+-----+-----+-----+-----+
i=1   |  *  |  *  |  *  |  *  |  *  |     |  <- Start diagonal: i=0, j=4
      +-----+-----+-----+-----+-----+-----+
i=2   |  *  |  *  |  *  |  *  |     |     |  <- Start diagonal: i=0, j=3
      +-----+-----+-----+-----+-----+-----+
i=3   |  *  |  *  |  *  |     |     |     |  <- Start diagonal: i=0, j=2
      +-----+-----+-----+-----+-----+-----+
i=4   |  *  |  *  |     |     |     |     |  <- Start diagonal: i=0, j=1
      +-----+-----+-----+-----+-----+-----+
i=5   |  *  |     |     |     |     |     |  <- Start diagonal: i=0, j=0
      +-----+-----+-----+-----+-----+-----+

Now Part 2: i = 1 to N-1, j = M-1 (rightmost column)
        j=0   j=1   j=2   j=3   j=4   j=5
      +-----+-----+-----+-----+-----+-----+
i=0   |     |     |     |     |     |     |
      +-----+-----+-----+-----+-----+-----+
i=1   |     |     |     |     |     |  *  |  <- Start diagonal: i=1, j=5
      +-----+-----+-----+-----+-----+-----+
i=2   |     |     |     |     |  *  |  *  |  <- Start diagonal: i=2, j=5
      +-----+-----+-----+-----+-----+-----+
i=3   |     |     |     |  *  |  *  |  *  |  <- Start diagonal: i=3, j=5
      +-----+-----+-----+-----+-----+-----+
i=4   |     |     |  *  |  *  |  *  |  *  |  <- Start diagonal: i=4, j=5
      +-----+-----+-----+-----+-----+-----+
i=5   |     |  *  |  *  |  *  |  *  |  *  |  <- Start diagonal: i=5, j=5
      +-----+-----+-----+-----+-----+-----+
 */
void PrintAllDiagonals(const vector<vector<int>>& matrix)
{
   const int n = static_cast<int>(matrix.size());
   const int m = n > 0 ? static_cast<int>(matrix[0].size()) : 0;

   cout << "Printing all diagonals:\n";
   // Can be divided into 2 parts
   for (int col = m - 1; col >= 0; col--) {
      int i = 0, j = col;
      while (i < n && j >= 0)
      {
         cout << matrix[i][j] << " ";
         i++; j--;
      }
      cout << '\n';
   }

   for (int row = 1; row < n; row++)
   {
      int i = row, j = m - 1;
      while (i < n && j >= 0)
      {
         cout << matrix[i][j] << " ";
         i++; j--;
      }
      cout << '\n';
   }
}

/*
        j=0     j=1    j=2    j=3    j=4    j=5                 j=0    j=1    j=2     j=3    j=4    j=5
      +------+------+------+------+------+------+             +------+------+------+------+------+------+
i=0   |  11  |  32  |  43  |  75  |  -4  |  55  |       i=0   |  11  |  -7  |  65  |  47  |  97  |  -5  |
      +------+------+------+------+------+------+             +------+------+------+------+------+------+
i=1   |  -7  |  77  |  22  |  39  |  16  |  -9  |       i=1   |  32  |  77  |  31  |  12  |  87  |  99  |
      +------+------+------+------+------+------+             +------+------+------+------+------+------+
i=2   |  65  |  31  |  66  |  40  |  -7  |  67  |  ==>  i=2   |  43  |  22  |  66  |  -3  |  12  |  43  |
      +------+------+------+------+------+------+             +------+------+------+------+------+------+
i=3   |  47  |  12  |  -3  |  -6  |  30  |  80  |       i=3   |  75  |  39  |  40  |  -6  |  -2  |  12  |
      +------+------+------+------+------+------+             +------+------+------+------+------+------+
i=4   |  97  |  87  |  12  |  -2  |  -4  |  39  |       i=4   |  -4  |  16  |  -7  |  30  |  -4  |  10  |
      +------+------+------+------+------+------+             +------+------+------+------+------+------+
i=5   |  -5  |  99  |  43  |  12  |  10  |  34  |       i=5   |  55  |  -9  |  67  |  80  |  39  |  34  |
      +------+------+------+------+------+------+             +------+------+------+------+------+------+
*/
vector<vector<int>> FindTransposeOfMatrix(const vector<vector<int>>& matrix)
{
   const auto n = matrix.size();
   const size_t m = n > 0 ? static_cast<int>(matrix[0].size()) : 0;
   vector<vector<int>> transpose(m, vector<int>(n));

   for (size_t i = 0; i < n; i++)
   {
      for (size_t j = 0; j < m; j++)
      {
         transpose[j][i] = matrix[i][j];
      }
   }
   return transpose;
}

/*
         j=0   j=1   j=2   j=3   j=4   j=5
      +-----+-----+-----+-----+-----+-----+
i=0   |  -  |  -  |  -  |  -  |  -  |  -  |
      +-----+-----+-----+-----+-----+-----+
i=1   |  *  |  -  |  -  |  -  |  -  |  -  |  <- swap [1][0] with [0][1]
      +-----+-----+-----+-----+-----+-----+
i=2   |  *  |  *  |  -  |  -  |  -  |  -  |  <- [2][0], [2][1]
      +-----+-----+-----+-----+-----+-----+
i=3   |  *  |  *  |  *  |  -  |  -  |  -  |  <- [3][0], [3][1], [3][2]
      +-----+-----+-----+-----+-----+-----+
i=4   |  *  |  *  |  *  |  *  |  -  |  -  |  <- [4][0] ... [4][3]
      +-----+-----+-----+-----+-----+-----+
i=5   |  *  |  *  |  *  |  *  |  *  |  -  |  <- [5][0] ... [5][4]
      +-----+-----+-----+-----+-----+-----+
 */
void FindTransposeOfSquareMatrixInPlace(vector<vector<int>>& matrix)
{
   const auto n = matrix.size();
   for (size_t i = 1; i < n; i++)
   {
      for (size_t j = 0; j < i; j++)
      {
         swap(matrix[i][j], matrix[j][i]);
      }
   }
}

void ReverseArray(vector<int>& vec) {
   size_t i = 0;
   size_t j = vec.size() - 1;

   while (i < j) {
      std::swap(vec[i], vec[j]);
      i++;
      j--;
   }
}

/*
        j=0     j=1    j=2    j=3    j=4    j=5                  j=0     j=1    j=2    j=3    j=4    j=5
      +------+------+------+------+------+------+              +------+------+------+------+------+------+
i=0   |  11  |  32  |  43  |  75  |  -4  |  55  |        i=0   |  -5  |  97  |  47  |  65  |  -7  |  11  |
      +------+------+------+------+------+------+              +------+------+------+------+------+------+
i=1   |  -7  |  77  |  22  |  39  |  16  |  -9  |        i=1   |  99  |  87  |  12  |  31  |  77  |  32  |
      +------+------+------+------+------+------+              +------+------+------+------+------+------+
i=2   |  65  |  31  |  66  |  40  |  -7  |  67  |  ==>   i=2   |  43  |  12  |  -3  |  66  |  22  |  43  |
      +------+------+------+------+------+------+              +------+------+------+------+------+------+
i=3   |  47  |  12  |  -3  |  -6  |  30  |  80  |        i=3   |  12  |  -2  |  -6  |  40  |  39  |  75  |
      +------+------+------+------+------+------+              +------+------+------+------+------+------+
i=4   |  97  |  87  |  12  |  -2  |  -4  |  39  |        i=4   |  10  |  -4  |  30  |  -7  |  16  |  -4  |
      +------+------+------+------+------+------+              +------+------+------+------+------+------+
i=5   |  -5  |  99  |  43  |  12  |  10  |  34  |        i=5   |  34  |  39  |  80  |  67  |  -9  |  55  |
      +------+------+------+------+------+------+              +------+------+------+------+------+------+
*/
void RotateMatrixBy90Degree(std::vector<std::vector<int>>& matrix)
{
   // Logic is to transpose first and then reverse each row.
   FindTransposeOfSquareMatrixInPlace(matrix);
   for (auto& i : matrix)
      ReverseArray(i);
}

/*
         j=0      j=1      j=2      j=3      j=4      j=5
      +--------+--------+--------+--------+--------+--------+
i=0   |  * 11  | * 32   |  * 43  |  * 75  |  * -4  |  * 55  |
      +--------+--------+--------+--------+--------+--------+
i=1   |  * -7  |   77   |   22   |   39   |   16   |  * -9  |
      +--------+--------+--------+--------+--------+--------+
i=2   |  * 65  |   31   |   66   |   40   |  -7    |  * 67  |
      +--------+--------+--------+--------+--------+--------+
i=3   |  * 47  |   12   |  -3    |  -6    |  30    |  * 80  |
      +--------+--------+--------+--------+--------+--------+
i=4   |  * 97  |   87   |  12    |  -2    |  -4    |  * 39  |
      +--------+--------+--------+--------+--------+--------+
i=5   |  * -5  |  * 99  |  * 43  |  * 12  |  * 10  |  * 34  |
      +--------+--------+--------+--------+--------+--------+
      * elements are boundary elements.
      *
      *Steps:
      * 1. Print N-1 elements to right.
      * 2. Print N-1 elements to down.
      * 3. Print N-1 elements to left.
      * 4. Print N-1 elements to top.
 */
void PrintBoundaryClockwiseSquareMatrix(const std::vector<std::vector<int>>& matrix)
{
   const int n = static_cast<int>(matrix.size());
   int i = 0, j = 0;
   // Number of elements [1, n-1] = r - l + 1
   // = n - 1 - 1 + 1 = n - 1 elements.
   for (int k = 1; k <= n - 1; k++)
   {
      cout << matrix[i][j] << " ";
      j++;
   } //  End of the loop i = 0 and j = n - 1 = 5

   for (int k = 1; k <= n - 1; k++)
   {
      cout << matrix[i][j] << " ";
      i++;
   } //  End of the loop i = n - 1 = 5  and j = n - 1 = 5

   for (int k = 1; k <= n - 1; k++)
   {
      cout << matrix[i][j] << " ";
      j--;
   } //  End of the loop i = n - 1  and j = 0

   for (int k = 1; k <= n - 1; k++)
   {
      cout << matrix[i][j] << " ";
      i--;
   } //  End of the loop i = 0  and j = 0
   cout << '\n';
}

void PrintBoundaryClockwise(const std::vector<std::vector<int>>& matrix)
{
   const int rows = static_cast<int>(matrix.size());
   if (rows == 0) return;

   const int cols = static_cast<int>(matrix[0].size());
   if (cols == 0) return;

   // Top row (left to right)
   for (int j = 0; j < cols; ++j)
      cout << matrix[0][j] << " ";

   // Right column (top to bottom), skip top cell
   for (int i = 1; i < rows; ++i)
      cout << matrix[i][cols - 1] << " ";

   // Bottom row (right to left), skip bottom-right if more than 1 row
   if (rows > 1) {
      for (int j = cols - 2; j >= 0; --j)
         cout << matrix[rows - 1][j] << " ";
   }

   // Left column (bottom to top), skip bottom-left and top-left if more than 1 col
   if (cols > 1) {
      for (int i = rows - 2; i > 0; --i)
         cout << matrix[i][0] << " ";
   }

   cout << '\n';
}

/*
          j=0     j=1     j=2     j=3     j=4     j=5
      +-------+-------+-------+-------+-------+-------+
i=0   |   -   |   -   |   -   |   -   |   ->  |   |   |
      +-------+-------+-------+-------+-------+-------+
i=1   |   -   |   -   |   -   |  ->   |   |   |   |   |
      +-------+-------+-------+-------+-------+-------+
i=2   |   ^   |   -   |  ->   |   v   |   |   |   |   |
      +-------+-------+-------+-------+-------+-------+
i=3   |   |   |   ^   |   *   |  <-   |   v   |   |   |
      +-------+-------+-------+-------+-------+-------+
i=4   |   |   |   |   |  <-   |   -   |   -   |   v   |
      +-------+-------+-------+-------+-------+-------+
i=5   |   |   |  <-   |   -   |   -   |   -   |   -   |
      +-------+-------+-------+-------+-------+-------+
 */
void PrintSpiral(const std::vector<std::vector<int>>& matrix)
{
   int i = 0, j = 0;
   int n = static_cast<int>(matrix.size());

   while (n > 1)
   {
      for (int k = 1; k <= n - 1; k++)
      {
         cout << matrix[i][j] << " ";
         j++;
      } 

      for (int k = 1; k <= n - 1; k++)
      {
         cout << matrix[i][j] << " ";
         i++;
      } 

      for (int k = 1; k <= n - 1; k++)
      {
         cout << matrix[i][j] << " ";
         j--;
      } 

      for (int k = 1; k <= n - 1; k++)
      {
         cout << matrix[i][j] << " ";
         i--;
      }
      n = n - 2;
      i++; j++;
   }
   if (n == 1)
      cout<< matrix[i][j] << " ";

   cout << '\n';
}
