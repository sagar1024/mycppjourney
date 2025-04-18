// E. Boneca Ambalabu

// time limit per test2 seconds
// memory limit per test256 megabytes

// Boneca Ambalabu gives you a sequence of n integers a1,a2,…,an. Output the maximum value of (ak⊕a1)+(ak⊕a2)+…+(ak⊕an) among all 1≤k≤n. Note that ⊕ denotes the bitwise XOR operation.

// Input
// The first line contains an integer t (1≤t≤104) – the number of independent test cases. The first line of each test case contains an integer n (1≤n≤2⋅105) – the length of the array. The second line of each test case contains n integers a1,a2,…,an (0≤ai<230). It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output the maximum value on a new line.

// Example
// InputCopy
// 5
// 3
// 18 18 18
// 5
// 1 2 4 8 16
// 5
// 8 13 4 5 15
// 6
// 625 676 729 784 841 900
// 1
// 1
// OutputCopy
// 0
// 79
// 37
// 1555
// 0

// Note
// In the first test case, the best we can do is (18⊕18)+(18⊕18)+(18⊕18)=0.
// In the second test case, we choose k=5 to get (16⊕1)+(16⊕2)+(16⊕4)+(16⊕8)+(16⊕16)=79.

#include <iostream>
#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    vector<int> bitCount(30, 0);
    for (int x : a)
    {
        for (int b = 0; b < 30; ++b)
        {
            if (x & (1 << b))
            {
                bitCount[b]++;
            }
        }
    }

    int maxSum = 0;
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int b = 0; b < 30; ++b)
        {
            int bit = (1 << b);
            if (a[i] & bit)
            {
                sum += (n - bitCount[b]) * bit;
            }
            else
            {
                sum += bitCount[b] * bit;
            }
        }

        maxSum = max(maxSum, sum);
    }

    cout << maxSum << endl;

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
