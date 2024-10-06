// B. Blank Space

// time limit per test1 second
// memory limit per test256 megabytes

// You are given a binary array a of n elements, a binary array is an array consisting only of 0s and 1s. A blank space is a segment of consecutive elements consisting of only 0s. Your task is to find the length of the longest blank space.

// Input
// The first line contains a single integer t (1≤t≤1000) — the number of test cases. The first line of each test case contains a single integer n (1≤n≤100) — the length of the array. The second line of each test case contains n space-separated integers ai (0≤ai≤1) — the elements of the array.

// Output
// For each test case, output a single integer — the length of the longest blank space.

// Example
// InputCopy
// 5
// 5
// 1 0 0 1 0
// 4
// 0 1 1 1
// 1
// 0
// 3
// 1 1 1
// 9
// 1 0 0 0 1 0 0 0 1
// OutputCopy
// 2
// 1
// 1
// 0
// 3

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll int ans = 0;
    ll int curr = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i]==0)
        {
            curr += 1;
        }
        else
        {
            curr = 0;
        }

        ans = max(ans,curr);
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
