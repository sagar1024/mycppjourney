// C. Add, Divide and Floor

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given an integer array a1,a2,…,an (0≤ai≤109). In one operation, you can choose an integer x (0≤x≤1018) and replace ai with ⌊ai+x2⌋ (⌊y⌋ denotes rounding y down to the nearest integer) for all i from 1 to n. Pay attention to the fact that all elements of the array are affected on each operation. Print the smallest number of operations required to make all elements of the array equal. If the number of operations is less than or equal to n, then print the chosen x for each operation. If there are multiple answers, print any of them.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of testcases. The first line of each testcase contains a single integer n (1≤n≤2⋅105). The second line contains n integers a1,a2,…,an (0≤ai≤109). The sum of n over all testcases doesn't exceed 2⋅105.

// Output
// For each testcase, print the smallest number of operations required to make all elements of the array equal. If the number of operations is less than or equal to n, then print the chosen x for each operation in the next line. If there are multiple answers, print any of them.

// Example
// InputCopy
// 4
// 1
// 10
// 2
// 4 6
// 6
// 2 1 2 1 2 1
// 2
// 0 32
// OutputCopy
// 0
// 2
// 2 5
// 1
// 1
// 6

// Note
// In the first testcase, all elements are already equal, so 0 operations are required. It doesn't matter if you print an empty line afterwards or not.
// In the second testcase, you can't make less than 2 operations. There are multiple answers, let's consider the answer sequence [2,5]. After applying an operation with x=2, the array becomes [⌊4+22⌋,⌊6+22⌋]=[3,4]. After applying an operation with x=5 after that, the array becomes [⌊3+52⌋,⌊4+52⌋]=[4,4]. Both elements are the same, so we are done.
// In the last testcase, you can't make less than 6 operations. Since 6 is greater than n, you don't have to print them. One possible answer sequence is [0,0,0,0,0,0]. We are just dividing the second element by 2 every time and not changing the first element.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(),a.end());
    ll int minn = a[0], maxx = a[n-1];
    ll int ops = 0;
    vector<int> ans;
    while(minn!=maxx)
    {
        ll int x = minn%2;
        if(minn%2==0)
        {
            minn = minn/2;
            maxx = maxx/2;
        }
        else
        {
            minn = (minn + 1)/2;
            maxx = (maxx + 1)/2;
        }

        ans.push_back(x);
        ops++;
    }

    cout << ops << endl;
    if(ops && ops<=n)
    {
        for(auto x: ans)
        {
            cout << x << " ";
        }
    }

    cout << endl;
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
