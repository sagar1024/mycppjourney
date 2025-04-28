// F. Greetings

// time limit per test5 seconds
// memory limit per test256 megabytes

// There are n people on the number line; the i-th person is at point ai and wants to go to point bi. For each person, ai<bi, and the starting and ending points of all people are distinct. (That is, all of the 2n numbers a1,a2,…,an,b1,b2,…,bn are distinct.) All the people will start moving simultaneously at a speed of 1 unit per second until they reach their final point bi. When two people meet at the same point, they will greet each other once. How many greetings will there be? Note that a person can still greet other people even if they have reached their final point.

// Input
// The first line of the input contains a single integer t (1≤t≤104) — the number of test cases. The description of test cases follows. The first line of each test case contains a single integer n (1≤n≤2⋅105) — the number of people. Then n lines follow, the i-th of which contains two integers ai and bi (−109≤ai<bi≤109) — the starting and ending positions of each person. For each test case, all of the 2n numbers a1,a2,…,an,b1,b2,…,bn are distinct. The sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output a single integer denoting the number of greetings that will happen.

// Example
// InputCopy
// 5
// 2
// 2 3
// 1 4
// 6
// 2 6
// 3 9
// 4 5
// 1 8
// 7 10
// -2 100
// 4
// -10 10
// -5 5
// -12 12
// -13 13
// 5
// -4 9
// -2 5
// 3 4
// 6 7
// 8 10
// 4
// 1 2
// 3 4
// 5 6
// 7 8
// OutputCopy
// 1
// 9
// 6
// 4
// 0

// Note
// In the first test case, the two people will meet at point 3 and greet each other.

