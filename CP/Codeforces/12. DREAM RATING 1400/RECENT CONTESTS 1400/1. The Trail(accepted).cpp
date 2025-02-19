// C. The Trail

// time limit per test2 seconds
// memory limit per test256 megabytes

// There are no mountains in Florida, and Florida Man cannot comprehend their existence. As such, he really needs your help with this one. In the wilderness lies a region of mountainous terrain represented as a rectangular grid with n rows and m columns. Each cell in the grid is identified by its position (i,j), where i is the row index and j is the column index. The altitude of cell (i,j) is denoted by ai,j. However, this region has been tampered with. A path consisting of n+m−1 cells, starting from the top-left corner (1,1) and ending at the bottom-right corner (n,m), has been cleared. For every cell (i,j) along this path, the altitude ai,j has been set to 0. The path moves strictly via downward (D) or rightward (R) steps. To restore the terrain to its original state, it is known that the region possessed a magical property before it was tampered with: all rows and all columns shared the same sum of altitudes. More formally, there exists an integer x such that ∑mj=1ai,j=x for all 1≤i≤n, and ∑ni=1ai,j=x for all 1≤j≤m. Your task is to assign new altitudes to the cells on the path such that the above magical property is restored. It can be proven that a solution always exists. If there are multiple solutions that satisfy the property, any one of them may be provided.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The first line of each test case contains two integers n and m (2≤n,m≤1000) — the number of rows and columns in the grid. The second line of each test case contains a string s of length n+m−2 (si=D or si=R) — the steps the path makes from (1,1) to (n,m). The character D represents a downward step, and R represents a rightward step. The i-th of the next n lines each contain m integers ai,1,ai,2,…,ai,m (−106≤ai,j≤106) — the altitude of each cell in the grid. It is guaranteed that if a cell (i,j) lies on the path, then ai,j=0. It is guaranteed that the sum of n⋅m over all test cases does not exceed 106.

// Output
// For each test case, output n lines of m integers representing the restored grid of altitudes bi,j. The altitudes must satisfy −1015≤bi,j≤1015, and additionally ai,j=bi,j if (i,j) is not on the path. If multiple solutions exist, output any of them.

// Example
// InputCopy
// 4
// 3 3
// DRRD
// 0 2 3
// 0 0 0
// 3 1 0
// 4 5
// DRRRRDD
// 0 1 0 2 3
// 0 0 0 0 0
// -1 0 -3 -3 0
// 0 0 0 -1 0
// 2 3
// RRD
// 0 0 0
// 0 1 0
// 5 5
// DDDDRRRR
// 0 25 2 9 11
// 0 6 13 20 22
// 0 17 24 1 8
// 0 3 10 12 19
// 0 0 0 0 0
// OutputCopy
// 1 2 3
// 2 3 1
// 3 1 2
// -6 1 0 2 3
// 7 -1 3 2 -11
// -1 0 -3 -3 7
// 0 0 0 -1 1
// 0 -1 1
// 0 1 -1
// 18 25 2 9 11
// 4 6 13 20 22
// 15 17 24 1 8
// 21 3 10 12 19
// 7 14 16 23 5

// Note
// In the first test case, the grid has been filled such that every row and column contains the numbers 1,2,3 in some order, resulting in a common sum of 6.
// In the second test case, the grid has been filled such that all rows and columns sum to 0.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<vector<ll int>> a(n, vector<ll int>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> a[i][j];
        }
    }

    int x = 0, y = 0;
    for(auto ch : s)
    {
        if(ch=='D')
        {
            ll int sum = 0;
            for(int i=0; i<m; i++)
            {
                sum += a[x][i];
            }

            a[x][y] = -sum; //Assigning the path cell -ve of sum, to make the total sum 0 of row
            x++; //Going down
        }
        else
        {
            ll int sum = 0;
            for(int i=0; i<n; i++)
            {
                sum += a[i][y];
            }

            a[x][y] = -sum;
            y++; //Going right
        }
    }

    //Iterating the last row
    ll int sum = 0;
    for(int i=0; i<m; i++)
    {
        sum += a[n-1][i];
    }

    //Assigning the last bottom right cell
    a[n-1][m-1] = -sum;

    //Output
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

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
