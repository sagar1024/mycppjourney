// A. Zhan's Blender

// time limit per test1 second
// memory limit per test256 megabytes

// Today, a club fair was held at "NSPhM". In order to advertise his pastry club, Zhan decided to demonstrate the power of his blender. To demonstrate the power of his blender, Zhan has n fruits. The blender can mix up to x fruits per second. In each second, Zhan can put up to y fruits into the blender. After that, the blender will blend min(x,c) fruits, where c is the number of fruits inside the blender. After blending, blended fruits are removed from the blender. Help Zhan determine the minimum amount of time required for Zhan to blend all fruits.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). The description of the test cases follows. The first line of each test case contains one integer n (0≤n≤109) — the number of fruits Zhan has. The second line of each test case contains two integers x and y (1≤x,y≤109) — the number of fruits the blender can blend per second and the number of fruits Zhan can put into the blender per second.

// Output
// For each testcase, output a single integer — the minimum number of seconds to blend all fruits.

// Example
// InputCopy
// 5
// 5
// 3 4
// 3
// 1 2
// 6
// 4 3
// 100
// 4 3
// 9
// 3 3
// OutputCopy
// 2
// 3
// 2
// 34
// 3

// Note
// In the first example, you can first put 2 fruits in the blender. After that, the blender will mix these 2 fruits, and in the end, there will be 0 fruits left in the blender. Then you can put 3 fruits into the blender, after which the blender will mix these 3 fruits.
// In the second example, you can put 1 fruit into the blender 3 times.
// In the third example, you can first put 3 fruits into the blender, then add another 3 fruits.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     ll int n, x, y;
//     cin >> n >> x >> y;

//     ll int ans = ceil((float)n/min(x,y));
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

// Alternate soln -

#include <iostream>
#include <cmath>

using namespace std;
#define ll long long

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;

    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }

    ll low = 1, high = (n + y - 1) / y;
    while (low < high)
    {
        ll mid = (low + high) / 2;
        if (mid * x >= n)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << low << endl;
    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
