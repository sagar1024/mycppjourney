// B. Set of Strangers

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given a table of n rows and m columns. Initially, the cell at the i-th row and the j-th column has color ai,j. Let's say that two cells are strangers if they don't share a side. Strangers are allowed to touch with corners. Let's say that the set of cells is a set of strangers if all pairs of cells in the set are strangers. Sets with no more than one cell are sets of strangers by definition. In one step, you can choose any set of strangers such that all cells in it have the same color and paint all of them in some other color. You can choose the resulting color. What is the minimum number of steps you need to make the whole table the same color?

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. Next, t cases follow. The first line of each test case contains two integers n and m (1≤n≤m≤700) — the number of rows and columns in the table. The next n lines contain the colors of cells in the corresponding row ai,1,…,ai,m (1≤ai,j≤nm). It's guaranteed that the total sum of nm doesn't exceed 5⋅105 over all test cases.

// Output
// For each test case, print one integer — the minimum number of steps to paint all cells of the table the same color.

// Example
// InputCopy
// 4
// 1 1
// 1
// 3 3
// 1 2 1
// 2 3 2
// 1 3 1
// 1 6
// 5 4 5 4 4 5
// 3 4
// 1 4 2 2
// 1 4 3 5
// 6 6 3 5
// OutputCopy
// 0
// 2
// 1
// 10

// Note
// In the first test case, the table is painted in one color from the start.
// In the second test case, you can, for example, choose all cells with color 1 and paint them in 3. Then choose all cells with color 2 and also paint them in 3.
// In the third test case, you can choose all cells with color 5 and paint them in color 4.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<int> hasColor(n * m, 0); //Keeping track of encountered colors to add them up later, add the extra ops required for colors sharing a side
    vector<int> hasBad(n * m, 0); //This color has neighbour cell with same color, would need 2 ops to fully change color
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    //We gotta take the entire input first and then only we can check the neighbour cells
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            hasColor[a[i][j] - 1] = 1;

            //Checking if the neighbour cells are of same color
            if (i + 1 < n && a[i][j] == a[i + 1][j])
            {
                hasBad[a[i][j] - 1] = 1;
            }
            if (j + 1 < m && a[i][j] == a[i][j + 1])
            {
                hasBad[a[i][j] - 1] = 1;
            }
        }
    }

    int sumColor = 0, sumBad = 0, maxBad = 0;
    for (int i = 0; i < n * m; i++)
    {
        sumColor += hasColor[i];
        sumBad += hasBad[i];
        maxBad = max(maxBad, hasBad[i]);
    }

    cout << (sumColor + sumBad - 1 - maxBad) << endl;

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
