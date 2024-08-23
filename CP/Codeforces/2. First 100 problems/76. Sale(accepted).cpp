// B. Sale

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Once Bob got to a sale of old TV sets. There were n TV sets at that sale. TV set with index i costs ai bellars. Some TV sets have a negative price — their owners are ready to pay Bob if he buys their useless apparatus. Bob can «buy» any TV sets he wants. Though he's very strong, Bob can carry at most m TV sets, and he has no desire to go to the sale for the second time. Please, help Bob find out the maximum sum of money that he can earn.

// Input
// The first line contains two space-separated integers n and m (1 ≤ m ≤ n ≤ 100) — amount of TV sets at the sale, and amount of TV sets that Bob can carry. The following line contains n space-separated integers ai ( - 1000 ≤ ai ≤ 1000) — prices of the TV sets.

// Output
// Output the only number — the maximum sum of money that Bob can earn, given that he can carry at most m TV sets.

// Examples
// Input
// 5 3
// -6 0 35 -2 4
// Output
// 8

// Input
// 4 2
// 7 0 0 -7
// Output
// 7

//My original soln

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Num of TV sets at the sale
    int n;
    cin >> n;

    //Num of TV sets Bob can carry
    int m;
    cin >> m;

    //Prices of the TVs
    vector<int> tvPrices(n);
    for(int i=0; i<n; i++)
    {
        cin >> tvPrices[i];
    }

    //Sorting the array of prices to get the largest -ve numbers ahead
    sort(tvPrices.begin(), tvPrices.end());

    //Calculating the amt of money Bob can earn
    int sum = 0;
    for(int i=0; i<m; i++)
    {
        //Only buying TVs with -ve prices
        if(tvPrices[i]<=0)
        {
            //Adding the first m TV's -ve prices
            sum += tvPrices[i];
        }
    }

    //Printing the amt of money Bob earned
    cout << -sum << endl;

    return 0;
}