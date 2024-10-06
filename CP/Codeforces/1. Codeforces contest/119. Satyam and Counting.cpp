// D. Satyam and Counting

// time limit per test2 seconds
// memory limit per test256 megabytes

// Satyam is given n distinct points on the 2D coordinate plane. It is guaranteed that 0≤yi≤1 for all given points (xi,yi). How many different nondegenerate right triangles∗ can be formed from choosing three different points as its vertices? Two triangles a and b are different if there is a point v such that v is a vertex of a but not a vertex of b. A nondegenerate right triangle has positive area and an interior 90∘ angle.

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases. The first line of each test case contains an integer n (3≤n≤2⋅105) — the number of points. The following n lines contain two integers xi and yi (0≤xi≤n, 0≤yi≤1) — the i'th point that Satyam can choose from. It is guaranteed that all (xi,yi) are pairwise distinct. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// Output an integer for each test case, the number of distinct nondegenerate right triangles that can be formed from choosing three points.

// Example
// InputCopy
// 3
// 5
// 1 0
// 1 1
// 3 0
// 5 0
// 2 1
// 3
// 0 0
// 1 0
// 3 0
// 9
// 1 0
// 2 0
// 3 0
// 4 0
// 5 0
// 2 1
// 7 1
// 8 1
// 9 1
// OutputCopy
// 4
// 0
// 8

// Note
// The four triangles in question for the first test case:(figure was given)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    unordered_map<int, int> countX, countY;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;

        points[i] = {x, y};
        countX[x]++;
        countY[y]++;
    }

    int rightTriangles = 0;
    for (auto &point : points)
    {
        int x = point.first;
        int y = point.second;

        int cntX = countX[x] - 1;
        int cntY = countY[y] - 1;

        rightTriangles += cntX * cntY;
    }

    if(rightTriangles==0)
    {
        cout << rightTriangles << endl;
    }
    else
    {
        cout << rightTriangles+1 << endl;
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
