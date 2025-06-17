#pragma once
#include <vector>

void PrintMatrix(const std::vector<std::vector<int>>& matrix);
void PrintMajorDiagonalElements(const std::vector<std::vector<int>>& matrix);
void PrintMinorDiagonalElements(const std::vector<std::vector<int>>& matrix);

void PrintAllDiagonals(const std::vector<std::vector<int>>& matrix);

// For matrix of NxM size. You have to allocate new matrix of size MxN.
std::vector<std::vector<int>> FindTransposeOfMatrix(
   const std::vector<std::vector<int>>& matrix);


void FindTransposeOfSquareMatrixInPlace(
   std::vector<std::vector<int>>& matrix);

void ReverseArray(std::vector<int>& vec);
void RotateMatrixBy90Degree(std::vector<std::vector<int>>& matrix);