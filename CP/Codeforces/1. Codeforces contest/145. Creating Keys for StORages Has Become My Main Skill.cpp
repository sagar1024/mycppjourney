// C. Creating Keys for StORages Has Become My Main Skill

// time limit per test2 seconds
// memory limit per test256 megabytes

// Akito still has nowhere to live, and the price for a small room is everywhere. For this reason, Akito decided to get a job at a bank as a key creator for storages. In this magical world, everything is different. For example, the key for a storage with the code (n,x) is an array a of length n such that: a1 | a2 | a3 | … | an=x, where a | b is the bitwise "OR" of numbers a and b. MEX({a1,a2,a3,…,an})∗ is maximized among all such arrays. Akito diligently performed his job for several hours, but suddenly he got a headache. Substitute for him for an hour; for the given n and x, create any key for the storage with the code (n,x). MEX(S) is the minimum non-negative integer z such that z is not contained in the set S and all 0≤y<z are contained in S.

// Input
// The first line contains the number t (1≤t≤104) — the number of test cases. In the only line of each test case, two numbers n and x (1≤n≤2⋅105,0≤x<230) are given — the length of the array and the desired value of the bitwise "OR". It is guaranteed that the sum of n across all test cases does not exceed 2⋅105.

// Output
// For each test case, output n integers ai (0≤ai<230) — the elements of the key array that satisfy all the conditions. If there are multiple suitable arrays, output any of them.

// Example
// InputCopy
// 9
// 1 69
// 7 7
// 5 7
// 7 3
// 8 7
// 3 52
// 9 11
// 6 15
// 2 3
// OutputCopy
// 69
// 6 0 3 4 1 2 5
// 4 1 3 0 2
// 0 1 2 3 2 1 0
// 7 0 6 1 5 2 4 3
// 0 52 0
// 0 1 8 3 0 9 11 2 10
// 4 0 3 8 1 2
// 0 3

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    ll int n;
    ll int x;

    cin >> n >> x;

    vector<ll int> arr(n);
    ll int current_xor = 0;
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = i;
        current_xor ^= i;
    }

    //Last element to make OR equal to x
    ll int last_element = x ^ current_xor;
    
    // if(last_element < (1 << 30) && find(arr.begin(), arr.end(), last_element) == arr.end())
    // {
    //     arr[n - 1] = last_element;
    // }
    // else
    // {
    //     arr[n - 2] |= last_element;
    //     arr[n - 1] = x ^ (current_xor & ~arr[n - 2]);
    // }

    arr[n-1] = last_element;
    for(ll int num : arr)
    {
        cout << num << " ";
    }

    cout << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
