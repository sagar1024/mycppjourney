// D. Binary String To Subsequences

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a binary string s consisting of n zeros and ones. Your task is to divide the given string into the minimum number of subsequences in such a way that each character of the string belongs to exactly one subsequence and each subsequence looks like "010101 ..." or "101010 ..." (i.e. the subsequence should not contain two adjacent zeros or ones). Recall that a subsequence is a sequence that can be derived from the given sequence by deleting zero or more elements without changing the order of the remaining elements. For example, subsequences of "1011101" are "0", "1", "11111", "0111", "101", "1001", but not "000", "101010" and "11100". You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow. The first line of the test case contains one integer n (1≤n≤2⋅105) — the length of s. The second line of the test case contains n characters '0' and '1' — the string s. It is guaranteed that the sum of n does not exceed 2⋅105 (∑n≤2⋅105).

// Output
// For each test case, print the answer: in the first line print one integer k (1≤k≤n) — the minimum number of subsequences you can divide the string s to. In the second line print n integers a1,a2,…,an (1≤ai≤k), where ai is the number of subsequence the i-th character of s belongs to. If there are several answers, you can print any.

// Example
// inputCopy
// 4
// 4
// 0011
// 6
// 111111
// 5
// 10101
// 8
// 01010000
// outputCopy
// 2
// 1 2 2 1 
// 6
// 1 2 3 4 5 6 
// 1
// 1 1 1 1 1 
// 4
// 1 1 1 1 1 2 3 4

