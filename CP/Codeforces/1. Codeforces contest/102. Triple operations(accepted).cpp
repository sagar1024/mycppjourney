// E. Triple Operations

// time limit per test1 second
// memory limit per test256 megabytes

// On the board Ivy wrote down all integers from l to r, inclusive. In an operation, she does the following: pick two numbers x and y on the board, erase them, and in their place write the numbers 3x and ⌊y3⌋. (Here ⌊∙⌋ denotes rounding down to the nearest integer). What is the minimum number of operations Ivy needs to make all numbers on the board equal 0? We have a proof that this is always possible.

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases. The only line of each test case contains two integers l and r (1≤l<r≤2⋅105).

// Output
// For each test case, output a single integer — the minimum number of operations needed to make all numbers on the board equal 0.

// Example
// InputCopy
// 4
// 1 3
// 2 4
// 199999 200000
// 19 84
// OutputCopy
// 5
// 6
// 36
// 263

// Note
// In the first test case, we can perform 5 operations as follows:1,2,3−→−−−−x=1,y=23,0,3−→−−−−x=0,y=31,0,3−→−−−−x=0,y=31,0,1−→−−−−x=0,y=10,0,1−→−−−−x=0,y=10,0,0.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int min_operations(int l, int r)
// {
//     //Priority queues to handle the largest and smallest numbers
//     priority_queue<int> max_heap;
//     priority_queue<int, vector<int>, greater<int>> min_heap;

//     //Inserting all numbers from l to r into both heaps
//     for (int i = l; i <= r; ++i)
//     {
//         max_heap.push(i); //Largest element on top
//         min_heap.push(i); //Smallest elemnt on top
//     }

//     int operations = 0;
//     while (!max_heap.empty())
//     {
//         // Get the largest number
//         int max_num = max_heap.top();
//         max_heap.pop();

//         // Get the smallest number
//         int min_num = min_heap.top();
//         min_heap.pop();

//         // If all numbers have been reduced to zero
//         if (max_num == 0)
//         {
//             break;
//         }

//         //Reducing the largest number by one third
//         int reduced_num = round((float)max_num) / 3;
//         if (reduced_num > 0)
//         {
//             max_heap.push(reduced_num);
//         }

//         //Thricing the smallest number
//         int increased_num = min_num * 3;
//         min_heap.push(increased_num);

//         operations++;
//     }

//     return operations;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int l, r;
//         cin >> l >> r;
//         int ans = min_operations(l,r);

//         cout << ans << endl;
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> arr(200005,0);

void precompute()
{
    arr[1] = 1;
    for(int i=2; i<200005; i++)
    {
        int count = 0;
        int n = i;
        while(n>0)
        {
            n /= 3;
            count++;
        }

        arr[i] = arr[i-1]+count;
    }
}
void solve()
{
    int l, r;
    cin >> l >> r;

    cout << arr[r] + arr[l] - 2*arr[l-1] << endl;
    return;
}

int32_t main()
{
    precompute();

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
