// D. Distinct Split

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Let's denote the f(x) function for a string x as the number of distinct characters that the string contains. For example f(abc)=3, f(bbbbb)=1, and f(babacaba)=3. Given a string s, split it into two non-empty strings a and b such that f(a)+f(b) is the maximum possible. In other words, find the maximum possible value of f(a)+f(b) such that a+b=s (the concatenation of string a and string b is equal to string s).

// Input
// The input consists of multiple test cases. The first line contains an integer t (1≤t≤104) — the number of test cases. The description of the test cases follows. The first line of each test case contains an integer n (2≤n≤2⋅105) — the length of the string s. The second line contains the string s, consisting of lowercase English letters. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output a single integer  — the maximum possible value of f(a)+f(b) such that a+b=s.

// Example
// inputCopy
// 5
// 2
// aa
// 7
// abcabcd
// 5
// aaaaa
// 10
// paiumoment
// 4
// aazz

// outputCopy
// 2
// 7
// 2
// 10
// 3

// Note
// For the first test case, there is only one valid way to split aa into two non-empty strings a and a, and f(a)+f(a)=1+1=2.
// For the second test case, by splitting abcabcd into abc and abcd we can get the answer of f(abc)+f(abcd)=3+4=7 which is maximum possible.
// For the third test case, it doesn't matter how we split the string, the answer will always be 2.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     //Storing the frequency of the letters
//     //Initializing it with zeros
//     int lettersFreq[26] = {0};

//     for(int i=0; i<n; i++)
//     {
//         lettersFreq[s[i]-'a']++;
//     }

//     //Crux of the problem
//     //Stores the result
//     int maxValuePossible = 0;

//     //Iteating twice as there are two f() functions
//     //Adding all the unique letter first
//     //AND subsequently subtracting their freq by one
//     //Then counting the remain nonZero frequencies
//     //AND then adding them to the final result
//     for (int i=1; i<=2; i++)
//     {
//         for (int j=0; j<=25; j++)
//         {
//             if (lettersFreq[j]>0)
//             {
//                 maxValuePossible++;
//                 lettersFreq[j]--;
//             }
//         }
//     }

//     cout << maxValuePossible << endl;
//     return;
// }

// int main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Wrong question -
// In the test case 1
// Max possible value for aazz is 4 not 3
