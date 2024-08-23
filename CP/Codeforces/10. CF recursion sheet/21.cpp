// U. Knapsack

// time limit per test2 seconds
// memory limit per test256 megabytes

// There are N items numbered from 1 to N. The ith item has a weight of wi and a value of vi. You have to choose some items out of the N items and carry them home in a knapsack. The capacity of the knapsack is W which denote the maximum weight that can be carried inside the knapsack. In other words, W means the total summation of all weights of items that can be carried in the knapsack. Print maximum possible sum of values of items that you can take home. Note: Solve this problem using recursion.

// Input
// First line contains two numbers N and W (1≤N≤20,1≤W≤100) number of items and the capacity of the knapsack. Next N lines will contain two numbers wi and vi (1≤wi≤50,1≤vi≤1000)

// Output
// Print maximum possible sum of values of items that you can take home.

// Examples
// InputCopy
// 3 8
// 3 30
// 4 50
// 5 60
// OutputCopy
// 90

// InputCopy
// 6 15
// 6 5
// 5 6
// 6 4
// 6 6
// 3 5
// 7 2
// OutputCopy
// 17

//My original soln -

//Base Case: If there are no items left (n == 0) or the knapsack capacity is 0 (W == 0), the maximum value is 0.
//Recursive Case: If the weight of the current item exceeds the current knapsack capacity, the item cannot be included, so the maximum value is the same as if this item didn't exist (knapsack(n-1, W)).
//Else: We consider both possibilities (including or excluding the item) and choose the one that gives the maximum value.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int knapsack(int n, int w, vector<int> &weights, vector<int> &values)
{
    if(n==0 || w==0)
    {
        return 0;
    }

    if(weights[n-1]>w)
    {
        return knapsack(n-1,w,weights,values);
    }
    else
    {
        int includeItem = values[n-1] + knapsack(n-1,w-weights[n-1],weights,values);
        int excludeItem = knapsack(n-1, w, weights, values);

        return max(includeItem,excludeItem);
    }
}

int32_t main()
{
    int n, w;
    cin >> n >> w;

    vector<int> weights(n), values(n);
    for(int i=0; i<n; i++)
    {
        cin >> weights[i] >> values[i];
    }

    int maxVal = knapsack(n, w, weights, values);
    cout << maxVal << endl;

    return 0;
}
