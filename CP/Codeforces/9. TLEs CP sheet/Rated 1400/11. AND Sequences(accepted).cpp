// B. AND Sequences

// time limit per test2 seconds
// memory limit per test256 megabytes

// A sequence of n non-negative integers (n≥2) a1,a2,…,an is called good if for all i from 1 to n−1 the following condition holds true: a1&a2&…&ai=ai+1&ai+2&…&an, where & denotes the bitwise AND operation. You are given an array a of size n (n≥2). Find the number of permutations p of numbers ranging from 1 to n, for which the sequence ap1, ap2, ... ,apn is good. Since this number can be large, output it modulo 109+7.

// Input
// The first line contains a single integer t (1≤t≤104), denoting the number of test cases. The first line of each test case contains a single integer n (2≤n≤2⋅105) — the size of the array. The second line of each test case contains n integers a1,a2,…,an (0≤ai≤109) — the elements of the array. It is guaranteed that the sum of n over all test cases doesn't exceed 2⋅105.

// Output
// Output t lines, where the i-th line contains the number of good permutations in the i-th test case modulo 109+7.

// Example
// InputCopy
// 4
// 3
// 1 1 1
// 5
// 1 2 3 4 5
// 5
// 0 2 0 3 0
// 4
// 1 3 5 1
// OutputCopy
// 6
// 0
// 36
// 4

// Note
// In the first test case, since all the numbers are equal, whatever permutation we take, the sequence is good. There are a total of 6 permutations possible with numbers from 1 to 3: [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].
// In the second test case, it can be proved that no permutation exists for which the sequence is good.
// In the third test case, there are a total of 36 permutations for which the sequence is good. One of them is the permutation [1,5,4,2,3] which results in the sequence s=[0,0,3,2,0]. This is a good sequence because
// s1=s2&s3&s4&s5=0,
// s1&s2=s3&s4&s5=0,
// s1&s2&s3=s4&s5=0,
// s1&s2&s3&s4=s5=0.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int MOD = 1e9+7;

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll int minn = *min_element(a.begin(),a.end());
    //ll int max = *max_element(a.begin(),a.end());

    ll int count = 0;
    for(int x: a)
    {
        if(minn == x)
        {
            count++;
        }
        if((minn & x) != minn)
        {
            cout << "0" << endl;
            return;
        }
    }

    ll int fact = 1;
    for(int i=1; i<=n-2; i++)
    {
        fact = (1LL * fact * i)%MOD;
    }

    ll int ans = (1LL*count*(count-1))%MOD;
    ans = (1LL*ans*fact)%MOD;

    cout << ans << endl;

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
