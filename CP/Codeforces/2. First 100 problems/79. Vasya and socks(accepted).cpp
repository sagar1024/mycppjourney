// A. Vasya and Socks

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Vasya has n pairs of socks. In the morning of each day Vasya has to put on a pair of socks before he goes to school. When he comes home in the evening, Vasya takes off the used socks and throws them away. Every m-th day (at days with numbers m, 2m, 3m, ...) mom buys a pair of socks to Vasya. She does it late in the evening, so that Vasya cannot put on a new pair of socks before the next day. How many consecutive days pass until Vasya runs out of socks?

// Input
// The single line contains two integers n and m (1 ≤ n ≤ 100; 2 ≤ m ≤ 100), separated by a space.

// Output
// Print a single integer — the answer to the problem.

// Examples
// Input
// 2 2
// Output
// 3
// Input
// 9 3
// Output
// 13

// Note
// In the first sample Vasya spends the first two days wearing the socks that he had initially. Then on day three he puts on the socks that were bought on day two.
// In the second sample Vasya spends the first nine days wearing the socks that he had initially. Then he spends three days wearing the socks that were bought on the third, sixth and ninth days. Than he spends another day wearing the socks that were bought on the twelfth day.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Initial num of socks
    int n;
    cin >> n;

    //One socks is bought on every mth day
    int m;
    cin >> m;

    int daysWithSocks = n;
    int daysOfBuying = 0;

    //Main logic
    while(daysWithSocks>0)
    {
        daysOfBuying++;
        if(daysOfBuying%m==0)
        {
            //Buying socks on every mth day
            daysWithSocks++;
        }
        daysWithSocks--;
    }

    //Num of days he put on a new pair of socks
    int totalNumOfDays = daysWithSocks + daysOfBuying;
    cout << totalNumOfDays << endl;

    return 0;
}