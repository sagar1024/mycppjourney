// D. Counting Points

// time limit per test2 seconds
// memory limit per test256 megabytes

// The pink soldiers drew n circles with their center on the x-axis of the plane. Also, they have told that the sum of radii is exactly m. Please find the number of integer points inside or on the border of at least one circle. Formally, the problem is defined as follows. You are given an integer sequence x1,x2,…,xn and a positive integer sequence r1,r2,…,rn, where it is known that ∑ni=1ri=m. You must count the number of integer pairs (x,y) that satisfy the following condition. There exists an index i such that (x−xi)2+y2≤r2i (1≤i≤n). Is this information really useful? Don't ask me; I don't really know.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The first line of each test case contains two integers n and m (1≤n≤m≤2⋅105). The second line of each test case contains x1,x2,…,xn — the centers of the circles (−109≤xi≤109). The third line of each test case contains r1,r2,…,rn — the radii of the circles (1≤ri, ∑ni=1ri=m). It is guaranteed that the sum of m over all test cases does not exceed 2⋅105.

// Output
// For each test case, output the number of integer points satisfying the condition on a separate line.

// Example
// InputCopy
// 4
// 2 3
// 0 0
// 1 2
// 2 3
// 0 2
// 1 2
// 3 3
// 0 2 5
// 1 1 1
// 4 8
// 0 5 10 15
// 2 2 2 2
// OutputCopy
// 13
// 16
// 14
// 52

// Note
// On the first test case, the circle with r1=1 is completely inside the circle with r2=2. Therefore, you only have to count the number of integer points inside the latter. There are 13 integer points such that x2+y2≤22, so the answer is 13.
// On the second test case, the circle with r1=1 is not completely inside the circle with r2=2. There are 3 additional points that are inside the first circle but not inside the second circle, so the answer is 3+13=16.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<long long> x(n), r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }

    map<long long, vector<pair<long long, long long>>> yx;
    for (int i = 0; i < n; i++)
    {
        long long center_x = x[i];
        long long radius = r[i];

        for (long long dx = -radius; dx <= radius; dx++)
        {
            long long current_x = center_x + dx;
            long long max_y_sq = radius * radius - dx * dx;

            if (max_y_sq < 0) continue;

            long long max_y = floor(sqrt(max_y_sq));
            yx[current_x].push_back({-max_y, max_y}); //Vertical points
        }
    }

    long long total = 0;
    for (auto &[current_x, y_ranges] : yx)
    {
        sort(y_ranges.begin(), y_ranges.end());
        vector<pair<long long, long long>> merged;

        for (auto &range : y_ranges)
        {
            if (merged.empty() || merged.back().second < range.first - 1) merged.push_back(range);
            else merged.back().second = max(merged.back().second, range.second);
        }

        for (auto &range : merged)
        {
            total += (range.second - range.first + 1);
        }
    }

    cout << total << endl;

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
