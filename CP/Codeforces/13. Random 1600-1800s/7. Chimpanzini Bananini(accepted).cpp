// G. Chimpanzini Bananini

// time limit per test2 seconds
// memory limit per test256 megabytes

// Chimpanzini Bananini stands on the brink of a momentous battle—one destined to bring finality. For an arbitrary array b of length m, let's denote the rizziness of the array to be ∑mi=1bi⋅i=b1⋅1+b2⋅2+b3⋅3+…+bm⋅m. Chimpanzini Bananini gifts you an empty array. There are three types of operations you can perform on it. Perform a cyclic shift on the array. That is, the array [a1,a2,…,an] becomes [an,a1,a2,…,an−1]. Reverse the entire array. That is, the array [a1,a2,…,an] becomes [an,an−1,…,a1]. Append an element to the end of the array. The array [a1,a2,…,an] becomes [a1,a2,…,an,k] after appending k to the end of the array. After each operation, you are interested in calculating the rizziness of your array. Note that all operations are persistent. This means that each operation modifies the array, and subsequent operations should be applied to the current state of the array after the previous operations.

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases. The first line of the input contains an integer q (1≤q≤2⋅105) — the number of operations you perform on your array. The following q lines first contain a single integer s (1≤s≤3) — the operation type. If s=1, then the cyclic shift operation should be performed. If s=2, then the reversal operation should be performed. If s=3, then the line will contain an additional integer k (1≤k≤106), denoting the element appended to the back of the array. It is guaranteed that the sum of q will not exceed 2⋅105 over all test cases. Additionally, it is guaranteed that the first operation on each test case will be one with s=3.

// Output
// For each test case, output q lines, outputting the rizziness of your array after each operation.

// Example
// InputCopy
// 1
// 13
// 3 1
// 3 2
// 3 3
// 1
// 3 4
// 2
// 3 5
// 1
// 3 6
// 2
// 3 7
// 2
// 1
// OutputCopy
// 1
// 5
// 14
// 11
// 27
// 23
// 48
// 38
// 74
// 73
// 122
// 102
// 88

// Note
// The first six states of the array:
// [1]
// [1,2]
// [1,2,3]
// [3,1,2]
// [3,1,2,4]
// [4,2,1,3]

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int norm = 0, rev = 0;
    int q;
    cin >> q;

    int tot = 0;
    int n = 0;
    
    deque<int> qNorm, qRev;
    
    int p = 0;
    while (q--)
    {
        int s;
        cin >> s;
        if (s == 1)
        {
            int last = qNorm.back();
            qNorm.pop_back();
            qNorm.push_front(last);
            norm += (tot - last);
            norm -= last * n;
            norm += last;

            last = qRev.front();
            qRev.pop_front();
            qRev.push_back(last);
            rev -= (tot - last);
            rev += last * n;
            rev -= last;
        }
        else if (s == 2)
        {
            swap(rev, norm);
            swap(qNorm, qRev);
        }
        else if (s == 3)
        {
            n++;
            int k;
            cin >> k;
            qNorm.push_back(k);
            qRev.push_front(k);
            norm += k * n;
            rev += tot;
            rev += k;
            tot += k;
        }

        cout << norm << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--)
    {
        solve();
    }

    return 0;
}
