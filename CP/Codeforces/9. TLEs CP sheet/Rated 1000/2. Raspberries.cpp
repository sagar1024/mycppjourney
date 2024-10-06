// C. Raspberries

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given an array of integers a1,a2,…,an and a number k (2≤k≤5). In one operation, you can do the following: Choose an index 1≤i≤n, Set ai=ai+1. Find the minimum number of operations needed to make the product of all the numbers in the array a1⋅a2⋅…⋅an divisible by k.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. Then follows the description of the test cases. The first line of each test case contains two integers n and k (2≤n≤105, 2≤k≤5) — the size of the array a and the number k. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤10). It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output the minimum number of operations needed to make the product of all the numbers in the array divisible by k.

// Example
// InputCopy
// 15
// 2 5
// 7 3
// 3 3
// 7 4 1
// 5 2
// 9 7 7 3 9
// 5 5
// 5 4 1 2 3
// 7 4
// 9 5 1 5 9 5 1
// 3 4
// 6 3 6
// 3 4
// 6 1 5
// 3 4
// 1 5 9
// 4 4
// 1 4 1 1
// 3 4
// 3 5 3
// 4 5
// 8 9 9 3
// 2 5
// 1 6
// 2 5
// 10 10
// 4 5
// 1 6 1 1
// 2 5
// 7 7
// OutputCopy
// 2
// 2
// 1
// 0
// 2
// 0
// 1
// 2
// 0
// 1
// 1
// 4
// 0
// 4
// 3

// Note
// In the first test case, we need to choose the index i=2 twice. After that, the array will be a=[7,5]. The product of all the numbers in the array is 35.
// In the fourth test case, the product of the numbers in the array is 120, which is already divisible by 5, so no operations are needed.
// In the eighth test case, we can perform two operations by choosing i=2 and i=3 in any order. After that, the array will be a=[1,6,10]. The product of the numbers in the array is 60.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         int n, k;
//         cin >> n >> k;

//         vector<int> a(n);
//         for(int i=0; i<n; i++)
//         {
//             cin >> a[i];
//         }

//         if(k==2 || k==3 || k==5)
//         {
//             for(int i=0; i<n; i++)
//             {
//                 a[i] = a[i]%k;
//             }
//             sort(a.begin(), a.end());
//             cout << a[0] << endl;
//         }
//         else if(k==4)
//         {
//             if(n==1)
//             {
//                 cout << k-n << endl;
//             }
//             else
//             {
//                 int evenCount = 0;
//                 for(int i=0; i<n; i++)
//                 {
//                     if(a[i]%2==0)
//                     {
//                         evenCount++;
//                     }
//                 }

//                 cout << 2-evenCount << endl;
//             }
//         }
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        int count2 = 0, count3 = 0, count5 = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
                count2++;
            if (a[i] % 3 == 0)
                count3++;
            if (a[i] % 5 == 0)
                count5++;
        }

        int operations = 0;

        if (k == 2)
        {
            //Need at least one even number
            if (count2 == 0)
                operations = 1;
        }
        else if (k == 3)
        {
            //Need at least one number divisible by 3
            if (count3 == 0)
                operations = 1;
        }
        else if (k == 4)
        {
            if (n == 1)
            {
                //If only one element, it must be made divisible by 4
                if (a[0] % 4 != 0)
                    operations = (a[0] % 2 == 0) ? 1 : 2;
            }
            else
            {
                //Need at least two even numbers
                operations = max(0, 2 - count2);
            }
        }
        else if (k == 5)
        {
            //Need at least one number divisible by 5
            if (count5 == 0)
                operations = 1;
        }

        cout << operations << endl;
    }

    return 0;
}
