// C. Array Elimination

// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output

// You are given array a1,a2,…,an, consisting of non-negative integers. Let's define operation of "elimination" with integer parameter k (1≤k≤n) as follows: Choose k distinct array indices 1≤i1<i2<…<ik≤n. Calculate x=ai1 & ai2 & … & aik, where & denotes the bitwise AND operation (notes section contains formal definition). Subtract x from each of ai1,ai2,…,aik; all other elements remain untouched. Find all possible values of k, such that it's possible to make all elements of array a equal to 0 using a finite number of elimination operations with parameter k. It can be proven that exists at least one possible k for any array a. Note that you firstly choose k and only after that perform elimination operations with value k you've chosen initially.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). Description of the test cases follows. The first line of each test case contains one integer n (1≤n≤200000) — the length of array a. The second line of each test case contains n integers a1,a2,…,an (0≤ai<230) — array a itself. It's guaranteed that the sum of n over all test cases doesn't exceed 200000.

// Output
// For each test case, print all values k, such that it's possible to make all elements of a equal to 0 in a finite number of elimination operations with the given parameter k. Print them in increasing order.

// Example
// inputCopy
// 5
// 4
// 4 4 4 4
// 4
// 13 7 25 19
// 6
// 3 5 3 1 7 1
// 1
// 1
// 5
// 0 0 0 0 0
// outputCopy
// 1 2 4
// 1 2
// 1
// 1
// 1 2 3 4 5

// Note
// In the first test case:

// If k=1, we can make four elimination operations with sets of indices {1}, {2}, {3}, {4}. Since & of one element is equal to the element itself, then for each operation x=ai, so ai−x=ai−ai=0.
// If k=2, we can make two elimination operations with, for example, sets of indices {1,3} and {2,4}: x=a1 & a3 = a2 & a4 = 4 & 4=4. For both operations x=4, so after the first operation a1−x=0 and a3−x=0, and after the second operation — a2−x=0 and a4−x=0.
// If k=3, it's impossible to make all ai equal to 0. After performing the first operation, we'll get three elements equal to 0 and one equal to 4. After that, all elimination operations won't change anything, since at least one chosen element will always be equal to 0.
// If k=4, we can make one operation with set {1,2,3,4}, because x=a1 & a2 & a3 & a4 =4.

// In the second test case, if k=2 then we can make the following elimination operations:

// Operation with indices {1,3}: x=a1 & a3 = 13 & 25=9. a1−x=13−9=4 and a3−x=25−9=16. Array a will become equal to [4,7,16,19].
// Operation with indices {3,4}: x=a3 & a4 = 16 & 19=16. a3−x=16−16=0 and a4−x=19−16=3. Array a will become equal to [4,7,0,3].
// Operation with indices {2,4}: x=a2 & a4 = 7 & 3=3. a2−x=7−3=4 and a4−x=3−3=0. Array a will become equal to [4,4,0,0].
// Operation with indices {1,2}: x=a1 & a2 = 4 & 4=4. a1−x=4−4=0 and a2−x=4−4=0. Array a will become equal to [0,0,0,0].

// Formal definition of bitwise AND:
// Let's define bitwise AND (&) as follows. Suppose we have two non-negative integers x and y, let's look at their binary representations (possibly, with leading zeroes): xk…x2x1x0 and yk…y2y1y0. Here, xi is the i-th bit of number x, and yi is the i-th bit of number y. Let r=x & y is a result of operation & on number x and y. Then binary representation of r will be rk…r2r1r0, where:

// ri={1, if xi=1 and yi=10, if xi=0 or yi=0

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++) cin >> a[i]; 

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
