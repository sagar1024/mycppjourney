// A. Laptops

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// One day Dima and Alex had an argument about the price and quality of laptops. Dima thinks that the more expensive a laptop is, the better it is. Alex disagrees. Alex thinks that there are two laptops, such that the price of the first laptop is less (strictly smaller) than the price of the second laptop but the quality of the first laptop is higher (strictly greater) than the quality of the second laptop. Please, check the guess of Alex. You are given descriptions of n laptops. Determine whether two described above laptops exist.

// Input
// The first line contains an integer n (1 ≤ n ≤ 105) — the number of laptops. Next n lines contain two integers each, ai and bi (1 ≤ ai, bi ≤ n), where ai is the price of the i-th laptop, and bi is the number that represents the quality of the i-th laptop (the larger the number is, the higher is the quality). All ai are distinct. All bi are distinct.

// Output
// If Alex is correct, print "Happy Alex", otherwise print "Poor Alex" (without the quotes).

// Examples
// inputCopy
// 2
// 1 2
// 2 1
// outputCopy
// Happy Alex

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Num of laptops
    int n;
    cin >> n;

    //Price and quality of each laptop
    vector<pair<int,int>> pnq(n);
    for(int i=0; i<n; i++)
    {
        cin >> pnq[i].first;
        cin >> pnq[i].second;
    }

    //MAIN logic

    //Sorting the laptops based on prices
    //sort(pnq.begin(), pnq.end());

    //Checking for both types of laptops
    bool morePriceThanQuality = false;
    bool moreQualityThanPrice = false;

    for(int i=0; i<n; i++)
    {
        //First type
        if(pnq[i].first > pnq[i].second)
        {
            morePriceThanQuality = true;
        }
        //Second type
        if(pnq[i].first < pnq[i].second)
        {
            moreQualityThanPrice = true;
        }
    }

    //If both type of laptops exists
    if(morePriceThanQuality && moreQualityThanPrice)
    {
        cout << "Happy Alex" << endl;
    }
    else
    {
        cout << "Poor Alex" << endl;
    }

    return 0;
}
