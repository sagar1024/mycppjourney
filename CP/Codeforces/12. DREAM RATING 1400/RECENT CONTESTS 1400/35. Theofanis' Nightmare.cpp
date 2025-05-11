// C. Theofanis' Nightmare

// time limit per test1 second
// memory limit per test256 megabytes

// Theofanis easily gets obsessed with problems before going to sleep and often has nightmares about them. To deal with his obsession he visited his doctor, Dr. Emix. In his latest nightmare, he has an array a of size n and wants to divide it into non-empty subarrays† such that every element is in exactly one of the subarrays. For example, the array [1,−3,7,−6,2,5] can be divided to [1][−3,7][−6,2][5]. The Cypriot value of such division is equal to Σki=1i⋅sumi where k is the number of subarrays that we divided the array into and sumi is the sum of the i-th subarray. The Cypriot value of this division of the array [1][−3,7][−6,2][5]=1⋅1+2⋅(−3+7)+3⋅(−6+2)+4⋅5=17. Theofanis is wondering what is the maximum Cypriot value of any division of the array. An array b is a subarray of an array a if b can be obtained from a by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end. In particular, an array is a subarray of itself.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. Each test case consists of two lines. The first line of each test case contains a single integer n (1≤n≤105) — the size of the array. The second line contains n integers a1,a2,…,an (−108≤ai≤108) — the elements of the array. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print one integer — the maximum Cypriot value of the array a.

// Example
// InputCopy
// 4
// 6
// 1 -3 7 -6 2 5
// 4
// 2 9 -5 -3
// 8
// -3 -4 2 -5 1 10 17 23
// 1
// 830
// OutputCopy
// 32
// 4
// 343
// 830

// Note
// In the first test case, to get the maximum Cypriot value we divide the array into [1][−3][7][−6][2][5] which gives us: Σki=1i⋅sumi=1⋅1+2⋅(−3)+3⋅7+4⋅(−6)+5⋅2+6⋅5=32
// Similarly, in the second test case we divide the array into [2][9,−5,−3] which gives us Σki=1i⋅sumi=1⋅2+2⋅(9+(−5)+(−3))=4.

