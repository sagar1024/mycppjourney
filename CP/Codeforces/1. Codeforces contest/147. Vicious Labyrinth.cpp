// B. Vicious Labyrinth

// time limit per test1.5 seconds
// memory limit per test256 megabytes

// Axium Crisis - ak+q

// There are n cells in a labyrinth, and cell i (1≤i≤n) is n−i kilometers away from the exit. In particular, cell n is the exit. Note also that each cell is connected to the exit but is not accessible from any other cell in any way. In each cell, there is initially exactly one person stuck in it. You want to help everyone get as close to the exit as possible by installing a teleporter in each cell i (1≤i≤n), which translocates the person in that cell to another cell ai. The labyrinth owner caught you in the act. Amused, she let you continue, but under some conditions: Everyone must use the teleporter exactly k times. No teleporter in any cell can lead to the same cell it is in. Formally, i≠ai for all 1≤i≤n. You must find a teleporter configuration that minimizes the sum of distances of all individuals from the exit after using the teleporter exactly k times while still satisfying the restrictions of the labyrinth owner. If there are many possible configurations, you can output any of them.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The first and only line of each test case contains two integers n and k (2≤n≤2⋅105, 1≤k≤109) — the number of cells in the labyrinth and the value k. It is guaranteed that the total sum of n across all test cases does not exceed 2⋅105.

// Output
// For each test case, output n integers — the destinations of the teleporters a1,a2,…,an in order, satisfying the given conditions (1≤ai≤n, ai≠i).

// Example
// InputCopy
// 2
// 2 1
// 3 2
// OutputCopy
// 2 1
// 2 3 2

// Note
// In the first test case, the position of each person is as follows.
// Before teleporting: [1,2].
// First teleportation: [2,1].
// The distance sum is (2−2)+(2−1)=1, which is the minimum possible.
// In the second test case, the position of each person is as follows.
// Before teleporting: [1,2,3].
// First teleportation: [2,3,2].
// Second teleportation: [3,2,3].
// The distance sum is (3−3)+(3−2)+(3−3)=1, which is the minimum possible.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    ll int n, k;
    cin >> n >> k;
    
    vector<int> teleporters(n + 1);
    if (k % 2 == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == n) teleporters[i] = n - 1;
            else teleporters[i] = n;
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == n) teleporters[i] = n - 1;
            else if (i == n - 1) teleporters[i] = n;
            else teleporters[i] = i + 1;
        }
    }

    for (int i = 1; i <= n; i++) cout << teleporters[i] << (i < n ? " " : "\n");

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
