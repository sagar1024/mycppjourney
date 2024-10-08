// D. Districts Connection

// time limit per test1 second
// memory limit per test256 megabytes

// There are n districts in the town, the i-th district belongs to the ai-th bandit gang. Initially, no districts are connected to each other. You are the mayor of the city and want to build n−1 two-way roads to connect all districts (two districts can be connected directly or through other connected districts). If two districts belonging to the same gang are connected directly with a road, this gang will revolt. You don't want this so your task is to build n−1 two-way roads in such a way that all districts are reachable from each other (possibly, using intermediate districts) and each pair of directly connected districts belong to different gangs, or determine that it is impossible to build n−1 roads to satisfy all the conditions. You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t (1≤t≤500) — the number of test cases. Then t test cases follow. The first line of the test case contains one integer n (2≤n≤5000) — the number of districts. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤109), where ai is the gang the i-th district belongs to. It is guaranteed that the sum of n does not exceed 5000 (∑n≤5000).

// Output
// For each test case, print: NO on the only line if it is impossible to connect all districts satisfying the conditions from the problem statement. YES on the first line and n−1 roads on the next n−1 lines. Each road should be presented as a pair of integers xi and yi (1≤xi,yi≤n;xi≠yi), where xi and yi are two districts the i-th road connects. For each road i, the condition a[xi]≠a[yi] should be satisfied. Also, all districts should be reachable from each other (possibly, using intermediate districts).

// Example
// InputCopy
// 4
// 5
// 1 2 2 1 3
// 3
// 1 1 1
// 4
// 1 1000 101 1000
// 4
// 1 2 3 4

// OutputCopy
// YES
// 1 3
// 3 5
// 5 4
// 1 2
// NO
// YES
// 1 2
// 2 3
// 3 4
// YES
// 1 2
// 1 3
// 1 4


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    bool allSame = true;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(i>0 && a[i-1]!=a[i])
        {
            allSame &= false;
        }
    }

    if(!allSame)
    {
        cout << "NO" << endl;
        return;
    }

    //Let's choose the first "root" as the district 1
    //AND connect all such districts i that a1≠ai to the district 1
    //So, all disconnected districts that remain are under control of the gang a1
    //Let's find any district i that ai≠a1
    //AND just connect all remaining districts of the gang a1 to this district

    

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
