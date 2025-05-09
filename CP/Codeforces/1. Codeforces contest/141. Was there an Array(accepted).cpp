// A. Was there an Array?

// time limit per test2 seconds
// memory limit per test512 megabytes

// For an array of integers a1,a2,…,an, we define its equality characteristic as the array b2,b3,…,bn−1, where bi=1 if the i-th element of the array a is equal to both of its neighbors, and bi=0 if the i-th element of the array a is not equal to at least one of its neighbors. For example, for the array [1,2,2,2,3,3,4,4,4,4], the equality characteristic will be [0,1,0,0,0,0,1,1]. You are given the array b2,b3,…,bn−1. Your task is to determine whether there exists such an array a for which the given array is the equality characteristic.

// Input
// The first line contains one integer t (1≤t≤1000) — the number of test cases. Each test case consists of two lines: the first line contains one integer n (3≤n≤100); the second line contains n−2 integers b2,b3,…,bn−1 (0≤bi≤1).

// Output
// For each test case, output YES if the array a exists, or NO if such an array does not exist. Each letter can be printed in any case.

// Example
// InputCopy
// 3
// 10
// 0 1 0 0 0 0 1 1
// 3
// 1
// 10
// 0 1 0 1 1 0 0 1
// OutputCopy
// YES
// YES
// NO

// Note
// In the first example, the array a=[1,2,2,2,3,3,4,4,4,4] is suitable.
// In the second example, the array a=[7,7,7] is suitable.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> b(n-2);
    for(int i=0; i<n-2; i++)
    {
        cin >> b[i];
    }

    bool yes = true;
    for(int i=1; i<n-3; i++)
    {
        if(b[i-1]!=b[i] && b[i]!=b[i+1] && b[i]==0)
        {
            yes &= false;
        }
    }

    if(yes) cout << "YES" << endl;
    else cout << "NO" << endl;

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
