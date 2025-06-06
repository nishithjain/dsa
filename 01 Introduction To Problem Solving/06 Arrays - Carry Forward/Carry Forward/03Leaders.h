#pragma once
#include <vector>
/* Count the Leaders in an Array
* An element in an array is a leader if it is strictly greater
* than all the elements to its right.
* The last element is always a leader because there's
* nothing on its right to compare with.
*/

int CountLeadersNaive(const std::vector<int>& vec);
int CountLeadersOptimized(const std::vector<int>& vec);