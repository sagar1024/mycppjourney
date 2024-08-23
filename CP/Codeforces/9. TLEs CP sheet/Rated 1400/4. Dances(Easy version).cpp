// G1. Dances (Easy version)

// time limit per test3 seconds
// memory limit per test256 megabytes

// This is the easy version of the problem. The only difference is that in this version m=1. You are given two arrays of integers a1,a2,…,an and b1,b2,…,bn. Before applying any operations, you can reorder the elements of each array as you wish. Then, in one operation, you will perform both of the following actions, if the arrays are not empty: Choose any element from array a and remove it (all remaining elements are shifted to a new array a), Choose any element from array b and remove it (all remaining elements are shifted to a new array b). Let k be the final size of both arrays. You need to find the minimum number of operations required to satisfy ai<bi for all 1≤i≤k. This problem was too easy, so the problem author decided to make it more challenging. You are also given a positive integer m. Now, you need to find the sum of answers to the problem for m pairs of arrays (c[i],b), where 1≤i≤m. Array c[i] is obtained from a as follows: c[i]1=i,c[i]j=aj, for 2≤j≤n.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) - the number of sets of input data. This is followed by their description. The first line of each test case contains two integers n and m (2≤n≤105, m=1) - the size of arrays a and b and the constraints on the value of element a1. The second line of each test case contains n−1 integers a2,…,an (1≤ai≤109). The third line of each test case contains n integers b1,b2,…,bn (1≤bi≤109). It is guaranteed that the sum of n over all test cases does not exceed 105.

// Output
// For each test case, output the total number of minimum operations for all pairs of arrays (ci,b).

// Example
// InputCopy
// 4
// 2 1
// 1
// 3 2
// 4 1
// 5 1 5
// 3 8 3 3
// 8 1
// 4 3 3 2 2 1 1
// 1 1 1 1 3 3 3 3
// 9 1
// 9 2 8 3 7 4 6 5
// 1 2 3 2 1 4 5 6 5

// OutputCopy
// 0
// 1
// 4
// 4

// Note

// In the first test case for the pair of arrays ([1,1],[3,2]), the answer is 0. No operations or reordering of elements are needed.

