// D. Make It Round

// time limit per test1 second
// memory limit per test256 megabytes

// Inflation has occurred in Berlandia, so the store needs to change the price of goods. The current price of good n is given. It is allowed to increase the price of the good by k times, with 1≤k≤m, k is an integer. Output the roundest possible new price of the good. That is, the one that has the maximum number of zeros at the end. For example, the number 481000 is more round than the number 1000010 (three zeros at the end of 481000 and only one at the end of 1000010). If there are several possible variants, output the one in which the new price is maximal. If it is impossible to get a rounder price, output n⋅m (that is, the maximum possible price).

// Input
// The first line contains a single integer t (1≤t≤104) —the number of test cases in the test. Each test case consists of one line. This line contains two integers: n and m (1≤n,m≤109). Where n is the old price of the good, and the number m means that you can increase the price n no more than m times.

// Output
// For each test case, output on a separate line the roundest integer of the form n⋅k (1≤k≤m, k — an integer). If there are several possible variants, output the one in which the new price (value n⋅k) is maximal. If it is impossible to get a more rounded price, output n⋅m (that is, the maximum possible price).

// Example
// InputCopy
// 10
// 6 11
// 5 43
// 13 5
// 4 16
// 10050 12345
// 2 6
// 4 30
// 25 10
// 2 81
// 1 7
// OutputCopy
// 60
// 200
// 65
// 60
// 120600000
// 10
// 100
// 200
// 100
// 7

// Note
// In the first case n=6, m=11. We cannot get a number with two zeros or more at the end, because we need to increase the price 50 times, but 50>m=11. The maximum price multiple of 10 would be 6⋅10=60.
// In the second case n=5, m=43. The maximum price multiple of 100 would be 5⋅40=200.
// In the third case, n=13, m=5. All possible new prices will not end in 0, then you should output n⋅m=65.
// In the fourth case, you should increase the price 15 times.
// In the fifth case, increase the price 12000 times.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     ll int n, m;
//     cin >> n >> m;

//     vector<pair<ll int,ll int>> a;
//     for(ll int i=1; i<=m; i++)
//     {
//         ll int x = n*i;
//         ll int count = 0;
//         while(x%10==0)
//         {
//             x /= 10;
//             count++;
//         }
//         a.push_back({count,x});
//     }

//     sort(a.begin(),a.end(), greater<pair<ll int,ll int>>());
//     vector<ll int> b;
//     ll int i = 0;
//     while(a[0].first == a[i].first && i<m)
//     {
//         b.push_back(a[i].second);
//         i++;
//     }

//     sort(b.begin(),b.end(), greater<ll int>());

//     cout << b[0] << endl;

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

// Alternate soln(tle on tc3) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     ll int n, m;
//     cin >> n >> m;

//     vector<pair<ll int, ll int>> a;
//     for (ll int i = 1; i <= m; i++)
//     {
//         ll int x = n * i;
//         ll int count = 0;
//         while (x % 10 == 0)
//         {
//             x /= 10;
//             count++;
//         }
//         a.push_back({count, n * i});
//     }

//     //Sorting by the first value(count of trailing zeros) in descending order
//     //AND If tied, by the second value in descending order
//     sort(a.begin(), a.end(), [](const pair<ll, ll> &left, const pair<ll, ll> &right){
//         if (left.first == right.first)
//             return left.second > right.second; //Sort by the value itself if trailing zero count is the same
//         return left.first > right.first; });

//     //The first element now holds the maximum count of zeros with the highest possible value
//     cout << a[0].second << endl;

//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

// Optimization:

// Divisibility by 2 and 5:
// The number of trailing zeros in a number is determined by the minimum of the counts of factors 2 and 5.
// Therefore, to maximize the number of trailing zeros, we should try to increase the factors of 2 and 5 in the product n * k.

// Factorizing n:
// Start by determining how many times n can be divided by 2 and 5.
// Then, maximize the trailing zeros by multiplying n by a factor that increases the minimum count of these prime factors.

// Multiplying Efficiently:
// We should try to multiply n by the largest factor possible under the constraint k ≤ m.
// The idea is to find how many times we can multiply n by powers of 2 and 5 without exceeding m
// AND then take the remaining multiplier to maximize the result.

// Optimized Approach:

// Factor out 2s and 5s from n.
// Calculate how many times we can multiply by 2 and 5 within the limit m.
// Multiply by the remaining factor to stay within the limit m.
// Return the maximum possible value with the highest number of trailing zeros.

// #include <iostream>
// #include <algorithm>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     ll n, m;
//     cin >> n >> m;

//     //Factor of powers of 2 and 5 from n
//     ll count2 = 0, count5 = 0;
//     ll temp = n;
//     while (temp % 2 == 0)
//     {
//         count2++;
//         temp /= 2;
//     }
//     while (temp % 5 == 0)
//     {
//         count5++;
//         temp /= 5;
//     }

//     // ll int multiplier = 1;
//     // ll int n2 = n; //Dummy
//     // while(multiplier<=m && (multiplier%2==0 || multiplier%5==0))
//     // {
//     //     if(n%2==0 && multiplier*2<=m)
//     //     {
//     //         multiplier *= 2;
//     //         n /= 2;
//     //     }
//     //     if(n%5==0 && multiplier*5<=m)
//     //     {
//     //         multiplier *= 5;
//     //         n /= 5;
//     //     }
//     // }

//     //Factor of 2 and 5 from m
//     ll int x2 = 0, x5 = 0;
//     ll temp2 = m;
//     while(m%2==0)
//     {
//         x2++;
//         temp2 /= 2;
//     }
//     while(m%5==0)
//     {
//         x5++;
//         temp2 /= 5;
//     }

//     ll int two = count2 + x2;
//     ll int five = count5 + x5;

//     ll int ans = 1;
//     if(two>five)
//     {
//         ll int extra = two - five;
//         ans *= pow(10,five);
//         ans *= pow(2,extra);
//     }
//     else if(two<five)
//     {
//         ll int extra = five - two;
//         ans *= pow(10,two);
//         ans *= pow(2,extra);
//     }
//     else
//     {
//         ans *= pow(10,two);
//     }

//     cout << ans << endl;

//     return;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll n0 = n;
    int cnt2 = 0, cnt5 = 0;
    ll k = 1;

    //Counting factors of 2 and 5 in n
    while (n % 2 == 0)
    {
        n /= 2;
        cnt2++;
    }
    while (n % 5 == 0)
    {
        n /= 5;
        cnt5++;
    }

    //Balancing factors by multiplying k with 2 or 5
    while (cnt2 < cnt5 && k * 2 <= m)
    {
        cnt2++;
        k *= 2;
    }
    while (cnt5 < cnt2 && k * 5 <= m)
    {
        cnt5++;
        k *= 5;
    }

    //Maximizing k by multiplying with 10
    while (k * 10 <= m)
    {
        k *= 10;
    }

    //Final adjustment to ensure k * m/k is within bounds
    k *= m / k;

    cout << n0 * k << endl;
    return;
}

int main()
{
    int t;
    cin >> t;

    forn(tt, t)
    {
        solve();
    }

    return 0;
}
