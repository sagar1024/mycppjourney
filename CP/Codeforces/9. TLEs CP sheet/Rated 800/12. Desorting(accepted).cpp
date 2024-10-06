// A. Desorting

// time limit per test1 second
// memory limit per test256 megabytes

// Call an array a of length n sorted if a1≤a2≤…≤an−1≤an. Ntarsis has an array a of length n. He is allowed to perform one type of operation on it (zero or more times): Choose an index i (1≤i≤n−1). Add 1 to a1,a2,…,ai. Subtract 1 from ai+1,ai+2,…,an. The values of a can be negative after an operation. Determine the minimum operations needed to make a not sorted.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). The description of the test cases follows. The first line of each test case contains a single integer n (2≤n≤500) — the length of the array a. The next line contains n integers a1,a2,…,an (1≤ai≤109) — the values of array a. It is guaranteed that the sum of n across all test cases does not exceed 500.

// Output
// Output the minimum number of operations needed to make the array not sorted.

// Example
// InputCopy
// 4
// 2
// 1 1
// 4
// 1 8 10 13
// 3
// 1 3 2
// 3
// 1 9 14
// OutputCopy
// 1
// 2
// 0
// 3

// Note
// In the first case, we can perform 1 operation to make the array not sorted:
// Pick i=1. The array a then becomes [2,0], which is not sorted.

// In the second case, we can perform 2 operations to make the array not sorted:
// Pick i=3. The array a then becomes [2,9,11,12].
// Pick i=3. The array a then becomes [3,10,12,11], which is not sorted.
// It can be proven that 1 and 2 operations are the minimal numbers of operations in the first and second test cases, respectively.

// In the third case, the array is already not sorted, so we perform 0 operations.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll int> a(n), sortedA;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     sortedA = a;
//     sort(sortedA.begin(),sortedA.end());
//     bool alreadySorted = true;
//     for(int i=0; i<n; i++)
//     {
//         if(a[i]!=sortedA[i])
//         {
//             alreadySorted &= false;
//         }
//     }

//     bool alreadyUnsorted = !alreadySorted;

//     if(alreadyUnsorted) cout << "0" << endl;
//     else
//     {
//         ll int minnDiff = 1e9+9;
//         for (int i = 1; i < n - 1; i++)
//         {
//             minnDiff = min(minnDiff, a[i] - a[i - 1]);
//         }

//         cout << minnDiff << endl;
//     }

//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    int diff = 1e9;
    bool sorted = true;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (i > 0)
        {
            diff = min(nums[i] - nums[i - 1], diff);
            sorted &= nums[i] >= nums[i - 1];
        }
    }

    if (!sorted)
    {
        cout << 0 << endl;
        return;
    }
    
    cout << diff / 2 + 1 << endl;

    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
