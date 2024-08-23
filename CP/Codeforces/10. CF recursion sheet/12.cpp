// L. Summation

// time limit per test1 second
// memory limit per test256 megabytes

// Given a number N and an array A of N numbers. Print the summation of the array elements. Note: Solve this problem using recursion.

// Input
// First line contains a number N (1 ≤ N ≤ 103) number of elements. Second line contains N numbers ( - 109 ≤ Ai ≤ 109).

// Output
// Print the summation of the N numbers.

// Examples
// InputCopy
// 4
// 1 4 2 7
// OutputCopy
// 14
// InputCopy
// 4
// 5 5 5 5
// OutputCopy
// 20

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(vector<long long int> &a, int n, long long int &sum)
{
    //Base case
    if(n<0)
    {
        return;
    }

    solve(a,n-1,sum);
    sum += a[n];

    return;
}

int32_t main()
{
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    long long int sum = 0;
    solve(a,n-1,sum);

    cout << sum << endl;
    return 0;
}
