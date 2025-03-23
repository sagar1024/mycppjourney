// C. DIY

// time limit per test2 seconds
// memory limit per test512 megabytes

// You are given a list of n integers a1,a2,…,an. You need to pick 8 elements from the list and use them as coordinates of four points. These four points should be corners of a rectangle which has its sides parallel to the coordinate axes. Your task is to pick coordinates in such a way that the resulting rectangle has the maximum possible area. The rectangle can be degenerate, i. e. its area can be 0. Each integer can be used as many times as it occurs in the list (or less).

// Input
// The first line contains one integer t (1≤t≤25000) — the number of test cases. The first line of each test case contains one integer n (8≤n≤2⋅105). The second line of each test case contains n integers a1,a2,…,an (−109≤ai≤109). Additional constraint on the input: the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print the answer as follows: if it is impossible to construct a rectangle which meets the constraints from the statement, print a single line containing the word NO (case-insensitive); otherwise, in the first line, print YES (case-insensitive). In the second line, print 8 integers x1,y1,x2,y2,x3,y3,x4,y4 — the coordinates of the corners of the rectangle. You can print the corners in any order.

// Example
// InputCopy
// 3
// 16
// -5 1 1 2 2 3 3 4 4 5 5 6 6 7 7 10
// 8
// 0 0 -1 2 2 1 1 3
// 8
// 0 0 0 0 0 5 0 5

// OutputCopy
// YES
// 1 2 1 7 6 2 6 7
// NO
// YES
// 0 0 0 5 0 0 0 5

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    map<ll int,ll int> mp;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    //Array with two coordinates
    vector<ll int> coor;

    //For iterating the map we can use -

    //Iterating using range-based for loop
    // for(const auto& [key, value] : mp)
    // {
    //     cout << "Key: " << key << " & " << "Value: " << value << endl;
    // }

    int pairs = 0;

    //We can also use -
    for(auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        if(iter->second >= 2)
        {
            for(int i=1; i<=(iter->second)/2; i++) coor.push_back(iter->first);
            //pairs += (iter->second)/2;
        }
    }

    // if(pairs<4)
    // {
    //     cout << "NO" << endl;
    //     return;
    // }
    if(coor.size()<4)
    {
        cout << "NO" << endl;
        return;
    }

    int len = coor.size();
    sort(coor.begin(), coor.end());

    ll int a1 = coor[0];
    ll int b = coor[1];
    ll int c = coor[len-2];
    ll int d = coor[len-1];

    cout << "YES" << endl;
    cout << a1 << " " << b << " " << a1 << " " << d << " " << c << " " << b << " " << c << " " << d << endl;

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
