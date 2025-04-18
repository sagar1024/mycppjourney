// B1. Reverse Card (Easy Version)

// time limit per test2 seconds
// memory limit per test256 megabytes

// The two versions are different problems. You may want to read both versions. You can make hacks only if both versions are solved. You are given two positive integers n, m. Calculate the number of ordered pairs (a,b) satisfying the following conditions:
// 1≤a≤n, 1≤b≤m;
// a+b is a multiple of b⋅gcd(a,b).

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The first line of each test case contains two integers n, m (1≤n,m≤2⋅106). It is guaranteed that neither the sum of n nor the sum of m over all test cases exceeds 2⋅106.

// Output
// For each test case, print a single integer: the number of valid pairs.

// Example
// InputCopy
// 6
// 1 1
// 2 3
// 3 5
// 10 8
// 100 1233
// 1000000 1145141
// OutputCopy
// 1
// 3
// 4
// 14
// 153
// 1643498

// Note
// In the first test case, only (1,1) satisfies the conditions.
// In the fourth test case, (1,1),(2,1),(2,2),(3,1),(4,1),(5,1),(6,1),(6,2),(6,3),(7,1),(8,1),(9,1),(10,1),(10,2) satisfy the conditions.

// #include <iostream>
// #include <bits/stdc++.h>

// #define int long long
// using namespace std;

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     int ans = 0;
//     for(int a=1; a<=n; a++)
//     {
//         for(int b=1; b<=m; b++)
//         {
//             int x = a + b;
//             int y = b * __gcd(a,b);
//             if(x%y==0)
//             {
//                 ans++;
//             }
//         }
//     }

//     cout << ans << endl;
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

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for(int i=1; i<=m; i++) ans += (n+i)/(1ll*i*i);

    cout << ans-1 << endl;
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
