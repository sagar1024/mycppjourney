// A. Two Permutations

// time limit per test1 second
// memory limit per test256 megabytes

// You are given three integers n, a, and b. Determine if there exist two permutations p and q of length n, for which the following conditions hold: The length of the longest common prefix of p and q is a. The length of the longest common suffix of p and q is b. A permutation of length n is an array containing each integer from 1 to n exactly once. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array), and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).

// Input
// Each test contains multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. The description of test cases follows. The only line of each test case contains three integers n, a, and b (1≤a,b≤n≤100).

// Output
// For each test case, if such a pair of permutations exists, output "Yes"; otherwise, output "No". You can output each letter in any case (upper or lower).

// Example
// InputCopy
// 4
// 1 1 1
// 2 1 2
// 3 1 1
// 4 1 1
// OutputCopy
// Yes
// No
// No
// Yes

// Note
// In the first test case, [1]and [1] form a valid pair.
// In the second test case and the third case, we can show that such a pair of permutations doesn't exist.
// In the fourth test case, [1,2,3,4] and [1,3,2,4] form a valid pair.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    if(a+b+2<=n || (a==b && b==n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
