// P. Log2

// time limit per test1 second
// memory limit per test256 megabytes

// Given a number N. Print ⌊log2(N)⌋. Note: Solve this problem using recursion.

// Input
// Only one line containing a number N (1≤N≤1018).

// Output
// Print the answer required above.

// Examples
// InputCopy
// 1
// OutputCopy
// 0
// InputCopy
// 8
// OutputCopy
// 3

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(ll int n, ll int &ans)
{
    if(n==1)
    {
        return;
    }
    solve(n/2,ans);
    ans++;
}

int32_t main()
{
    ll int n;
    cin >> n;

    ll int ans = 0;
    solve(n,ans);

    cout << ans << endl;

    return 0;
}
