// B. Seating in a Bus

// time limit per test2 seconds
// memory limit per test256 megabytes

// In Berland, a bus consists of a row of n seats numbered from 1 to n. Passengers are advised to always board the bus following these rules:

// If there are no occupied seats in the bus, a passenger can sit in any free seat;
// Otherwise, a passenger should sit in any free seat that has at least one occupied neighboring seat. In other words, a passenger can sit in a seat with index i (1≤i≤n) only if at least one of the seats with indices i−1 or i+1 is occupied.

// Today, n passengers boarded the bus. The array a chronologically records the seat numbers they occupied. That is, a1 contains the seat number where the first passenger sat, a2 — the seat number where the second passenger sat, and so on. You know the contents of the array a. Determine whether all passengers followed the recommendations. For example, if n=5, and a = [5,4,2,1,3], then the recommendations were not followed, as the 3-rd passenger sat in seat number 2, while the neighboring seats with numbers 1 and 3 were free.

// Input
// The first line of input contains a single integer t (1≤t≤104) — the number of test cases. The following describes the input test cases. The first line of each test case contains exactly one integer n (1≤n≤2⋅105) — the number of seats in the bus and the number of passengers who boarded the bus. The second line of each test case contains n distinct integers ai (1≤ai≤n) — the seats that the passengers occupied in chronological order. It is guaranteed that the sum of n values across all test cases does not exceed 2⋅105, and that no passenger sits in an already occupied seat.

// Output
// For each test case, output on a separate line: "YES", if all passengers followed the recommendations and "NO" otherwise. You may output the answer in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).

// Example
// InputCopy
// 4
// 5
// 5 4 2 1 3
// 3
// 2 3 1
// 4
// 2 3 1 4
// 5
// 1 2 3 5 4

// OutputCopy
// NO
// YES
// YES
// NO

// Note
// The first test case is explained in the problem statement.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    deque<int> seats;
    seats.push_back(a[0]);
    for(int i=1; i<n; i++)
    {
        if(a[i]<seats.front())
        {
            if(abs(a[i]-seats.front())==1)
            {
                seats.push_front(a[i]);
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        else if(a[i]>seats.back())
        {
            if(abs(a[i]-seats.back())==1)
            {
                seats.push_back(a[i]);
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
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
