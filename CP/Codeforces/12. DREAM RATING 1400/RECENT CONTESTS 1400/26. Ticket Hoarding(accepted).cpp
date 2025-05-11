// C. Ticket Hoarding

// time limit per test2 seconds
// memory limit per test256 megabytes

// As the CEO of a startup company, you want to reward each of your k employees with a ticket to the upcoming concert. The tickets will be on sale for n days, and by some time travelling, you have predicted that the price per ticket at day i will be ai. However, to prevent ticket hoarding, the concert organizers have implemented the following measures: A person may purchase no more than m tickets per day. If a person purchases x tickets on day i, all subsequent days (i.e. from day i+1 onwards) will have their prices per ticket increased by x. For example, if a=[1,3,8,4,5] and you purchase 2 tickets on day 1, they will cost 2 in total, and the prices from day 2 onwards will become [5,10,6,7]. If you then purchase 3 more tickets on day 2, they will cost in total an additional 15, and the prices from day 3 onwards will become [13,9,10]. Find the minimum spending to purchase k tickets.

// Input
// Each test contains multiple test cases. The first line contains an integer t (1≤t≤104) — the number of test cases. The description of the test cases follows. The first line of each test case contains three integers n, m, and k (1≤n≤3⋅105,1≤m≤109,1≤k≤min(nm,109)) — the number of sale days, the maximum amount of ticket purchasable each day, and the number of tickets to be bought at the end. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the price per ticket for each of the upcoming n days. It is guaranteed that the sum of n over all test cases does not exceed 3⋅105.

// Output
// For each test case, print one integer: the minimum amount of money needed to purchase exactly k tickets.

// Example
// InputCopy
// 4
// 4 2 3
// 8 6 4 2
// 4 2 8
// 8 6 4 2
// 5 100 1
// 10000 1 100 10 1000
// 6 3 9
// 5 5 5 5 5 5
// OutputCopy
// 10
// 64
// 1
// 72

// Note
// In the first test case, one optimal way to buy 3 tickets is as follows:
// Buy 0 tickets on the first day. The prices per ticket for the remaining days are [6,4,2].
// Buy 0 tickets on the second day. The prices per ticket for the remaining days are [4,2].
// Buy 1 ticket on the third day with cost 4. The price per ticket for the remaining day is [3].
// Buy 2 tickets on the fourth day with cost 6.

// In the second test case, there is only one way to buy 8 tickets:
// Buy 2 tickets on the first day with cost 16. The prices per ticket for the remaining days are [8,6,4].
// Buy 2 tickets on the second day with cost 16. The prices per ticket for the remaining days are [8,6].
// Buy 2 tickets on the third day with cost 16. The price per ticket for the remaining day is [8].
// Buy 2 tickets on the fourth day with cost 16.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     ll int n, m, k;
//     cin >> n >> m >> k;

//     vector<ll int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     //We need k tickets
//     //Max allowed is m/day
//     //So num of days of purchase
//     ll int days = k/m;

//     //We need "days" num of cheapest days from the array
//     //AND keep adding additional m every next step
//     vector<ll int> a2;
//     a2 = a;
//     sort(a2.begin(),a2.end());

//     //Storing bag for keeping track of cheapest days
//     set<ll int> cheapestDays;
//     for(int i=0; i<days; i++)
//     {
//         cheapestDays.insert(a2[i]);
//     }

//     ll int ans = 0;
//     ll int currM = 0;
//     for(int i=0; i<n; i++)
//     {
//         if(cheapestDays.find(a[i])!=cheapestDays.end())
//         {
//             ans += (a[i]+currM)*m;
//             currM += m;

//             cheapestDays.erase(a[i]);
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
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    //We'll simulate increasing penalties as we go
    vector<pair<ll, int>> days;
    for (int i = 0; i < n; i++)
    {
        days.emplace_back(a[i], i); //(base cost, day index)
    }

    //Sort days by base price — we'll buy from cheapest first
    sort(days.begin(), days.end());

    ll totalCost = 0;
    ll penalty = 0;
    ll ticketsRemaining = k;
    for (auto [baseCost, index] : days)
    {
        if(ticketsRemaining == 0) break;

        ll buy = min(m, ticketsRemaining);
        totalCost += (baseCost + penalty) * buy;
        
        penalty += buy;
        ticketsRemaining -= buy;
    }

    cout << totalCost << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
