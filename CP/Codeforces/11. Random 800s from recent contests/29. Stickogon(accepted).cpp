// A. Stickogon

// time limit per test1 second
// memory limit per test256 megabytes

// You are given n sticks of lengths a1,a2,…,an. Find the maximum number of regular (equal-sided) polygons you can construct simultaneously, such that: Each side of a polygon is formed by exactly one stick. No stick is used in more than 1 polygon. Note: Sticks cannot be broken.

// Input
// The first line contains a single integer t (1≤t≤100) — the number of test cases. The first line of each test case contains a single integer n (1≤n≤100) — the number of sticks available. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤100) — the stick lengths.

// Output
// For each test case, output a single integer on a new line — the maximum number of regular (equal-sided) polygons you can make simultaneously from the sticks available.

// Example
// InputCopy
// 4
// 1
// 1
// 2
// 1 1
// 6
// 2 2 3 3 3 3
// 9
// 4 2 2 2 2 4 2 4 4
// OutputCopy
// 0
// 0
// 1
// 2

// Note
// In the first test case, we only have one stick, hence we can't form any polygon.
// In the second test case, the two sticks aren't enough to form a polygon either.
// In the third test case, we can use the 4 sticks of length 3 to create a square.
// In the fourth test case, we can make a pentagon with side length 2, and a square of side length 4.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n), freq(101);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }

    int ans = 0;
    for(int i=0; i<101; i++)
    {
        if(freq[i]>=3)
        {
            ans += freq[i]/3;
        }
    }

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
