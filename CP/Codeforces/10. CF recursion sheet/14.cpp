// N. Sum of a Matrix

// time limit per test1 second
// memory limit per test256 megabytes

// Given two matrices A and B of size R * C. Print the summation of A and B. Note: Solve this problem using recursion.

// Input
// First line contains two numbers R and C (1 ≤ R, C ≤ 100). number of rows and number of columns respectively. Next R lines will contain C numbers ( - 100 ≤ Ai, j ≤ 100) matrix A numbers. Next R lines will contain C numbers ( - 100 ≤ Bi, j ≤ 100) matrix B numbers.

// Output
// Print the summation result.

// Example
// InputCopy
// 2 3
// 1 2 3
// 4 5 6
// 1 3 5
// 7 9 11
// OutputCopy
// 2 5 8
// 11 14 17

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void sumMatrices(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& result, int i, int j, int R, int C)
{
    if(i>=R) return;
    if(j>=C)
    {
        //New row, column = 0
        sumMatrices(A,B,result,i+1,0,R,C);
        return;
    }

    result[i][j] = A[i][j]+B[i][j];
    sumMatrices(A,B,result,i,j+1,R,C);

    return;
}

int main()
{
    int R, C;
    cin >> R >> C;

    vector<vector<int>> A(R, vector<int>(C));
    vector<vector<int>> B(R, vector<int>(C));
    vector<vector<int>> result(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> B[i][j];
        }
    }

    //MAIN logic
    sumMatrices(A, B, result, 0, 0, R, C);

    //Output
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
