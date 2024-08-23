// C. Array Game

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given an array a of n positive integers. In one operation, you must pick some (i,j) such that 1≤i<j≤|a| and append |ai−aj| to the end of the a (i.e. increase n by 1 and set an to |ai−aj|). Your task is to minimize and print the minimum value of a after performing k operations.

// Input
// Each test contains multiple test cases. The first line contains an integer t (1≤t≤1000) — the number of test cases. The description of the test cases follows. The first line of each test case contains two integers n and k (2≤n≤2⋅103, 1≤k≤109) — the length of the array and the number of operations you should perform. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤1018) — the elements of the array a. It is guaranteed that the sum of n2 over all test cases does not exceed 4⋅106.

// Output
// For each test case, print a single integer — the smallest possible value of the minimum of array a after performing k operations.

// Example
// InputCopy
// 4
// 5 2
// 3 9 7 15 1
// 4 3
// 7 4 15 12
// 6 2
// 42 47 50 54 62 79
// 2 1
// 500000000000000000 1000000000000000000

// OutputCopy
// 1
// 0
// 3
// 500000000000000000

// Note
// In the first test case, after any k=2 operations, the minimum value of a will be 1.
// In the second test case, an optimal strategy is to first pick i=1,j=2 and append |a1−a2|=3 to the end of a, creating a=[7,4,15,12,3]. Then, pick i=3,j=4 and append |a3−a4|=3 to the end of a, creating a=[7,4,15,12,3,3]. In the final operation, pick i=5,j=6 and append |a5−a6|=0 to the end of a. Then the minimum value of a will be 0.
// In the third test case, an optimal strategy is to first pick i=2,j=3 to append |a2−a3|=3 to the end of a. Any second operation will still not make the minimum value of a be less than 3.

//My original soln(wrong ans on tc2) -

//If k≥3, the answer is equal to 0 since after performing an operation on the same pair (i,j) twice, performing an operation on the two new values (which are the same) results in 0. Therefore, let's consider the case for 1≤k≤2. For k=1, it is sufficient to sort the array and output the minimum between ai and ai+1−ai. For k=2, let's brute force the first operation. If the newly created value is v, then it is sufficient to find the smallest ai satisfying ai≥v and greatest ai satisfying ai≤v and relax the answer on |ai−v|. Also, remember to consider the cases of performing no operation or one operation. This runs in O(N2logN). There also exists a solution in O(N2) using a two pointers approach

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    ll int n, k;
    cin >> n >> k;

    vector<ll int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    if(k>=3)
    {
        cout << "0" << endl;
        return;
    }

    sort(a.begin(),a.end());
    ll int ans = INT_MAX;
    for(int i=1; i<n; i++)
    {
        ans = min(ans,abs(a[i-1]-a[i]));
    }
    if(k==1)
    {
        cout << ans << endl;
    }
    else if(k==2)
    {
        for(int i=1; i<n; i++)
        {
            ll int x = abs(a[i-1]-a[i]);
            a.push_back(x);
        }

        sort(a.begin(),a.end());
        cout << a[0] << endl;
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
