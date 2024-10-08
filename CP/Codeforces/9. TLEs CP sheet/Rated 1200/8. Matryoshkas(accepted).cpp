// D. Matryoshkas

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Matryoshka is a wooden toy in the form of a painted doll, inside which you can put a similar doll of a smaller size. A set of nesting dolls contains one or more nesting dolls, their sizes are consecutive positive integers. Thus, a set of nesting dolls is described by two numbers: s — the size of a smallest nesting doll in a set and m — the number of dolls in a set. In other words, the set contains sizes of s,s+1,…,s+m−1 for some integer s and m (s,m>0). You had one or more sets of nesting dolls. Recently, you found that someone mixed all your sets in one and recorded a sequence of doll sizes — integers a1,a2,…,an. You do not remember how many sets you had, so you want to find the minimum number of sets that you could initially have. For example, if a given sequence is a=[2,2,3,4,3,1]. Initially, there could be 2 sets:

// the first set consisting of 4 nesting dolls with sizes [1,2,3,4];
// a second set consisting of 2 nesting dolls with sizes [2,3].

// According to a given sequence of sizes of nesting dolls a1,a2,…,an, determine the minimum number of nesting dolls that can make this sequence. Each set is completely used, so all its nesting dolls are used. Each element of a given sequence must correspond to exactly one doll from some set.

// Input
// The first line of input data contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows. The first line of each test case contains one integer n (1≤n≤2⋅105) — the total number of matryoshkas that were in all sets. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109)  — the sizes of the matryoshkas. It is guaranteed that the sum of values of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print one integer k — the minimum possible number of matryoshkas sets.

// Example
// inputCopy
// 10
// 6
// 2 2 3 4 3 1
// 5
// 11 8 7 10 9
// 6
// 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
// 8
// 1 1 4 4 2 3 2 3
// 6
// 1 2 3 2 3 4
// 7
// 10 11 11 12 12 13 13
// 7
// 8 8 9 9 10 10 11
// 8
// 4 14 5 15 6 16 7 17
// 8
// 5 15 6 14 8 12 9 11
// 5
// 4 2 2 3 4

// outputCopy
// 2
// 1
// 6
// 2
// 2
// 2
// 2
// 2
// 4
// 3

// Note
// The first test case is described in the problem statement.
// In the second test case, all matryoshkas could be part of the same set with minimum size s=7.
// In the third test case, each matryoshka represents a separate set.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<long long int> a(n);
    map<long long int, int> count;
    set<long long int> st;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        count[a[i]]++;
        st.insert(a[i]);
        st.insert(a[i]+1);
    }

    int prevCount = 0; //Initially 0
    int ans = 0;

    //Iterating in the set
    //Set automatically sorts in ascending order
    for(auto x: st)
    {
        int currCount = count[x];
        ans += max(currCount-prevCount,0);
        prevCount = currCount;
    }

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
