// A. Setting up Camp

// time limit per test1 second
// memory limit per test256 megabytes

// The organizing committee plans to take the participants of the Olympiad on a hike after the tour. Currently, the number of tents needed to be taken is being calculated. It is known that each tent can accommodate up to 3 people. Among the participants, there are a introverts, b extroverts, and c universals:
// Each introvert wants to live in a tent alone. Thus, a tent with an introvert must contain exactly one person — only the introvert himself.
// Each extrovert wants to live in a tent with two others. Thus, the tent with an extrovert must contain exactly three people.
// Each universal is fine with any option (living alone, with one other person, or with two others).

// The organizing committee respects the wishes of each participant very much, so they want to fulfill all of them. Tell us the minimum number of tents needed to be taken so that all participants can be accommodated according to their preferences. If it is impossible to accommodate the participants in a way that fulfills all the wishes, output −1.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. This is followed by the descriptions of the test cases. Each test case is described by a single line containing three integers a, b, c (0≤a,b,c≤109) — the number of introverts, extroverts, and universals, respectively.

// Output
// For each test case, output a single integer — the minimum number of tents, or −1 if it is impossible to accommodate the participants.

// Example
// InputCopy
// 10
// 1 2 3
// 1 4 1
// 1 4 2
// 1 1 1
// 1 3 2
// 19 7 18
// 0 0 0
// 7 0 0
// 0 24 0
// 1000000000 1000000000 1000000000
// OutputCopy
// 3
// -1
// 3
// -1
// 3
// 28
// 0
// 7
// 8
// 1666666667

// Note
// In the first test case, 1 tent will be given to the introverts, 1 tent will be shared by two extroverts and one universal, and the last tent will be shared by two universals. In total, 3 tents are needed.
// In the second test case, three extroverts will take 1 tent, and 1 tent will be taken by an introvert. Then, one extrovert and one universal will be left. This extrovert will not be able to live with two others.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    // if((b+c)%3!=0 && b>c)
    // {
    //     cout << "-1" << endl;
    //     return;
    // }

    // int ans = a+(b+c)+2/3;
    // cout << ans << endl;

    //Step 1: Calculate the number of tents required by introverts
    long long tents_for_introverts = a;

    //Step 2: Calculate tents required for extroverts and universals
    long long total_people = b + c;

    //Condition to check if it's possible to satisfy extrovert requirements
    if (b > total_people / 2)
    {
        cout << -1 << endl;
        return;
    }

    //Step 3: Calculate minimum tents, rounding up (b+c+2)/3 covers rounding up for three-person tents
    long long tents_for_others = (total_people + 2) / 3;
    long long total_tents = tents_for_introverts + tents_for_others;

    cout << total_tents << endl;

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
