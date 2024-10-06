// X. The maximum path-sum

// time limit per test1 second
// memory limit per test256 megabytes

// Given a matrix A of size N*M. Print the maximum sum of numbers that can be obtained when you take a path from A1,1 to AN,M. If you stay in Ai,j you can only go to :
// Ai+1,j if and only if i≤N
// Ai,j+1 if and only if j≤M

// Note: Solve this problem using recursion.

// Input
// First line contains two numbers N and M (1≤N,M≤10) N donates number of rows and M donates number of columns. Next N lines each of them will contain M numbers (−105≤Ai,j≤105).

// Output
// Print the maximum sum of numbers can be obtained.

// Example
// InputCopy
// 3 3
// 5 2 4
// 1 3 5
// 9 2 7
// OutputCopy
// 24

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// int solve(int n, int m, vector<vector<int>> a, int row, int col, int sum)
// {
//     if(row==n && col==m)
//     {
//         return sum;
//     }

//     sum += max(solve(n-1,m,a,row+1,col,sum),solve(n,m-1,a,row,col+1,sum));
//     return sum;
// }

// int32_t main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> a(n, vector<int>(m));
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<m; j++)
//         {
//             cin >> a[i][j];
//         }
//     }

//     //Max sum of numbers in a path
//     int ans = solve(n,m,a,0,0,0);

//     cout << ans << endl;

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// //Recursive function to calculate maximum path sum
// int solve(int n, int m, vector<vector<int>> &a, int row, int col, vector<vector<int>> &dp)
// {
//     if (row == n - 1 && col == m - 1)
//     {
//         return a[row][col]; //Base case: bottom-right corner
//     }
//     if (dp[row][col] != -1)
//     {
//         return dp[row][col]; //Returning already computed value
//     }

//     int sumDown = 0, sumRight = 0;
//     if (row < n - 1)
//     {
//         sumDown = solve(n, m, a, row + 1, col, dp);
//     }
//     if (col < m - 1)
//     {
//         sumRight = solve(n, m, a, row, col + 1, dp);
//     }

//     //Adding current cell value to the maximum sum from moving either down or right
//     dp[row][col] = a[row][col] + max(sumDown, sumRight);

//     return dp[row][col];
// }

// int32_t main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> a(n, vector<int>(m));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> a[i][j];
//         }
//     }

//     //Initializing dp array with -1(indicating uncomputed)
//     vector<vector<int>> dp(n, vector<int>(m, -1));

//     //Computing the maximum sum starting from top-left corner(0, 0)
//     int ans = solve(n, m, a, 0, 0, dp);
//     cout << ans << endl;

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, vector<vector<int>> &a, int row, int col)
{
    //Base case: reached the bottom-right corner
    if (row == n - 1 && col == m - 1)
    {
        return a[row][col];
    }

    //If we're at the bottom row, we can only move right
    if (row == n - 1)
    {
        return a[row][col] + solve(n, m, a, row, col + 1);
    }

    //If we're at the rightmost column, we can only move down
    if (col == m - 1)
    {
        return a[row][col] + solve(n, m, a, row + 1, col);
    }

    //Otherwise, we can move either right or down
    int moveRight = solve(n, m, a, row, col + 1);
    int moveDown = solve(n, m, a, row + 1, col);

    //Returning the current cell's value plus the maximum of moving right or down
    return a[row][col] + max(moveRight, moveDown);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int ans = solve(n, m, a, 0, 0);
    cout << ans << endl;

    return 0;
}
