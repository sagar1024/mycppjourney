// A. Array Coloring

// time limit per test1 second
// memory limit per test256 megabytes

// You are given an array consisting of n integers. Your task is to determine whether it is possible to color all its elements in two colors in such a way that the sums of the elements of both colors have the same parity and each color has at least one element colored. For example, if the array is [1,2,4,3,2,3,5,4], we can color it as follows: [1,2,4,3,2,3,5,4], where the sum of the blue elements is 6 and the sum of the red elements is 18.

// Input
// The first line contains an integer t (1≤t≤1000) — the number of test cases. Each test case begins with a line containing an integer n (2≤n≤50) — the length of the array a. The next line contains n integers a1,a2,…,an (1≤ai≤50) — the elements of the array a.

// Output
// For each test case, output "YES" (without quotes) if it is possible to color the array in two colors in such a way that the sums of the elements of both colors have the same parity and each color has at least one element colored, and "NO" otherwise. You can output "Yes" and "No" in any case (for example, the strings "yES", "yes", and "Yes" will be recognized as correct answers).

// Example
// InputCopy
// 7
// 8
// 1 2 4 3 2 3 5 4
// 2
// 4 7
// 3
// 3 9 8
// 2
// 1 7
// 5
// 5 4 3 2 1
// 4
// 4 3 4 5
// 2
// 50 48
// OutputCopy
// YES
// NO
// YES
// YES
// NO
// YES
// YES

// Note
// The first sample is described in the statement.
// In the second sample, there are only two colorings [4,7] and [4,7] , but in both cases the parity of sums is different.
// In the third sample, you can color [3,9,8] and 12 and 8 are both even.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    bool allEven, allOdd;
    int oddFreq = 0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        if(a[i]%2==0) allOdd &= false;
        if(a[i]%2!=0)
        {
            allEven &= false;
            oddFreq++;
        }
    }

    if(allOdd || allEven) cout << "YES" << endl;
    else if(oddFreq%2==0) cout << "YES" << endl;
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
