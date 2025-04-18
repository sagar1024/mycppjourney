// F. Trulimero Trulicina

// time limit per test2 seconds
// memory limit per test256 megabytes

// Trulicina gives you integers n, m, and k. It is guaranteed that k≥2 and n⋅m≡0(modk). Output a n by m grid of integers such that each of the following criteria hold: Each integer in the grid is between 1 and k, inclusive. Each integer from 1 to k appears an equal number of times. No two cells that share an edge have the same integer. It can be shown that such a grid always exists. If there are multiple solutions, output any.

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases. The first line of each test case contains three integers n, m, and k (2≤n⋅m≤2⋅105,2≤k≤n⋅m,n⋅m≡0(modk)). It is guaranteed that the sum of n⋅m over all test cases does not exceed 2⋅105.

// Output
// For each test case, output n lines, each containing m integers that satisfy the criteria. If there are multiple solutions, output any.

// Example
// InputCopy
// 3
// 2 2 2
// 3 4 6
// 5 5 25
// OutputCopy
// 1 2
// 2 1
// 1 6 1 6
// 2 5 2 5
// 3 4 3 4
// 17 2 12 25 14
// 3 1 6 19 11
// 8 20 23 24 4
// 9 10 5 13 21
// 22 7 15 18 16

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int total_cells = n * m;
    int freq = total_cells / k;

    vector<int> count(k + 1, freq);

    vector<vector<int>> grid(n, vector<int>(m, 0));
    queue<int> black_nums, white_nums;
    for (int i = 1; i <= k; ++i)
    {
        if (i % 2 == 0) black_nums.push(i);
        else white_nums.push(i);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            bool is_black = (i + j) % 2 == 0;

            int num = 0;
            if (is_black)
            {
                while (!black_nums.empty())
                {
                    int candidate = black_nums.front();
                    if (count[candidate] > 0)
                    {
                        num = candidate;
                        count[candidate]--;
                        
                        if (count[candidate] == 0) black_nums.pop();

                        break;
                    }
                    else
                    {
                        black_nums.pop();
                    }
                }
            }
            else
            {
                while (!white_nums.empty())
                {
                    int candidate = white_nums.front();
                    if (count[candidate] > 0)
                    {
                        num = candidate;
                        count[candidate]--;

                        if (count[candidate] == 0) white_nums.pop();

                        break;
                    }
                    else
                    {
                        white_nums.pop();
                    }
                }
            }

            grid[i][j] = num;
        }
    }

    for (const auto &row : grid)
    {
        for (int val : row) cout << val << ' ';
        cout << endl;
    }

    return;
}

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        solve();
    }

    return 0;
}
