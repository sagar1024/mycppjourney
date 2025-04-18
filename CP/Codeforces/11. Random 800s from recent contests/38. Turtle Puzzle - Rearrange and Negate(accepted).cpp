// A. Turtle Puzzle: Rearrange and Negate

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given an array a of n integers. You must perform the following two operations on the array (the first, then the second): Arbitrarily rearrange the elements of the array or leave the order of its elements unchanged. Choose at most one contiguous segment of elements and replace the signs of all elements in this segment with their opposites. Formally, you can choose a pair of indices l,r such that 1≤l≤r≤n and assign ai=−ai for all l≤i≤r (negate elements). Note that you may choose not to select a pair of indices and leave all the signs of the elements unchanged. What is the maximum sum of the array elements after performing these two operations (the first, then the second)?

// Input
// The first line of the input contains a single integer t (1≤t≤1000) — the number of test cases. The descriptions of the test cases follow. The first line of each test case contains a single integer n (1≤n≤50) — the number of elements in array a. The second line of each test case contains n integers a1,a2,…,an (−100≤ai≤100) — elements of the array.

// Output
// For each test case, output the maximum sum of the array elements after sequentially performing the two given operations.

// Example
// InputCopy
// 8
// 3
// -2 3 -3
// 1
// 0
// 2
// 0 1
// 1
// -99
// 4
// 10 -2 -3 7
// 5
// -1 -2 -3 -4 -5
// 6
// -41 22 -69 73 -15 -50
// 12
// 1 2 3 4 5 6 7 8 9 10 11 12
// OutputCopy
// 8
// 0
// 1
// 99
// 22
// 15
// 270
// 78

// Note
// In the first test case, you can first rearrange the array to get [3,−2,−3] (operation 1), then choose l=2,r=3 and get the sum 3+−((−2)+(−3))=8 (operation 2).
// In the second test case, you can do nothing in both operations and get the sum 0.
// In the third test case, you can do nothing in both operations and get the sum 0+1=1.
// In the fourth test case, you can first leave the order unchanged (operation 1), then choose l=1,r=1 and get the sum −(−99)=99 (operation 2).
// In the fifth test case, you can first leave the order unchanged (operation 1), then choose l=2,r=3 and get the sum 10+−((−2)+(−3))+7=22 (operation 2).
// In the sixth test case, you can first leave the order unchanged (operation 1), then choose l=1,r=5 and get the sum −((−1)+(−2)+(−3)+(−4)+(−5))=15 (operation 2).

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    ll int sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        sum += abs(a[i]);
    }

    cout << sum << endl;

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
