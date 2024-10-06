// V. Creating Expression1

// time limit per test1 second
// memory limit per test256 megabytes

// Given two numbers N, X and an array A of N numbers. Determine if there is a way to put '+' or '-' signs between every two numbers in the array A in order to make an expression that is equal to X. Note: Solve this problem using recursion.

// Input
// First line contains two numbers N and X (1≤N≤20,−109≤X≤109). Second line contains N distinct numbers A1,A2,....AN (1≤Ai≤105).

// Output
// Print "YES" if you can put '+' or '-' signs between every two number to create an expression that is equal to X otherwise, print "NO".

// Examples
// InputCopy
// 5 5
// 1 2 3 4 5
// OutputCopy
// YES
// InputCopy
// 5 2
// 1 2 3 4 5
// OutputCopy
// NO

// Note
// In the first example: 1 - 2 - 3 + 4 + 5 = 5

//My original soln(wrong on tc 103) -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(ll int n, ll int x, vector<int>&a, ll int sum)
{
    if(n==0)
    {
        return sum==x;
    }
    return solve(n-1,x,a,sum+a[n-1]) || solve(n-1,x,a,sum-a[n-1]);
}

int32_t main()
{
    ll int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    //ll int sum = 0;
    bool ans = solve(n,x,a,0);

    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
