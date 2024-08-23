// C. Differential Sorting

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given an array a of n elements. Your can perform the following operation no more than n times: Select three indices x,y,z (1≤x<y<z≤n) and replace ax with ay−az. After the operation, |ax| need to be less than 1018. Your goal is to make the resulting array non-decreasing. If there are multiple solutions, you can output any. If it is impossible to achieve, you should report it as well.

// Input
// Each test contains multiple test cases. The first line will contain a single integer t (1≤t≤10000) — the number of test cases. Then t test cases follow. The first line of each test case contains a single integer n (3≤n≤2⋅105) — the size of the array a. The second line of each test case contains n integers a1,a2,…,an (−109≤ai≤109), the elements of a. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print −1 in a single line if there is no solution. Otherwise in the first line you should print a single integer m (0≤m≤n) — number of operations you performed. Then the i-th of the following m lines should contain three integers x,y,z (1≤x<y<z≤n)— description of the i-th operation. If there are multiple solutions, you can output any. Note that you don't have to minimize the number of operations in this task.

// Example
// InputCopy
// 3
// 5
// 5 -4 2 -1 2
// 3
// 4 3 2
// 3
// -3 -2 -1

// OutputCopy
// 2
// 1 2 3
// 3 4 5
// -1
// 0

// Note
// In the first example, the array becomes

// [−6,−4,2,−1,2] after the first operation,
// [−6,−4,−3,−1,2] after the second operation.

// In the second example, it is impossible to make the array sorted after any sequence of operations.
// In the third example, the array is already sorted, so we don't need to perform any operations.

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    vector<ll int> faults(n,0);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        if(a[i]<a[i-1])
        {
            faults[i] = 1;
        }
    }

    vector<vector<ll int>> ans(n, vector<ll int>(3));
    bool yes = false;
    for(int i=0; i<n; i++)
    {
        if(faults[i]==1)
        {
            for(int j=i; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    if((a[j]-a[k])>=a[i])
                    {
                        ans.push_back({i,j,k});
                        yes = true;
                    }
                }
            }
        }
    }

    if(yes)
    {
        cout << ans.size() << endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(j==0)
                {
                    cout << ans[i][j];
                }
                else
                {
                    cout << " " << ans[i][j];
                }
            }
            cout << endl;
        }
    }
    else
    {
        cout << "-1" << endl;
    }

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
