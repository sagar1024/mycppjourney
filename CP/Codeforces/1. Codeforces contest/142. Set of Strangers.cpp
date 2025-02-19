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

    vector<vector<int>> grid(n, vector<int>(m));
    unordered_map<int, int> colorCountEven, colorCountOdd, freq;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            if ((i + j) % 2 == 0)
                colorCountEven[grid[i][j]]++;
            else
                colorCountOdd[grid[i][j]]++;

            freq[grid[i][j]]++;
        }
    }

    // Special case: 1D array (either n == 1 or m == 1)
    if (n == 1 || m == 1)
    {
        //Flattening the array
        vector<int> arr;
        if (n == 1)
        {
            for (int j = 0; j < m; ++j)
            {
                arr.push_back(grid[0][j]);
            }
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                arr.push_back(grid[i][0]);
            }
        }

        unordered_map<int, int> freq1, freq2;
        int len = arr.size();

        //Group elements into two sets based on non-adjacent positions
        for (int i = 0; i < len; i += 2)
        {
            freq1[arr[i]]++;
        }
        for (int i = 1; i < len; i += 2)
        {
            freq2[arr[i]]++;
        }
        
        int maxFreq1 = 0, maxFreq2 = 0;
        for (auto &[color, count] : freq1)
        {
            maxFreq1 = max(maxFreq1, count);
        }
        for (auto &[color, count] : freq2)
        {
            maxFreq2 = max(maxFreq2, count);
        }

        cout << (len - (maxFreq1 + maxFreq2)) << endl;
        
        return;
    }

    int totalEven = (n * m + 1) / 2;
    int totalOdd = (n * m) / 2;

    int maxEvenCount = 0, maxOddCount = 0;
    int maxEvenColor = -1, maxOddColor = -1;
    for (auto &[color, count] : colorCountEven)
    {
        if (count > maxEvenCount)
        {
            maxEvenCount = count;
            maxEvenColor = color;
        }
    }
    for (auto &[color, count] : colorCountOdd)
    {
        if (count > maxOddCount)
        {
            maxOddCount = count;
            maxOddColor = color;
        }
    }

    // Second most frequent for conflict resolution
    int secondMaxEvenCount = 0, secondMaxOddCount = 0;

    for (auto &[color, count] : colorCountEven)
    {
        if (color != maxEvenColor && count > secondMaxEvenCount)
        {
            secondMaxEvenCount = count;
        }
    }
    for (auto &[color, count] : colorCountOdd)
    {
        if (color != maxOddColor && count > secondMaxOddCount)
        {
            secondMaxOddCount = count;
        }
    }

    // Different colors chosen
    int option1 = (totalEven - maxEvenCount) + (totalOdd - maxOddCount);

    // Same color is chosen for both sets, pick second-best option
    int option2 = INT_MAX;
    if (maxEvenColor == maxOddColor)
    {
        option2 = min((totalEven - secondMaxEvenCount) + (totalOdd - maxOddCount), (totalEven - maxEvenCount) + (totalOdd - secondMaxOddCount));
    }

    cout << min(option1, option2) << endl;

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
