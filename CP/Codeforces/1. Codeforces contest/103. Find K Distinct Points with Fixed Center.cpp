// A. Find K Distinct Points with Fixed Center

// time limit per test1 second
// memory limit per test256 megabytes

// I couldn't think of a good title for this problem, so I decided to learn from LeetCode.
// — Sun Tzu, The Art of War

// You are given three integers xc, yc, and k (−100≤xc,yc≤100, 1≤k≤1000). You need to find k distinct points (x1,y1), (x2,y2), …, (xk,yk), having integer coordinates, on the 2D coordinate plane such that:
// their center∗ is (xc,yc)
// −109≤xi,yi≤109 for all i from 1 to k

// It can be proven that at least one set of k distinct points always exists that satisfies these conditions. The center of k points (x1,y1), (x2,y2), …, (xk,yk) is (x1+x2+…+xkk,y1+y2+…+ykk).

// Input
// The first line contains t (1≤t≤100) — the number of test cases. Each test case contains three integers xc, yc, and k (−100≤xc,yc≤100, 1≤k≤1000) — the coordinates of the center and the number of distinct points you must output. It is guaranteed that the sum of k over all test cases does not exceed 1000.

// Output
// For each test case, output k lines, the i-th line containing two space separated integers, xi and yi, (−109≤xi,yi≤109) — denoting the position of the i-th point. If there are multiple answers, print any of them. It can be shown that a solution always exists under the given constraints.

// Example
// InputCopy
// 4
// 10 10 1
// 0 0 3
// -5 -8 8
// 4 -5 3
// OutputCopy
// 10 10
// -1 -1
// 5 -1
// -4 2
// -6 -7
// -5 -7
// -4 -7
// -4 -8
// -4 -9
// -5 -9
// -6 -9
// -6 -8
// 1000 -1000
// -996 995
// 8 -10

// Note
// For the first test case, (101,101)=(10,10).
// For the second test case, (−1+5−43,−1−1+23)=(0,0).

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     ll int xc, yc;
//     cin >> xc >> yc;

//     int k;
//     cin >> k;

//     for (int i = 1; i <= k; i++)
//     {
//         //Generating distinct points around (xc, yc)
//         //Tracing the part of the circle
//         ll int xi = xc + i;
//         ll int yi = yc - i;
//         cout << xi << " " << yi << endl;
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

// Alternate soln -

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void solve_test_case()
{
    int xc, yc, k;
    cin >> xc >> yc >> k;

    long long sum_x = 0, sum_y = 0;
    vector<pair<long long int, long long int>> points;

    //Generate k-1 points
    for (int i = 1; i <= k - 1; i++)
    {
        int x = xc+i, y = yc-i;
        points.push_back({x, y});
        sum_x += x;
        sum_y += y;
    }

    //Calculate the last point to make the center (xc, yc)
    long long last_x = (long long)k * xc - sum_x;
    long long last_y = (long long)k * yc - sum_y;
    points.push_back({last_x, last_y});

    for (const auto &point : points)
    {
        cout << point.first << " " << point.second << "\n";
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve_test_case();
    }

    return 0;
}
