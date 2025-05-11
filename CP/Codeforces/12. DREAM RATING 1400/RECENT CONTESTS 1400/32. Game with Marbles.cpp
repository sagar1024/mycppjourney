// E1. Game with Marbles (Easy Version)

// time limit per test3.5 seconds
// memory limit per test256 megabytes

// The easy and hard versions of this problem differ only in the constraints on the number of test cases and n. In the easy version, the number of test cases does not exceed 103, and n does not exceed 6. Recently, Alice and Bob were given marbles of n different colors by their parents. Alice has received a1 marbles of color 1, a2 marbles of color 2,..., an marbles of color n. Bob has received b1 marbles of color 1, b2 marbles of color 2, ..., bn marbles of color n. All ai and bi are between 1 and 109. After some discussion, Alice and Bob came up with the following game: players take turns, starting with Alice. On their turn, a player chooses a color i such that both players have at least one marble of that color. The player then discards one marble of color i, and their opponent discards all marbles of color i. The game ends when there is no color i such that both players have at least one marble of that color. The score in the game is the difference between the number of remaining marbles that Alice has and the number of remaining marbles that Bob has at the end of the game. In other words, the score in the game is equal to (A−B), where A is the number of marbles Alice has and B is the number of marbles Bob has at the end of the game. Alice wants to maximize the score, while Bob wants to minimize it. Calculate the score at the end of the game if both players play optimally.

// Input
// The first line contains a single integer t (1≤t≤103) — the number of test cases. Each test case consists of three lines:
// the first line contains a single integer n (2≤n≤6) — the number of colors;
// the second line contains n integers a1,a2,…,an (1≤ai≤109), where ai is the number of marbles of the i-th color that Alice has;
// the third line contains n integers b1,b2,…,bn (1≤bi≤109), where bi is the number of marbles of the i-th color that Bob has.

// Output
// For each test case, output a single integer — the score at the end of the game if both Alice and Bob act optimally.

// Example
// InputCopy
// 5
// 3
// 4 2 1
// 1 2 4
// 4
// 1 20 1 20
// 100 15 10 20
// 5
// 1000000000 1000000000 1000000000 1000000000 1000000000
// 1 1 1 1 1
// 3
// 5 6 5
// 2 1 7
// 6
// 3 2 4 2 5 5
// 9 4 7 9 2 5
// OutputCopy
// 1
// -9
// 2999999997
// 8
// -6

// Note
// In the first example, one way to achieve a score of 1 is as follows:
// Alice chooses color 1, discards 1 marble. Bob also discards 1 marble;
// Bob chooses color 3, discards 1 marble. Alice also discards 1 marble;
// Alice chooses color 2, discards 1 marble, and Bob discards 2 marble.
// As a result, Alice has a=[3,1,0] remaining, and Bob has b=[0,0,3] remaining. The score is 3+1−3=1.
// It can be shown that neither Alice nor Bob can achieve a better score if both play optimally.

// In the second example, Alice can first choose color 1, then Bob will choose color 4, after which Alice will choose color 2, and Bob will choose color 3. It can be shown that this is the optimal game.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n),b(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> b[i];
    }

    return;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
