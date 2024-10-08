// C. Rotation Matching

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// After the mysterious disappearance of Ashish, his two favourite disciples Ishika and Hriday, were each left with one half of a secret message. These messages can each be represented by a permutation of size n. Let's call them a and b. Note that a permutation of n elements is a sequence of numbers a1,a2,…,an, in which every number from 1 to n appears exactly once. The message can be decoded by an arrangement of sequence a and b, such that the number of matching pairs of elements between them is maximum. A pair of elements ai and bj is said to match if:

// i=j, that is, they are at the same index.
// ai=bj

// His two disciples are allowed to perform the following operation any number of times: choose a number k and cyclically shift one of the permutations to the left or right k times. A single cyclic shift to the left on any permutation c is an operation that sets c1:=c2,c2:=c3,…,cn:=c1 simultaneously. Likewise, a single cyclic shift to the right on any permutation c is an operation that sets c1:=cn,c2:=c1,…,cn:=cn−1 simultaneously.

// Help Ishika and Hriday find the maximum number of pairs of elements that match after performing the operation any (possibly zero) number of times.

// Input
// The first line of the input contains a single integer n (1≤n≤2⋅105) — the size of the arrays. The second line contains n integers a1, a2, ..., an (1≤ai≤n) — the elements of the first permutation. The third line contains n integers b1, b2, ..., bn (1≤bi≤n) — the elements of the second permutation.

// Output
// Print the maximum number of matching pairs of elements after performing the above operations some (possibly zero) times.

// Examples
// inputCopy
// 5
// 1 2 3 4 5
// 2 3 4 5 1
// outputCopy
// 5
// inputCopy
// 5
// 5 4 3 2 1
// 1 2 3 4 5
// outputCopy
// 1
// inputCopy
// 4
// 1 3 2 4
// 4 2 3 1
// outputCopy
// 2

// Note
// For the first case: b can be shifted to the right by k=1. The resulting permutations will be {1,2,3,4,5} and {1,2,3,4,5}.
// For the second case: The operation is not required. For all possible rotations of a and b, the number of matching pairs won't exceed 1.
// For the third case: b can be shifted to the left by k=1. The resulting permutations will be {1,3,2,4} and {2,3,1,4}. Positions 2 and 4 have matching pairs of elements. For all possible rotations of a and b, the number of matching pairs won't exceed 2.

