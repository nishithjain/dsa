#pragma once
#include <vector>

/*
 *
 *What is a Sub-array?
 *    A sub-array is a contiguous (continuous) part of an array.
 * Basic Properties of Sub-arrays
	    Single elements are valid sub-arrays.
	    Entire array is a valid sub-array.
	    Unique identification: Each sub-array is uniquely represented 
		     by its start (L) and end (R) indices.
      Valid Index Range:
	       0 <= L <= R < N (N is the size of the array)
      Number of elements in a sub-array from L to R 
	       = R - L + 1
*/
void PrintAllSubArrays(const std::vector<int>& vec);

void SumOfAllSubArrays(const std::vector<int>& vec);

/*
 * Print the sum of all sub-arrays which start at
 * index 2.
 */
void SumOfAllSubArraysAt2(const std::vector<int>& vec);

/*
 * Print the sum of all sub-arrays without PrefixSum.
 */
void SumOfAllSubArraysOptimized(const std::vector<int>& vec);


int MaxSubArraySum(const std::vector<int>& vec);

int SumOfSumOfAllSubArrays(const std::vector<int>& vec);

int SumOfSumOfAllSubArraysContributionTechnique(const std::vector<int>& vec);