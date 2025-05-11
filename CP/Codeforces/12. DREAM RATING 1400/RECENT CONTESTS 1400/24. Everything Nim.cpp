// A. Everything Nim

// time limit per test2 seconds
// memory limit per test256 megabytes

// Alice and Bob are playing a game on n piles of stones. On each player's turn, they select a positive integer k that is at most the size of the smallest nonempty pile and remove k stones from each nonempty pile at once. The first player who is unable to make a move (because all piles are empty) loses. Given that Alice goes first, who will win the game if both players play optimally?

// Input
// The first line of the input contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows. The first line of each test case contains a single integer n (1≤n≤2⋅105) — the number of piles in the game. The next line of each test case contains n integers a1,a2,…an (1≤ai≤109), where ai is the initial number of stones in the i-th pile. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print a single line with the name of the winner, assuming both players play optimally. If Alice wins, print "Alice", otherwise print "Bob" (without quotes).

// Example
// InputCopy
// 7
// 5
// 3 3 3 3 3
// 2
// 1 7
// 7
// 1 3 9 7 4 2 100
// 3
// 1 2 3
// 6
// 2 1 3 4 2 4
// 8
// 5 7 2 9 6 3 3 2
// 1
// 1000000000
// OutputCopy
// Alice
// Bob
// Alice
// Alice
// Bob
// Alice
// Alice

// Note
// In the first test case, Alice can win by choosing k=3 on her first turn, which will empty all of the piles at once.
// In the second test case, Alice must choose k=1 on her first turn since there is a pile of size 1, so Bob can win on the next turn by choosing k=6.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    bool allsame = true;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        if(i>0 && a[i-1]!=a[i])
        {
            allsame &= false;
        }
    }

    if(allsame || n==1)
    {
        cout << "Alice" << endl;
        return;
    }

    sort(a.begin(),a.end());
    vector<ll int> b;
    for(int i=1; i<=n; i++)
    {
        b.push_back(i);
    }

    ll int idx = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i]>b[i])
        {
            idx = i+1;
            break;
        }
    }

    if(idx==0)
    {
        if(n%2==1) cout << "Alice" << endl;
        else cout << "Bob" << endl;
        return;
    }

    if(idx%2==1) cout << "Alice" << endl;
    else cout << "Bob" << endl;

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
