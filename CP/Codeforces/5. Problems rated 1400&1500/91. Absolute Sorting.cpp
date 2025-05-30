// D. Absolute Sorting

// time limit per test2 seconds
// memory limit per test512 megabytes

// You are given an array a consisting of n integers. The array is sorted if a1≤a2≤⋯≤an. You want to make the array a sorted by applying the following operation exactly once: choose an integer x, then for every i∈[1,n], replace ai by |ai−x|. Find any value of x that will make the array sorted, or report that there is no such value.

// Input
// The first line contains one integer t (1≤t≤2⋅104) — the number of test cases. Each test case consists of two lines. The first line contains one integer n (2≤n≤2⋅105). The second line contains n integers a1,a2,…,an (1≤ai≤108). Additional constraint on the input: the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print any integer x (0≤x≤109) that makes the array sorted. It can be shown that if such an integer x exists, there is at least one such integer between 0 and 109. If there is no such integer, then print −1. If there are multiple suitable values of x, print any of them.

// Example
// InputCopy
// 8
// 5
// 5 3 3 3 5
// 4
// 5 3 4 5
// 8
// 1 2 3 4 5 6 7 8
// 6
// 10 5 4 3 2 1
// 3
// 3 3 1
// 3
// 42 43 42
// 2
// 100000000 99999999
// 6
// 29613295 52036613 75100585 78027446 81409090 73215
// OutputCopy
// 4
// -1
// 0
// 42
// 2
// -1
// 100000000
// 40741153

// Note
// In the first test case, after using x=4, the array becomes [1,1,1,1,1].
// In the third test case, after using x=0, the array becomes [1,2,3,4,5,6,7,8].
// In the fourth test case, after using x=42, the array becomes [32,37,38,39,40,41].

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    //God, save me.

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
