// A. Sum of Three

// time limit per test2 seconds
// memory limit per test256 megabytes

// Monocarp has an integer n. He wants to represent his number as a sum of three distinct positive integers x, y, and z. Additionally, Monocarp wants none of the numbers x, y, and z to be divisible by 3. Your task is to help Monocarp to find any valid triplet of distinct positive integers x, y, and z, or report that such a triplet does not exist.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of testcases. The only line of each testcase contains a single integer n (1≤n≤109).

// Output
// For each testcase, if there is no valid triplet x, y, and z, print NO on the first line. Otherwise, print YES on the first line. On the second line, print any valid triplet of distinct positive integers x, y, and z such that x+y+z=n, and none of the printed numbers are divisible by 3. If there are multiple valid triplets, you can print any of them.

// Example
// InputCopy
// 4
// 10
// 4
// 15
// 9
// OutputCopy
// YES
// 4 5 1
// NO
// YES
// 2 8 5
// NO

// Note
// In the first testcase, one of the valid triplets is x=4, y=5, z=1. None of these numbers are divisible by three, and 4+5+1=10.
// In the second testcase, there is no valid triplet.
// In the third testcase, one of the valid triplets is x=2, y=8, z=5. None of these numbers are divisible by three, and 2+8+5=15.
// In the fourth testcase, there is no valid triplet.

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    ll int n;
    cin >> n;

    for(int x=1; x<=20; x++)
    {
        for(int y=1; y<=20; y++)
        {
            if((x+y)>=n || x==y)
            {
                continue;
            }

            int z = n-x-y;
            if(z==x || z==y)
            {
                continue;
            }
            if(x%3==0 || y%3==0 || z%3==0)
            {
                continue;
            }

            cout << "YES" << endl;
            cout << x << " " << y << " " << z << endl;
            return;
        }
    }

    cout << "NO" << endl;

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
