// A. Copil Copac Draws Trees

// time limit per test3 seconds
// memory limit per test256 megabytes

// Copil Copac is given a list of n−1 edges describing a tree of n vertices. He decides to draw it using the following algorithm:
// Step 0: Draws the first vertex (vertex 1). Go to step 1.
// Step 1: For every edge in the input, in order: if the edge connects an already drawn vertex u to an undrawn vertex v, he will draw the undrawn vertex v and the edge. After checking every edge, go to step 2.
// Step 2: If all the vertices are drawn, terminate the algorithm. Else, go to step 1.

// The number of readings is defined as the number of times Copil Copac performs step 1. Find the number of readings needed by Copil Copac to draw the tree.

// Input
// Each test contains multiple test cases. The first line of input contains a single integer t (1≤t≤104) — the number of test cases. The description of test cases follows. The first line of each test case contains a single integer n (2≤n≤2⋅105) — the number of vertices of the tree. The following n−1 lines of each test case contain two integers ui and vi (1≤ui,vi≤n, ui≠vi) — indicating that (ui,vi) is the i-th edge in the list. It is guaranteed that the given edges form a tree. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output the number of readings Copil Copac needs to draw the tree.

// Example
// InputCopy
// 2
// 6
// 4 5
// 1 3
// 1 2
// 3 4
// 1 6
// 7
// 5 6
// 2 4
// 2 7
// 1 3
// 1 2
// 4 5

// OutputCopy
// 2
// 3

// Note
// In the first test case:
// After the first reading, the tree will look like this:
// After the second reading:
// Therefore, Copil Copac needs 2 readings to draw the tree.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAXX = 2e5+5;
int dp[MAXX], id[MAXX];
vector<pair<int,int>> edges[MAXX]; //square brackets, it indicates the use of a constant size array

void dfs(int u)
{
    for(auto iter: edges[u])
    {
        //If unvisited
        if(dp[iter.first]==0)
        {
            dp[iter.first] = dp[u] + (iter.second<=id[u]);
            id[iter.first] = iter.second;
            dfs(iter.first);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        dp[i] = 0;
        id[i] = 0;
        edges[i].clear();
    }

    //Tree
    //vector<vector<int>> adjMat(n,vector<int>(n));
    // for(int i=0; i<n; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     adjMat[u].push_back(v);
    //     adjMat[v].push_back(u);
    // }

    for(int i=1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;

        edges[u].push_back({v,i});
        edges[v].push_back({u,i});
    }

    dp[1] = 1;
    dfs(1);

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
