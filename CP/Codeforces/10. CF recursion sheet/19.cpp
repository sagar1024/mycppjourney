// S. Array Average

// time limit per test1 second
// memory limit per test256 megabytes

// Given a number N and an array A of N numbers. Calculate the average of these numbers. Note: solve this problem using recursion.

// Input
// First line contains a number N (1≤N≤100) number of elements. Second line contains N numbers (−109≤Ai≤109).

// Output
// Print the calculated average, with 6 digits after the decimal point.

// Example
// InputCopy
// 5
// 1 2 3 4 5

// OutputCopy
// 3.000000

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

double solve(vector<ll int> &a, int n)
{
    if(n==1)
    {
        return a[0];
    }

    double currAvg = solve(a,n-1);
    double avg = (currAvg*(n-1) + a[n-1])/n;

    return avg;
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

    double ans = solve(a,n);
    //cout << ans << endl;
    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}
