// B. Composite Coloring

// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output

// A positive integer is called composite if it can be represented as a product of two positive integers, both greater than 1. For example, the following numbers are composite: 6, 4, 120, 27. The following numbers aren't: 1, 2, 3, 17, 97. Alice is given a sequence of n composite numbers a1,a2,…,an. She wants to choose an integer m≤11 and color each element one of m colors from 1 to m so that:

// for each color from 1 to m there is at least one element of this color;
// each element is colored and colored exactly one color;
// the greatest common divisor of any two elements that are colored the same color is greater than 1, i.e. gcd(ai,aj)>1 for each pair i,j if these elements are colored the same color.

// Note that equal elements can be colored different colors — you just have to choose one of m colors for each of the indices from 1 to n. Alice showed already that if all ai≤1000 then she can always solve the task by choosing some m≤11. Help Alice to find the required coloring. Note that you don't have to minimize or maximize the number of colors, you just have to find the solution with some m from 1 to 11.

// Input
// The first line contains a single integer t (1≤t≤1000) — the number of test cases. Then the descriptions of the test cases follow. The first line of the test case contains a single integer n (1≤n≤1000) — the amount of numbers in a sequence a. The second line of the test case contains n composite integers a1,a2,…,an (4≤ai≤1000). It is guaranteed that the sum of n over all test cases doesn't exceed 104.

// Output
// For each test case print 2 lines. The first line should contain a single integer m (1≤m≤11) — the number of used colors. Consider colors to be numbered from 1 to m. The second line should contain any coloring that satisfies the above conditions. Print n integers c1,c2,…,cn (1≤ci≤m), where ci is the color of the i-th element. If there are multiple solutions then you can print any of them. Note that you don't have to minimize or maximize the number of colors, you just have to find the solution with some m from 1 to 11. Remember that each color from 1 to m should be used at least once. Any two elements of the same color should not be coprime (i.e. their GCD should be greater than 1).

// Example
// inputCopy
// 3
// 3
// 6 10 15
// 2
// 4 9
// 23
// 437 519 865 808 909 391 194 291 237 395 323 365 511 497 781 737 871 559 731 697 779 841 961

// outputCopy
// 1
// 1 1 1
// 2
// 2 1
// 11
// 4 7 8 10 7 3 10 7 7 8 3 1 1 5 5 9 2 2 3 3 4 11 6

// Note
// In the first test case, gcd(6,10)=2, gcd(6,15)=3 and gcd(10,15)=5. Therefore, it's valid to color all elements the same color. Note that there are other colorings which satisfy Alice's requirement in this test case.
// In the second test case there is only one element of each color, so the coloring definitely satisfies Alice's requirement.

