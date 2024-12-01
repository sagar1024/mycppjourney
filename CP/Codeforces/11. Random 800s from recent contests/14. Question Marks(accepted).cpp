// A. Question Marks

// time limit per test1 second
// memory limit per test256 megabytes

// Tim is doing a test consisting of 4n questions; each question has 4 options: 'A', 'B', 'C', and 'D'. For each option, there are exactly n correct answers corresponding to that option — meaning there are n questions with the answer 'A', n questions with the answer 'B', n questions with the answer 'C', and n questions with the answer 'D'. For each question, Tim wrote his answer on the answer sheet. If he could not figure out the answer, he would leave a question mark '?' for that question. You are given his answer sheet of 4n characters. What is the maximum number of correct answers Tim can get?

// Input
// The first line contains a single integer t (1≤t≤1000) — the number of test cases. The first line of each test case contains an integer n (1≤n≤100). The second line of each test case contains a string s of 4n characters (si∈{A,B,C,D,?}) — Tim's answers for the questions.

// Output
// For each test case, print a single integer — the maximum score that Tim can achieve.

// Example
// InputCopy
// 6
// 1
// ABCD
// 2
// AAAAAAAA
// 2
// AAAABBBB
// 2
// ????????
// 3
// ABCABCABCABC
// 5
// ACADC??ACAC?DCAABC?C
// OutputCopy
// 4
// 2
// 4
// 0
// 9
// 13

// Note
// In the first test case, there is exactly one question with each answer 'A', 'B', 'C', and 'D'; so it's possible that Tim gets all his answers correct.
// In the second test case, there are only two correct answers 'A' which makes him get exactly 2 points in any case.
// In the third test case, Tim can get at most 2 correct answers with option 'A' and 2 correct answers with option 'B'. For example, he would get 4 points if the answers were 'AACCBBDD'.
// In the fourth test case, he refuses to answer any question at all, which makes him get 0 points.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    unordered_map<char,int> mp;
    for(int i=0; i<4*n; i++)
    {
        mp[s[i]]++;
    }

    int ans = 0;
    
    ans += min(mp['A'], n);
    ans += min(mp['B'], n);
    ans += min(mp['C'], n);
    ans += min(mp['D'], n);

    //ans += min(mp['?'], n);

    cout << ans << endl;

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
