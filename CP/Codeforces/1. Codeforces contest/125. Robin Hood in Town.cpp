// C. Robin Hood in Town

// time limit per test2 seconds
// memory limit per test256 megabytes

// In Sherwood, we judge a man not by his wealth, but by his merit. Look around, the rich are getting richer, and the poor are getting poorer. We need to take from the rich and give to the poor. We need Robin Hood! There are n people living in the town. Just now, the wealth of the i-th person was ai gold. But guess what? The richest person has found an extra pot of gold! More formally, find an aj=max(a1,a2,…,an), change aj to aj+x, where x is a non-negative integer number of gold found in the pot. If there are multiple maxima, it can be any one of them. A person is unhappy if their wealth is strictly less than half of the average wealth∗. If strictly more than half of the total population n are unhappy, Robin Hood will appear by popular demand. Determine the minimum value of x for Robin Hood to appear, or output −1 if it is impossible. The average wealth is defined as the total wealth divided by the total population n, that is, ∑ain, the result is a real number.

// Input
// The first line of input contains one integer t (1≤t≤104) — the number of test cases. The first line of each test case contains an integer n (1≤n≤2⋅105) — the total population. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤106) — the wealth of each person. It is guaranteed that the sum of n across all test cases does not exceed 2⋅105.

// Output
// For each test case, output one integer — the minimum number of gold that the richest person must find for Robin Hood to appear. If it is impossible, output −1 instead.

// Example
// InputCopy
// 6
// 1
// 2
// 2
// 2 19
// 3
// 1 3 20
// 4
// 1 2 3 4
// 5
// 1 2 3 4 5
// 6
// 1 2 1 1 1 25
// OutputCopy
// -1
// -1
// 0
// 15
// 16
// 0

// Note
// In the first test case, it is impossible for a single person to be unhappy.
// In the second test case, there is always 1 happy person (the richest).
// In the third test case, no additional gold are required, so the answer is 0.
// In the fourth test case, after adding 15 gold, the average wealth becomes 254, and half of this average is 258, resulting in 3 people being unhappy.
// In the fifth test case, after adding 16 gold, the average wealth becomes 315, resulting in 3 people being unhappy.

// My original soln -
 
// #include <iostream>
// #include <bits/stdc++.h>
 
// using namespace std;
// #define ll long long
 
// void solve()
// {
//     int n;
//     cin >> n;
 
//     vector<int> a(n);
//     int sum = 0;
//     int max_a = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         sum += a[i];
//         max_a = max(max_a, a[i]);
//     }
 
//     //Case 1: If n == 1, it's impossible for anyone to be unhappy.
//     if (n == 1 || n==2)
//     {
//         cout << -1 << endl;
//         return;
//     }
 
//     int result = max(0, ((sum + n - 2) / (n - 1)) - max_a);
//     cout << result << endl;
 
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
 
// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
 
long long solve(int n, vector<long long> &wealth)
{
    if (n == 1) return -1; // Impossible for a single person to be unhappy
 
    long long sum = 0;
    long long max_wealth = 0;
 
    for (int i = 0; i < n; i++)
    {
        sum += wealth[i];
        max_wealth = max(max_wealth, wealth[i]);
    }
 
    long long left = 0;
    //long long right = 1e18; //A large upper bound
    long long right = 1e7+7;
    long long result = -1;
 
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        long long new_sum = sum + mid;
        double avg = (double)new_sum / n;
        int unhappy_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == max_element(wealth.begin(), wealth.end()) - wealth.begin())
            {
                if (wealth[i] + mid < avg / 2) unhappy_count++;
            }
            else
            {
                if (wealth[i] < avg / 2) unhappy_count++;
            }
        }
 
        if (unhappy_count > n / 2)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
 
    return result;
}
 
int main()
{
    int t;
    cin >> t;
 
    while (t--)
    {
        int n;
        cin >> n;
 
        vector<long long> wealth(n);
        for (int i = 0; i < n; i++)
        {
            cin >> wealth[i];
        }
 
        cout << solve(n, wealth) << endl;
    }
 
    return 0;
}
