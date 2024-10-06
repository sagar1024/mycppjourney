// Z. Left Max

// time limit per test1 second
// memory limit per test256 megabytes

// Given a number N and an array A of N numbers, print the maximum in the range from 1 to i for each i≤N. Note: Solve this problem using recursion.

// Input
// First line contains a number N (1≤N≤105) number of elements. Second line contains N numbers (−109≤Ai≤109).

// Output
// Print N numbers, the maximum from index 1 to index i.

// Example
// InputCopy
// 5
// 4 3 5 7 3

// OutputCopy
// 4 4 5 7 7

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(int iterator, int n, vector<ll int> &a, ll int currMax)
{
    if(iterator==n-1)
    {
        currMax = max(a[iterator],currMax);
        cout << currMax << endl;

        return;
    }

    currMax = max(a[iterator], currMax);
    cout << currMax << " ";

    return solve(iterator+1, n, a, currMax);
}

int32_t main()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    solve(0,n,a,INT_MIN);

    return 0;
}
