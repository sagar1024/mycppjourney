// Q. 3n + 1 sequence

// time limit per test1 second
// memory limit per test256 megabytes

// Given a number n, you should print the length of the 3n+1 sequence starting with n. The sequence is constructed as follows: If the number n is odd, the next number will be 3n+1. If the number n is even, the next number will be n/2. For example, the 3n+1 sequence of 3 is {3,10,5,16,8,4,2,1} and its length is 8. Note: Solve this problem using recursion.

// Input
// Only one line containing a number n (1≤n≤105).

// Output
// Print the length of 3n+1 sequence of the given n.

// Examples
// InputCopy
// 1
// OutputCopy
// 1
// InputCopy
// 2
// OutputCopy
// 2
// InputCopy
// 3
// OutputCopy
// 8

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(int n, int &ans)
{
    if(n==1)
    {
        return;
    }
    if(n%2!=0)
    {
        solve(3*n+1,ans);
    }
    else if(n%2==0)
    {
        solve(n/2,ans);
    }
    ans++;
    return;
}

int32_t main()
{
    int n;
    cin >> n;

    int ans = 1;
    solve(n,ans);

    cout << ans << endl;
    return 0;
}
