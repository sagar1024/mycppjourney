// C. Target Practice

// time limit per test1 second
// memory limit per test256 megabytes

// A 10×10 target is made out of five "rings" as shown. Each ring has a different point value: the outermost ring — 1 point, the next ring — 2 points, ..., the center ring — 5 points. Vlad fired several arrows at the target. Help him determine how many points he got.

// Input
// The input consists of multiple test cases. The first line of the input contains a single integer t (1≤t≤1000) — the number of test cases. Each test case consists of 10 lines, each containing 10 characters. Each character in the grid is either X (representing an arrow) or . (representing no arrow).

// Output
// For each test case, output a single integer — the total number of points of the arrows.

// Example
// InputCopy
// 4
// X.........
// ..........
// .......X..
// .....X....
// ......X...
// ..........
// .........X
// ..X.......
// ..........
// .........X
// ..........
// ..........
// ..........
// ..........
// ..........
// ..........
// ..........
// ..........
// ..........
// ..........
// ..........
// ..........
// ..........
// ..........
// ....X.....
// ..........
// ..........
// ..........
// ..........
// ..........
// XXXXXXXXXX
// XXXXXXXXXX
// XXXXXXXXXX
// XXXXXXXXXX
// XXXXXXXXXX
// XXXXXXXXXX
// XXXXXXXXXX
// XXXXXXXXXX
// XXXXXXXXXX
// XXXXXXXXXX
// OutputCopy
// 17
// 0
// 5
// 220

// Note
// In the first test case, there are three arrows on the outer ring worth 1 point each, two arrows on the ring worth 3 points each, and two arrows on the ring worth 4 points each. The total score is 3×1+2×3+2×4=17.
// In the second test case, there aren't any arrows, so the score is 0.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int t;
    cin >> t;

    int score[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
        {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    while (t--)
    {
        vector<vector<char>> a(10, vector<char>(10));
        int ans = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                char ch;
                cin >> ch;

                if(ch=='X')
                {
                    ans += score[i][j];
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
