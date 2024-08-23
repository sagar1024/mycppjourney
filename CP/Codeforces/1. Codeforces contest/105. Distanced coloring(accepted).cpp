// A. Distanced Coloring

// time limit per test1 second
// memory limit per test256 megabytes

// You received an n×m grid from a mysterious source. The source also gave you a magic positive integer constant k. The source told you to color the grid with some colors, satisfying the following condition: If (x1,y1), (x2,y2) are two distinct cells with the same color, then max(|x1−x2|,|y1−y2|)≥k. You don't like using too many colors. Please find the minimum number of colors needed to color the grid.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). The description of the test cases follows. The only line of each test case consists of three positive integers n, m, k (1≤n,m,k≤104) — the dimensions of the grid and the magic constant.

// Output
// For each test case, print a single integer — the minimum number of colors needed to color the grid.

// Example
// InputCopy
// 6
// 3 3 2
// 5 1 10000
// 7 3 4
// 3 2 7
// 8 9 6
// 2 5 4
// OutputCopy
// 4
// 5
// 12
// 6
// 36
// 8

// Note
// In the first test case, one of the optimal constructions is:
// In the second test case, the color of all cells must be pairwise different, so the answer is 5.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n, m, k;
//     cin >> n >> m >> k;

//     if(n<=k && m<=k)
//     {
//         cout << n*m << endl;
//     }
//     else if(n>k && m>k)
//     {
//         if(n/k>1 && m/k>1)
//         {
//             int colors_needed = ((n+k-1)/k) * ((m+k-1)/k);
//             cout << colors_needed << endl;
//         }
//         else if((n/k>1 && m/k<=1) || (n/k<=1 && m/k>1))
//         {
//             if(n/k>1 && m/k<=1)
//             {
//                 int colors_needed = ((n+k-1)/k) * min(m,k);
//                 cout << colors_needed << endl;
//             }
//             else if(n/k<=1 && m/k>1)
//             {
//                 int colors_needed = min(n,k) * ((m+k-1)/k);
//                 cout << colors_needed << endl;
//             }
//         }
//         else if(n/k<=1 && m/k<=1)
//         {
//             cout << k*k << endl;
//         }
//     }
//     else if((n<=k && m>=k) || (n>=k && m<=k))
//     {
//         if(n<=k && m>=k)
//         {
//             if(m/k<=1)
//             {
//                 cout << n*k << endl;
//             }
//             else
//             {
//                 int colors_needed = n * ((m+k-1)/k);
//                 cout << colors_needed << endl;
//             }
//         }
//         else if(n>=k && m<=k)
//         {
//             if(n/k<=1)
//             {
//                 cout << m*k << endl;
//             }
//             else
//             {
//                 int colors_needed = ((n+k-1)/k) * m;
//                 cout << colors_needed << endl;
//             }
//         }
//     }

//     return;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln(mle on tc3) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int solve(int n, int m, int k)
// {
//     vector<vector<int>> grid(n, vector<int>(m, 0));
//     int color = 0;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             if (grid[i][j] == 0)
//             {
//                 color++;
//                 for (int x = 0; x < n; x++){
//                     for (int y = 0; y < m; y++){
//                         if (max(abs(x - i), abs(y - j)) % k == 0)
//                         {
//                             grid[x][y] = color;
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     return color;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m, k;
//         cin >> n >> m >> k;
//         cout << solve(n, m, k) << endl;
//     }

//     return 0;
// }

//Correct soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    cout << min(n,k)*min(m,k) << endl;
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
