// A. Sorting with Twos

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given an array of integers a1,a2,…,an. In one operation, you do the following:

// Choose a non-negative integer m, such that 2m≤n.
// Subtract 1 from ai for all integers i, such that 1≤i≤2m.

// Can you sort the array in non-decreasing order by performing some number (possibly zero) of operations? An array is considered non-decreasing if ai≤ai+1 for all integers i such that 1≤i≤n−1.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows. The first line of each test case contains a single integer n (1≤n≤20) — the length of array a. The second line of each test case contains n integers a1,a2,…,an — the integers in array a (0≤ai≤1000).

// Output
// For each test case, output "YES" if the array can be sorted, and "NO" otherwise.

// Example
// InputCopy
// 8
// 5
// 1 2 3 4 5
// 5
// 6 5 3 4 4
// 9
// 6 5 5 7 5 6 6 8 7
// 4
// 4 3 2 1
// 6
// 2 2 4 5 3 2
// 8
// 1 3 17 19 27 57 179 13
// 5
// 3 17 57 179 92
// 10
// 1 2 3 4 0 6 7 8 9 10
// OutputCopy
// YES
// YES
// YES
// NO
// NO
// NO
// YES
// YES

// Note
// In the first test case, the array is already sorted in non-decreasing order, so we don't have to perform any operations.
// In the second test case, we can choose m=1 twice to get the array [4,3,3,4,4]. Then, we can choose m=0 once and get the sorted in non-decreasing order array [3,3,3,4,4].
// In the third test case, we can choose m=0 once and get the array [5,5,5,7,5,6,6,8,7]. Then, we can choose m=2 twice and get the array [3,3,3,5,5,6,6,8,7]. After that, we can choose m=3 once and get the sorted in non-decreasing order array [2,2,2,4,4,5,5,7,7].
// For the fourth and fifth test case, it can be shown that the array could not be sorted using these operations.

#include <iostream>
#include <bits/stdc++.h>
//#include <bit>

using namespace std;
#define ll long long

bool isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b;
    for(int i=0; i<n ;i++)
    {
        cin >> a[i];
    }

    //Diff array
    for(int i=0; i<n-1; i++)
    {
        b.push_back(a[i+1]-a[i]);
    }

    bool sortable = true;
    for(int i=0; i<n-1; i++)
    {
        //if(b[i]>=0 || std::has_single_bit(i)) continue;
        //else sortable &= false;
        if(b[i]>=0 || isPowerOfTwo(i+1)) continue;
        else sortable &= false;
    }

    if(sortable) cout << "YES" << endl;
    else cout << "NO" << endl;

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
