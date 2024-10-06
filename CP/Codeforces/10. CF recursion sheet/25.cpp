// Y. Number of Ways

// time limit per test1 second
// memory limit per test256 megabytes

// Given two numbers S and E where S denotes a start point and E denotes an end point. Determine how many possible ways to reach point E if you can move either 1 step, 2 steps or 3 steps at a time. Note: Solve this problem using recursion.

// Input
// Only one line contains two numbers S and E (1≤S≤E≤15).

// Output
// Print the answer required above.

// Example
// InputCopy
// 2 5
// OutputCopy
// 4

// Note
// In the first example:
// There are 4 ways to reach from point 2 to point 5 as follows: [2, 3, 4, 5], [2, 3, 5], [2, 4, 5] and [2, 5].

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(int s, int e, int ways)
{
    if(s==e)
    {
        return ways+1;
    }
    if(s>e)
    {
        return ways+0;
    }
    
    return solve(s+1,e,ways) + solve(s+2,e,ways) + solve(s+3,e,ways);
}

int32_t main()
{
    int s, e;
    cin >> s >> e;

    int ways = solve(s,e,0);
    cout << ways << endl;

    return 0;
}
