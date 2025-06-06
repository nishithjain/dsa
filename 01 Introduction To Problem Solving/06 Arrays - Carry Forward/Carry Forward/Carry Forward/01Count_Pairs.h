#pragma once
#include <iostream>
#include <string>

/*
 * Carry Forward Technique:
 * Learn an efficient way to process sequences (like arrays or strings) by
 * carrying forward useful information from previous steps to avoid redundant
 * work and improve performance.
 * Problem Statement:
 *    Given a string s, you have to calculate the number of pair of
 *    indexes (i, j) such that i<j and the s[i] = 'a' and s[j] = 'g'.
 */

int count_pairs_naive(const std::string& s);
int count_pairs_naive_optimized(const std::string& s);
int count_pairs_optimized_right_to_left(const std::string& s);
int count_pairs_optimized_left_to_right(const std::string& s);
int count_pairs_prefix_sum(const std::string& s);
