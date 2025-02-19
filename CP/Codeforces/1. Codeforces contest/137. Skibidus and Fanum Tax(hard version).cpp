// C2. Skibidus and Fanum Tax (hard version)

// time limit per test2 seconds
// memory limit per test256 megabytes

// This is the hard version of the problem. In this version, m≤2⋅105. Skibidus has obtained two arrays a and b, containing n and m elements respectively. For each integer i from 1 to n, he is allowed to perform the operation at most once: Choose an integer j such that 1≤j≤m. Set ai:=bj−ai. Note that ai may become non-positive as a result of this operation. Skibidus needs your help determining whether he can sort a in non-decreasing order∗ by performing the above operation some number of times. a is sorted in non-decreasing order if a1≤a2≤…≤an.

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases. The first line of each test case contains two integers n and m (1≤n≤2⋅105, 1≤m≤2⋅105). The following line of each test case contains n integers a1,a2,…,an (1≤ai≤109). The following line of each test case contains m integers b1,b2,…,bm (1≤bi≤109). It is guaranteed that the sum of n and the sum of m over all test cases does not exceed 2⋅105.

// Output
// For each test case, if it is possible to sort a in non-decreasing order, print "YES" on a new line. Otherwise, print "NO" on a new line. You can output the answer in any case. For example, the strings "yEs", "yes", and "Yes" will also be recognized as positive responses.

// Example
// InputCopy
// 5
// 1 3
// 5
// 9 1 1000000000
// 3 2
// 1 4 3
// 3 4
// 4 3
// 2 4 6 5
// 6 1 8
// 5 2
// 6 4 5 4 5
// 4 1000
// 3 1
// 9 8 7
// 8
// OutputCopy
// YES
// NO
// YES
// NO
// YES

// Note
// In the first test case, [5] is already sorted.
// In the second test case, it can be shown that it is impossible.
// In the third test case, we can set a2:=b1−a2=6−4=2 and a3:=b3−a3=8−6=2. The sequence [2,2,2,5] is in nondecreasing order.
// In the last case, we can apply operations on each index. The sequence becomes [−1,0,1], which is in nondecreasing order.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<ll int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll int b;
    cin >> b;

    bool yes1 = true;

    vector<ll int> modified = a;
    modified[0] = min(a[0],b-a[0]);
    for (int i = 1; i < n; i++)
    {
        ll int prev = modified[i - 1];
        ll int curr = modified[i];
        if (curr < prev)
        {
            ll int x = min(curr,b - curr);
            if (x < prev)
            {
                x = max(curr,b-curr);
                if(x<prev)
                {
                    yes1 &= false;
                }
            }

            modified[i] = x;
        }
        else
        {
            if(min(curr,b-curr)>=prev)
            {
                modified[i] = min(curr,b-curr);
            }
        }
    }

    if(yes1) cout << "YES" << endl;
    else cout << "NO" << endl;

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
