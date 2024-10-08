// D. Friends and the Restaurant

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A group of n friends decide to go to a restaurant. Each of the friends plans to order meals for xi burles and has a total of yi burles (1≤i≤n). The friends decide to split their visit to the restaurant into several days. Each day, some group of at least two friends goes to the restaurant. Each of the friends visits the restaurant no more than once (that is, these groups do not intersect). These groups must satisfy the condition that the total budget of each group must be not less than the amount of burles that the friends in the group are going to spend at the restaurant. In other words, the sum of all xi values in the group must not exceed the sum of yi values in the group. What is the maximum number of days friends can visit the restaurant? For example, let there be n=6 friends for whom x = [8,3,9,2,4,5] and y = [5,3,1,4,5,10]. Then:

// first and sixth friends can go to the restaurant on the first day. They will spend 8+5=13 burles at the restaurant, and their total budget is 5+10=15 burles. Since 15≥13, they can actually form a group.
// friends with indices 2,4,5 can form a second group. They will spend 3+2+4=9 burles at the restaurant, and their total budget will be 3+4+5=12 burles (12≥9).

// It can be shown that they will not be able to form more groups so that each group has at least two friends and each group can pay the bill. So, the maximum number of groups the friends can split into is 2. Friends will visit the restaurant for a maximum of two days. Note that the 3-rd friend will not visit the restaurant at all. Output the maximum number of days the friends can visit the restaurant for given n, x and y.

// Input
// The first line of the input contains an integer t (1≤t≤104) — the number of test cases in the test. The descriptions of the test cases follow. The first line of each test case contains a single integer n (2≤n≤105) — the number of friends. The second line of each test case contains exactly n integers x1,x2,…,xn (1≤xi≤109). The value of xi corresponds to the number of burles that the friend numbered i plans to spend at the restaurant. The third line of each test case contains exactly n integers y1,y2,…,yn (1≤yi≤109). The value yi corresponds to the number of burles that the friend numbered i has. It is guaranteed that the sum of n values over all test cases does not exceed 105.

// Output
// For each test case, print the maximum number of days to visit the restaurant. If friends cannot form even one group to visit the restaurant, print 0.

// Example
// inputCopy
// 6
// 6
// 8 3 9 2 4 5
// 5 3 1 4 5 10
// 4
// 1 2 3 4
// 1 1 2 2
// 3
// 2 3 7
// 1 3 10
// 6
// 2 3 6 9 5 7
// 3 2 7 10 6 10
// 6
// 5 4 2 1 8 100
// 1 1 1 1 1 200
// 6
// 1 4 1 2 4 2
// 1 3 3 2 3 4

// outputCopy
// 2
// 0
// 1
// 3
// 1
// 3

// Note
// The first test case in explained in the problem statement.
// In the second test case, friends cannot form at least one group of two or more people.
// In the third test case, one way to visit the restaurant in one day is to go in a group of all three friends (1+3+10≥2+3+7). Note that they do not have the option of splitting into two groups.

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<long long int> x(n), y(n), diff(n);
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> y[i];
        diff[i] = y[i] - x[i];
    }

    sort(diff.begin(), diff.end());
    int ans = 0;
    int left=0, right=n-1;
    while(left<right)
    {
        if(diff[left]+diff[right]>=0)
        {
            ans += 1;
            left++;
            right--;
        }
        else
        {
            left++;
        }
    }

    cout << ans << endl;
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
