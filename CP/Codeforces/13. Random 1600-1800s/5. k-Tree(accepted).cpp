// C. k-Tree

// time limit per test1 second
// memory limit per test256 megabytes

// Quite recently a creative student Lesha had a lecture on trees. After the lecture Lesha was inspired and came up with the tree of his own which he called a k-tree. A k-tree is an infinite rooted tree where:
// each vertex has exactly k children;
// each edge has some weight;
// if we look at the edges that goes from some vertex to its children (exactly k edges), then their weights will equal 1, 2, 3, ..., k.

// The picture below shows a part of a 3-tree. As soon as Dima, a good friend of Lesha, found out about the tree, he immediately wondered: "How many paths of total weight n (the sum of all weights of the edges in the path) are there, starting from the root of a k-tree and also containing at least one edge of weight at least d?". Help Dima find an answer to his question. As the number of ways can be rather large, print it modulo 1000000007 (109 + 7).

// Input
// A single line contains three space-separated integers: n, k and d (1 ≤ n, k ≤ 100; 1 ≤ d ≤ k).

// Output
// Print a single integer — the answer to the problem modulo 1000000007 (109 + 7).

// Examples
// InputCopy
// 3 3 2
// OutputCopy
// 3
// InputCopy
// 3 3 3
// OutputCopy
// 1
// InputCopy
// 4 3 2
// OutputCopy
// 6
// InputCopy
// 4 5 2
// OutputCopy
// 7

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
int dp[100][2];

void add(int &a, int b)
{
    a += b;
    if (a >= mod) a -= mod;
}

int main(int argc, char **argv)
{
    int n, k, d;
    cin >> n >> k >> d;
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = dp[i][1] = 0;
        for (int j = 1; j <= k; ++j)
        {
            if (i - j < 0) break;
            if (j < d)
            {
                add(dp[i][0], dp[i - j][0]);
                add(dp[i][1], dp[i - j][1]);
            }
            else
            {
                add(dp[i][1], dp[i - j][0]);
                add(dp[i][1], dp[i - j][1]);
            }
        }
    }

    cout << dp[n][1] << "\n";
    return 0;
}
