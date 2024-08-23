// C. Dolce Vita

// time limit per test2 seconds
// memory limit per test256 megabytes

// Turbulent times are coming, so you decided to buy sugar in advance. There are n shops around that sell sugar: the i-th shop sells one pack of sugar for ai coins, but only one pack to one customer each day. So in order to buy several packs, you need to visit several shops. Another problem is that prices are increasing each day: during the first day the cost is ai, during the second day cost is ai+1, during the third day — ai+2 and so on for each shop i. On the contrary, your everyday budget is only x coins. In other words, each day you go and buy as many packs as possible with total cost not exceeding x. Note that if you don't spend some amount of coins during a day, you can't use these coins during the next days. Eventually, the cost for each pack will exceed x, and you won't be able to buy even a single pack. So, how many packs will you be able to buy till that moment in total?

// Input
// The first line contains a single integer t (1≤t≤1000) — the number of test cases. Next t cases follow. The first line of each test case contains two integers n and x (1≤n≤2⋅105; 1≤x≤109) — the number of shops and your everyday budget. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the initial cost of one pack in each shop. It's guaranteed that the total sum of n doesn't exceed 2⋅105.

// Output
// For each test case, print one integer — the total number of packs you will be able to buy until prices exceed your everyday budget.

// Example
// InputCopy
// 4
// 3 7
// 2 1 2
// 5 9
// 10 20 30 40 50
// 1 1
// 1
// 2 1000
// 1 1
// OutputCopy
// 11
// 0
// 1
// 1500

// Note
// In the first test case,
// Day 1: prices are [2,1,2]. You can buy all 3 packs, since 2+1+2≤7.
// Day 2: prices are [3,2,3]. You can't buy all 3 packs, since 3+2+3>7, so you buy only 2 packs.
// Day 3: prices are [4,3,4]. You can buy 2 packs with prices 4 and 3.
// Day 4: prices are [5,4,5]. You can't buy 2 packs anymore, so you buy only 1 pack.
// Day 5: prices are [6,5,6]. You can buy 1 pack.
// Day 6: prices are [7,6,7]. You can buy 1 pack.
// Day 7: prices are [8,7,8]. You still can buy 1 pack of cost 7.
// Day 8: prices are [9,8,9]. Prices are too high, so you can't buy anything.
// In total, you bought 3+2+2+1+1+1+1=11 packs.

// In the second test case, prices are too high even at the first day, so you can't buy anything.
// In the third test case, you can buy only one pack at day one.
// In the fourth test case, you can buy 2 packs first 500 days. At day 501 prices are [501,501], so you can buy only 1 pack the next 500 days. At day 1001 prices are [1001,1001] so can't buy anymore. In total, you bought 500⋅2+500⋅1=1500 packs.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// ll int totalPacks(vector<ll int>&a, ll int budget, ll int mid)
// {
//     ll int tp = 0;
//     for(int i=0; i<=mid; i++)
//     {
//         ll int bgt = budget;
//         for(int j=0; j<a.size() && bgt>=0; j++)
//         {
//             if(a[j]+i<=budget)
//             {
//                 tp++;
//                 bgt -= a[j]+i;
//                 if(bgt<=0)
//                 {
//                     break;
//                 }
//             }
//         }
//     }

//     return tp;
// }

// void solve()
// {
//     ll int n, x;
//     cin >> n >> x;

//     vector<ll int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     sort(a.begin(), a.end());

//     ll int left = 0, right = 200005;
//     ll int ans = 0;
//     while(left<right)
//     {
//         ll int mid = (left+right)/2;
//         if(totalPacks(a,x,mid)>=ans)
//         {
//             ans = mid;
//             left = mid+1;
//         }
//         else
//         {
//             right = mid-1;
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
#define ll long long

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll sum = accumulate(a.begin(), a.end(), 0LL); //Sum of all elements in a
    ll prevDay = -1;
    ll ans = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        //Purpose: Calculate the maximum day (curDay) up to which you can still afford to buy a pack from the current and all cheaper shops
        //Explanation: x - sum: Represents how much of your budget is left after subtracting the sum of prices of all the packs on the first day
        //Here (x - sum) / (i + 1): Determines how many additional days you can afford to keep buying packs from the first i + 1 shops, because on each subsequent day, the price increases by 1 for each shop
        ll curDay = (x - sum >= 0) ? (x - sum) / (i + 1) : -1;

        //Purpose: Calculate the total number of packs you can buy for the days between prevDay and curDay
        //Explanation: i + 1: This is the number of shops currently under consideration
        //Here (curDay - prevDay): This gives the number of days you can continue buying packs (from prevDay + 1 to curDay)
        ans += (i + 1) * (curDay - prevDay);
        prevDay = curDay;

        //Subtract the price of the current shop from sum because in the next iteration, you're only considering the cheaper shops. This step simulates the effect of having bought a pack from the current shop, reducing the overall sum of the shop prices for future iterations
        sum -= a[i];
    }

    cout << ans << endl;
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
