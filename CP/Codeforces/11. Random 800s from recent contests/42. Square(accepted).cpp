// A. Square

// time limit per test1 second
// memory limit per test256 megabytes

// A square of positive (strictly greater than 0) area is located on the coordinate plane, with sides parallel to the coordinate axes. You are given the coordinates of its corners, in random order. Your task is to find the area of the square.

// Input
// Each test consists of several testcases. The first line contains one integer t (1≤t≤100) — the number of testcases. The following is a description of the testcases. Each testcase contains four lines, each line contains two integers xi,yi (−1000≤xi,yi≤1000), coordinates of the corners of the square. It is guaranteed that there is a square with sides parallel to the coordinate axes, with positive (strictly greater than 0) area, with corners in given points.

// Output
// For each test case, print a single integer, the area of the square.

// Example
// InputCopy
// 3
// 1 2
// 4 5
// 1 5
// 4 2
// -1 1
// 1 -1
// 1 1
// -1 -1
// 45 11
// 45 39
// 17 11
// 17 39
// OutputCopy
// 9
// 4
// 784

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    //Euclidean distance
    int dist1 = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    int dist2 = sqrt(pow(x3-x1,2)+pow(y3-y1,2));

    //The min dist will always be a side
    int minn = min(dist1,dist2);

    int area = minn*minn;
    cout << area << endl;

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
