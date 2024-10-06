// E. Klee's SUPER DUPER LARGE Array!!!

// time limit per test2 seconds
// memory limit per test256 megabytes

// Klee has an array a of length n containing integers [k,k+1,...,k+n−1] in that order. Klee wants to choose an index i (1≤i≤n) such that x=|a1+a2+⋯+ai−ai+1−⋯−an| is minimized. Note that for an arbitrary integer z, |z| represents the absolute value of z. Output the minimum possible value of x.

// Input
// The first line contains t (1≤t≤104) — the number of test cases. Each test case contains two integers n and k (2≤n,k≤109) — the length of the array and the starting element of the array.

// Output
// For each test case, output the minimum value of x on a new line.

// Example
// InputCopy
// 4
// 2 2
// 7 2
// 5 3
// 1000000000 1000000000
// OutputCopy
// 1
// 5
// 1
// 347369930

// Note
// In the first sample, a=[2,3]. When i=1 is chosen, x=|2−3|=1. It can be shown this is the minimum possible value of x.
// In the third sample, a=[3,4,5,6,7]. When i=3 is chosen, x=|3+4+5−6−7|=1. It can be shown this is the minimum possible value of x.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     ll int n, k;
//     cin >> n >> k;

//     //Answer
//     ll int x = INT_MAX;

//     //Given array
//     vector<ll int> a(n);
//     int sum = 0;
//     for(int i=0; i<n; i++)
//     {
//         a[i] = k+i;
//         sum += a[i];
//     }

//     ll int leftSum = 0;
//     ll int rightSum = sum;
//     for(int i=0; i<n; i++)
//     {
//         leftSum += a[i];
//         rightSum -= a[i];
//         x = min(x,abs(leftSum-rightSum));
//     }

//     cout << x << endl;
//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;
#define ll long long

void solve()
{
    ll n, k;
    cin >> n >> k;

    //Total sum of the array elements
    ll sum = (n * k) + (n * (n - 1)) / 2; //Sum of arithmetic series

    ll leftSum = 0;
    ll rightSum = sum;

    //Initializing with a large value
    ll minX = numeric_limits<ll>::max();

    for (ll i = 0; i < n; i++)
    {
        ll currentElement = k + i;
        leftSum += currentElement;
        rightSum -= currentElement;
        minX = min(minX, abs(leftSum - rightSum));
    }

    cout << minX << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
