// B. Stone Age Problem

// time limit per test2 seconds
// memory limit per test256 megabytes

// Once upon a time Mike and Mike decided to come up with an outstanding problem for some stage of ROI (rare olympiad in informatics). One of them came up with a problem prototype but another stole the idea and proposed that problem for another stage of the same olympiad. Since then the first Mike has been waiting for an opportunity to propose the original idea for some other contest... Mike waited until this moment! You are given an array a of n integers. You are also given q queries of two types: Replace i-th element in the array with integer x. Replace each element in the array with integer x. After performing each query you have to calculate the sum of all elements in the array.

// Input
// The first line contains two integers n and q (1≤n,q≤2⋅105) — the number of elements in the array and the number of queries, respectively. The second line contains n integers a1,…,an (1≤ai≤109) — elements of the array a. Each of the following q lines contains a description of the corresponding query. Description begins with integer t (t∈{1,2}) which denotes a type of the query: If t=1, then two integers i and x are following (1≤i≤n, 1≤x≤109) — position of replaced element and it's new value. If t=2, then integer x is following (1≤x≤109) — new value of each element in the array.

// Output
// Print q integers, each on a separate line. In the i-th line print the sum of all elements in the array after performing the first i queries.

// Example
// InputCopy
// 5 5
// 1 2 3 4 5
// 1 1 5
// 2 10
// 1 5 11
// 1 4 1
// 2 1

// OutputCopy
// 19
// 50
// 51
// 42
// 5

// Note
// Consider array from the example and the result of performing each query
// Initial array is [1,2,3,4,5].
// After performing the first query, array equals to [5,2,3,4,5]. The sum of all elements is 19.
// After performing the second query, array equals to [10,10,10,10,10]. The sum of all elements is 50.
// After performing the third query, array equals to [10,10,10,10,11]. The sum of all elements is 51.
// After performing the fourth query, array equals to [10,10,10,1,11]. The sum of all elements is 42.
// After performing the fifth query, array equals to [1,1,1,1,1]. The sum of all elements is 5.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// int32_t main()
// {
//     int n, q;
//     cin >> n >> q;

//     vector<ll int> a(n);
//     ll int sum = 0;
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//         sum += a[i];
//     }

//     while(q--)
//     {
//         int type;
//         cin >> type;

//         if(type==1)
//         {
//             ll int pos, val;
//             cin >> pos >> val;
//             pos--; //Making 0-indexed

//             sum -= a[pos];
//             sum += val;
//             a[pos] = val; //Assigning the new val "after" subtracting it

//             cout << sum << endl;
//         }
//         else if(type==2)
//         {
//             ll int val;
//             cin >> val;

//             //memset(a,val,a.size());
//             fill(a.begin(),a.end(),val);
//             sum = a.size()*val;

//             cout << sum << endl;
//         }
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int32_t main()
{
    int n, q;
    cin >> n >> q;

    vector<ll int> a(n);
    ll int sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    int lastIdx = 0;
    int lastVal = 0;
    while(q--)
    {
        int type;
        cin >> type;

        if(type==1)
        {
            ll int pos, val;
            cin >> pos >> val;
            pos--; //Making 0-indexed

            if(lastVal)
            {
                a[pos] = lastVal;
            }
            sum -= a[pos];
            sum += val;
            lastIdx = pos;
            //Assigning the new val "after" subtracting it
            //a[pos] = val;

            cout << sum << endl;
        }
        else if(type==2)
        {
            ll int val;
            cin >> val;

            //memset(a,val,a.size());
            //fill(a.begin(),a.end(),val);
            sum = a.size()*val;
            lastVal = val;

            cout << sum << endl;
        }
    }

    return 0;
}
