// W. Reach Value

// time limit per test1 second
// memory limit per test256 megabytes

// Given a number N. Initially you have a value equal 1 and you can perform one of the following operation any number of times: Multiply your current value by 10. Multiply your current value by 20. Determine if your value can reach N or not. Note: Solve this problem using recursion.

// Input
// First line contains a number T (1≤T≤100) number of test cases. Next T lines will contain a number N (1≤N≤1012).

// Output
// For each test case print "YES" if your value can reach exactly N otherwise, print "NO".

// Example
// InputCopy
// 5
// 1
// 2
// 10
// 25
// 200

// OutputCopy
// YES
// NO
// YES
// NO
// YES

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool check(ll int n, ll int currNumber)
{
    if(currNumber==n)
    {
        return true;
    }
    if(currNumber>n)
    {
        return false;
    }
    
    return check(n,currNumber*10) || check(n,currNumber*20);
}

void solve()
{
    ll int n;
    cin >> n;

    //ll int curr = 1;
    bool ans = check(n,1);

    if(ans) cout << "YES" << endl;
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
