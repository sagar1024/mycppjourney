// B. Olya and Game with Arrays

// time limit per test1 second
// memory limit per test256 megabytes

// Artem suggested a game to the girl Olya. There is a list of n arrays, where the i-th array contains mi≥2 positive integers ai,1,ai,2,…,ai,mi. Olya can move at most one (possibly 0) integer from each array to another array. Note that integers can be moved from one array only once, but integers can be added to one array multiple times, and all the movements are done at the same time. The beauty of the list of arrays is defined as the sum ∑ni=1minmij=1ai,j. In other words, for each array, we find the minimum value in it and then sum up these values. The goal of the game is to maximize the beauty of the list of arrays. Help Olya win this challenging game!

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤25000) — the number of test cases. The description of test cases follows. The first line of each test case contains a single integer n (1≤n≤25000) — the number of arrays in the list. This is followed by descriptions of the arrays. Each array description consists of two lines. The first line contains a single integer mi (2≤mi≤50000) — the number of elements in the i-th array. The next line contains mi integers ai,1,ai,2,…,ai,mi (1≤ai,j≤109) — the elements of the i-th array. It is guaranteed that the sum of mi over all test cases does not exceed 50000.

// Output
// For each test case, output a single line containing a single integer — the maximum beauty of the list of arrays that Olya can achieve.

// Example
// InputCopy
// 3
// 2
// 2
// 1 2
// 2
// 4 3
// 1
// 3
// 100 1 6
// 3
// 4
// 1001 7 1007 5
// 3
// 8 11 6
// 2
// 2 9

// OutputCopy
// 5
// 1
// 19

// Note
// In the first test case, we can move the integer 3 from the second array to the first array. Then the beauty is min(1,2,3)+min(4)=5. It can be shown that this is the maximum possible beauty.
// In the second test case, there is only one array, so regardless of the movements, the beauty will be min(100,1,6)=1.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// vector<vector<ll int>> a;

// void solve()
// {
//     int n;
//     cin >> n;

//     ll int minn = 0; //Smallest number in all arrays
//     int idx = 0; //Index of the row where the smallest num was found
//     for(int i=1; i<=n; i++)
//     {
//         int m;
//         cin >> m;

//         vector<ll int> a2;
//         for(int j=0; j<m; j++)
//         {
//             ll int x;
//             cin >> x;

//             a2.push_back(x);

//             if(minn>a2[j])
//             {
//                 minn = a2[j];
//                 idx = i-1;
//             }
//         }

//         sort(a2.begin(), a2.end());
//         a.push_back(a2);
//     }

//     //We will push the smallest number from each array
//     //To the array with the smallest element
//     //AND then add the second smallest numbers of each array + minn
//     ll int ans = 0;
//     ans += minn;
//     for(int i=0; i<n; i++)
//     {
//         if(i==idx)
//         {
//             continue;
//         }
//         else
//         {
//             ans += a[i][1];
//         }
//     }

//     cout << ans << endl;
//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;
#define all(v) v.begin(), v.end()

typedef long long ll;
const int INF = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    int global_min = INF;
    vector<int> second_mins;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        vector<int> array(m);
        for(int &num : array) cin >> num;

        int min_val = *min_element(all(array));
        global_min = min(global_min, min_val);
        auto it = find(all(array), min_val);
        array.erase(it);
        if (!array.empty())
        {
            second_mins.push_back(*min_element(all(array)));
        }
    }

    int smallest_second_min = *min_element(all(second_mins));
    ll sum_second_mins = accumulate(all(second_mins), 0ll);

    cout << global_min + sum_second_mins - smallest_second_min << "\n";

    return;
}

int main()
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
