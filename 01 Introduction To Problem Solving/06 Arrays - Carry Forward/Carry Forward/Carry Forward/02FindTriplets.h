#pragma once
#include <string>
/* Problem Statement:
 *    Given a string S, find the number of triplets (i, j, k) such that:
 *    i < j < k
 *    S[i] == 'A', S[j] == 'X', and S[k] == 'G'
 */

int CountTripletsBruteForceApproach(const std::string& s);
int CountTripletsPrefixSuffixSum(const std::string& s);
int CountTriplets(const std::string& s);