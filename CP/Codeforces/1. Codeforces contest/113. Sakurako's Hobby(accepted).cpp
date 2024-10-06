// D. Sakurako's Hobby

// time limit per test2 seconds
// memory limit per test256 megabytes

// For a certain permutation p, Sakurako calls an integer j reachable from an integer i if it is possible to make i equal to j by assigning i=pi a certain number of times. If p=[3,5,6,1,2,4], then, for example, 4 is reachable from 1, because: i=1 → i=p1=3 → i=p3=6 → i=p6=4. Now i=4, so 4 is reachable from 1. Each number in the permutation is colored either black or white. Sakurako defines the function F(i) as the number of black integers that are reachable from i. Sakurako is interested in F(i) for each 1≤i≤n, but calculating all values becomes very difficult, so she asks you, as her good friend, to compute this. A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (the number 2 appears twice in the array), and [1,3,4] is also not a permutation (n=3, but the array contains 4).

// Input
// The first line contains a single integer t (1≤t≤104)  — the number of test cases. The first line of each test case contains a single integer n (1≤n≤2⋅105)  — the number of elements in the array. The second line of each test case contains n integers p1,p2,…,pn (1≤pi≤n)  — the elements of the permutation. The third line of each test case contains a string s of length n, consisting of '0' and '1'. If si=0, then the number pi is colored black; if si=1, then the number pi is colored white. It is guaranteed that the sum of n across all test cases does not exceed 2⋅105.

// Output
// For each test case, output n integers F(1),F(2),…,F(n).

// Example
// InputCopy
// 5
// 1
// 1
// 0
// 5
// 1 2 4 5 3
// 10101
// 5
// 5 4 1 3 2
// 10011
// 6
// 3 5 6 1 2 4
// 010000
// 6
// 1 2 3 4 5 6
// 100110

// OutputCopy
// 1 
// 0 1 1 1 1 
// 2 2 2 2 2 
// 4 1 4 4 1 4 
// 0 1 1 0 0 1 

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];

        //Convert to 0-based index
        --p[i];
    }

    string s;
    cin >> s;

    vector<int> F(n, 0);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            //Starting a new cycle
            int cycle_count = 0;
            int start = i;
            vector<int> cycle_nodes;

            //Traversing the cycle
            while (!visited[start])
            {
                visited[start] = true;
                cycle_nodes.push_back(start);
                if (s[start] == '0')
                {
                    cycle_count++;
                }
                start = p[start];
            }

            //Assigning the count to all elements in the cycle
            for (int node : cycle_nodes)
            {
                F[node] = cycle_count;
            }
        }
    }

    for(int count : F)
    {
        cout << count << " ";
    }

    cout << endl;
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
