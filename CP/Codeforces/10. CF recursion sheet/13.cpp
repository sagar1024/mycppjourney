// M. Suffix Sum

// time limit per test1 second
// memory limit per test256 megabytes

// Given two numbers N and M, and an array A of N numbers. Calculate the sum of the last M numbers. Note: solve this problem using recursion.

// Input
// First line contains two numbers N and M (1≤M≤N≤105). Second line contains N numbers (−109≤Ai≤109).

// Output
// Print the sum of the last M numbers of the given array.

// Example
// InputCopy
// 5 3
// 1 8 2 10 3

// OutputCopy
// 15

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void calculate(vector<ll int>&a, int n, int m, ll int &ans)
{
    if(m==0)
    {
        return;
    }

    calculate(a,n-1,m-1,ans);
    ans += a[n];

    return;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;

    vector<ll int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll int ans = 0;
    calculate(a,n-1,m,ans);

    cout << ans << endl;
    return 0;
}
