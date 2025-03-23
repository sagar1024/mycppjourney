// C. Alya and Permutation

// time limit per test2 seconds
// memory limit per test256 megabytes

// Alya has been given a hard problem. Unfortunately, she is too busy running for student council. Please solve this problem for her. Given an integer n, construct a permutation p of integers 1,2,…,n that maximizes the value of k (which is initially 0) after the following process. Perform n operations, on the i-th operation (i=1,2,…,n), If i is odd, k=k&pi, where & denotes the bitwise AND operation. If i is even, k=k|pi, where | denotes the bitwise OR operation.

// Input
// The first line contains a single integer t (1≤t≤500) — the number of test cases. The only line of each test case contains a single integer n (5≤n≤2⋅105) — the length of the permutation. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output the maximum value of k in the first line and output the permutation p1,p2,…,pn in the second line. If there are multiple such permutations, output any.

// Example
// InputCopy
// 6
// 5
// 6
// 7
// 8
// 9
// 10
// OutputCopy
// 5
// 2 1 3 4 5 
// 7
// 1 2 4 6 5 3 
// 7
// 2 4 5 1 3 6 7 
// 15
// 2 4 5 1 3 6 7 8 
// 9
// 2 4 5 6 7 1 3 8 9 
// 15
// 1 2 3 4 5 6 8 10 9 7

// Note
// For the first test case, the value of k is determined as follows:
// k=0 initially.
// On the 1st operation, 1 is odd, so Alya sets k to be k&p1=0&2=0.
// On the 2nd operation, 2 is even, so Alya sets k to be k|p2=0|1=1.
// On the 3rd operation, 3 is odd, so Alya sets k to be k&p3=1&3=1.
// On the 4th operation, 4 is even, so Alya sets k to be k|p4=1|4=5.
// On the 5th operation, 5 is odd, so Alya sets k to be k&p5=5&5=5.
// The final value of k is 5. It can be shown that the final value of k is at most 5 for all permutations of length 5. Another valid output is [2,3,1,4,5].
// For the second test case, the final value of k is 7. It can be shown that the final value of k is at most 7 for all permutations of length 6. Other valid outputs include [2,4,1,6,3,5] and [5,2,6,1,3,4].

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int k = 0;
    // vector<int> p;
    // for(int i=1; i<=n; i++)
    // {
    //     p.push_back(i);
    // }

    set<int> st;
    for(int i=1; i<=n; i++)
    {
        st.insert(i);
    }

    vector<int> res(n+1); //Result
    int lsb = n & (-n); //To find the lsb in bit rep of n
    int power2 = 1; //Power of 2
    while(power2*2<=n)
    {
        power2 = power2*2;
    }

    //Case when n is odd
    if(n&1)
    {
        cout << n << endl; //Cant go more than n
        res[n-3] = lsb;
        res[n-2] = lsb + (lsb==1? 2:1);
        res[n-1] = n-lsb;
        res[n] = n;
    }
    else //Case when n is even
    {
        //Represents a number that has all bits set to 1 up to the highest bit of power2
        cout << power2*2-1 << endl;

        //Case when n is pow of 2
        if(power2==n)
        {
            res[n-4] = 1; //Sets the lsb
            //and
            res[n-3] = 3; //Sets the lowest 2 bits
            //or
            res[n-2] = n-2;
            //and 
            res[n-1] = n-1;
            //or 
            res[n] = n;
        }
        else
        {
            res[n-2] = n; //Setting to large n
            //and
            res[n-1] = n-1;
            //or
            res[n] = power2-1;
        }
    }

    for(int i=1; i<n+1; i++)
    {
        st.erase(res[i]);
    }

    for(int i=1; i<n+1; i++)
    {
        if(!res[i])
        {
            res[i] = *st.begin(), st.erase(res[i]);
        }
    }

    for(int i=1; i<n+1; i++)
    {
        if (i==1) cout << res[i];
        else cout << " " << res[i];
    }
    
    cout << endl;

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
