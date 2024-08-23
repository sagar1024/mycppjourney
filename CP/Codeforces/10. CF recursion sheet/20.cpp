// T. Combination

// time limit per test2 seconds
// memory limit per test64 megabytes

// Given two numbers N and R. Print the NCR value. Note: Solve this problem using recursion.

// Input
// Only one line contains two numbers N and R (0 ≤ N, R ≤ 30).

// Output
// Print the NCR value.

// Examples
// InputCopy
// 4 2
// OutputCopy
// 6
// InputCopy
// 3 3
// OutputCopy
// 1

// Note
// For more information visit combination:

// My original soln(wrong on tc4) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve(int n, int r, int &comb)
// {
//     if(r==0)
//     {
//         return;
//     }
//     solve(n-1,r-1,comb);
//     comb *= n;
// }

// int32_t main()
// {
//     int n, r;
//     cin >> n >> r;

//     int r_fact = 1;
//     for(int i=1; i<=r; i++)
//     {
//         r_fact *= i;
//     }

//     int possible_comb = 1;
//     solve(n,r,possible_comb);

//     int ans = possible_comb/r_fact;
//     cout << ans << endl;

//     return 0;
// }

// Alternate soln(tle on tc32) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// int nCr(int n, int r)
// {
//     if (r == 0 || r == n)
//     {
//         return 1;
//     }
//     return nCr(n - 1, r - 1) + nCr(n - 1, r);
// }

// int main()
// {
//     int n, r;
//     cin >> n >> r;

//     int result = nCr(n, r);
//     cout << result << endl;

//     return 0;
// }

// Alternate soln(runtime error on tc32) -

// #include <iostream>
// #include <vector>

// using namespace std;

// int nCr(int n, int r, vector<vector<int>> &memo)
// {
//     if (r == 0 || r == n)
//     {
//         return 1;
//     }
//     if (memo[n][r] != -1)
//     {
//         return memo[n][r];
//     }
//     memo[n][r] = nCr(n - 1, r - 1, memo) + nCr(n - 1, r, memo);
//     return memo[n][r];
// }

// int main()
// {
//     int n, r;
//     cin >> n >> r;

//     vector<vector<int>> memo(n + 1, vector<int>(r + 1, -1));
//     int result = nCr(n, r, memo);

//     cout << result << endl;
//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     int n, r;
//     cin >> n >> r;

//     int x = 1;
//     for(int i=n; i>n-r; i--)
//     {
//         x *= i;
//     }

//     int y = 1;
//     for(int i=r; i>=1; i--)
//     {
//         y *= i;
//     }

//     int ans = x/y;
//     cout << ans << endl;

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int nCr(int n, int r)
{
    if (r == 0 || r == n)
    {
        return 1;
    }
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
    int n, r;
    cin >> n >> r;

    int result = nCr(n, r);
    cout << result << endl;

    return 0;
}
