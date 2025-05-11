// C. Wonderful City

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are the proud leader of a city in Ancient Berland. There are n2 buildings arranged in a grid of n rows and n columns. The height of the building in row i and column j is hi,j. The city is beautiful if no two adjacent by side buildings have the same height. In other words, it must satisfy the following: There does not exist a position (i,j) (1≤i≤n, 1≤j≤n−1) such that hi,j=hi,j+1. There does not exist a position (i,j) (1≤i≤n−1, 1≤j≤n) such that hi,j=hi+1,j. There are n workers at company A, and n workers at company B. Each worker can be hired at most once. It costs ai coins to hire worker i at company A. After hiring, worker i will: Increase the heights of all buildings in row i by 1. In other words, increase hi,1,hi,2,…,hi,n by 1. It costs bj coins to hire worker j at company B. After hiring, worker j will:
// Increase the heights of all buildings in column j by 1. In other words, increase h1,j,h2,j,…,hn,j by 1. Find the minimum number of coins needed to make the city beautiful, or report that it is impossible.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). The description of the test cases follows. The first line of each test case contains a single integer n (2≤n≤1000) — the size of the grid. The i-th of the next n lines of each test case contains n integers hi,1,hi,2,…,hi,n (1≤hi,j≤109) — the heights of the buildings in row i. The next line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the costs of hiring the workers at company A. The next line of each test case contains n integers b1,b2,…,bn (1≤bj≤109) — the costs of hiring the workers at company B. It is guaranteed that the sum of n over all test cases does not exceed 1000.

// Output
// For each test case, output a single integer — the minimum number of coins needed, or −1 if it is impossible.

// Example
// InputCopy
// 4
// 2
// 1 2
// 2 1
// 100 100
// 100 100
// 4
// 1 2 1 2
// 3 2 1 2
// 1 2 1 1
// 1 3 1 2
// 1 2 3 4
// 5 6 7 8
// 3
// 1 2 2
// 2 2 1
// 2 1 1
// 100 100 100
// 100 100 100
// 6
// 8 7 2 8 4 8
// 7 7 9 7 1 1
// 8 3 1 1 8 5
// 6 8 3 1 1 4
// 1 4 5 1 9 6
// 7 1 1 6 8 2
// 11 23 20 79 30 15
// 15 83 73 57 34 63
// OutputCopy
// 0
// 14
// -1
// 183

// Note
// For the first test case, we can see that the city is already beautiful. Thus, the answer is 0.
// For the second test case, we can hire worker 2 from company A, worker 4 from company A, and worker 4 from company B:
// The cost of hiring the workers is 2+4+8=14. This is the minimum possible cost.
// For the third test case, no matter what we do, it is impossible to make the city beautiful. Thus, the answer is −1.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const long long INF = 1e18;

long long solveHor(int n, vector<vector<int>> &h, vector<int> &a)
{
    vector<vector<long long>> dp(n, vector<long long>(2, INF));
    dp[0][0] = 0;
    dp[0][1] = a[0];

    for (int i = 1; i < n; i++)
    {
        for (int x = 0; x < 2; x++)
        {
            for (int y = 0; y < 2; y++)
            {
                bool ok = true;
                for (int j = 0; j < n; j++)
                {
                    ok &= (h[i - 1][j] + y != h[i][j] + x);
                }
                if (ok)
                {
                    if (x == 0)
                    {
                        dp[i][x] = min(dp[i][x], dp[i - 1][y]);
                    }
                    if (x == 1)
                    {
                        dp[i][x] = min(dp[i][x], dp[i - 1][y] + a[i]);
                    }
                }
            }
        }
    }

    return min(dp[n - 1][0], dp[n - 1][1]);
}

void transpose(int n, vector<vector<int>> &h)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(h[i][j], h[j][i]);
        }
    }
}

void test()
{
    int n;
    cin >> n;

    vector<vector<int>> h(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> h[i][j];
        }
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    long long horCost = solveHor(n, h, a);
    transpose(n, h);
    long long verCost = solveHor(n, h, b);
    long long totalCost = horCost + verCost;

    if (totalCost >= INF)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << totalCost << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        test();
    }

    return 0;
}
