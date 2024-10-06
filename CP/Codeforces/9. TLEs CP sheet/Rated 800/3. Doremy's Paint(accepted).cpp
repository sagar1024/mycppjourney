// A. Doremy's Paint 3

// time limit per test1 second
// memory limit per test256 megabytes

// An array b1,b2,…,bn of positive integers is good if all the sums of two adjacent elements are equal to the same value. More formally, the array is good if there exists a k such that b1+b2=b2+b3=…=bn−1+bn=k. Doremy has an array a of length n. Now Doremy can permute its elements (change their order) however she wants. Determine if she can make the array good.

// Input
// The input consists of multiple test cases. The first line contains a single integer t (1≤t≤100) — the number of test cases. The description of the test cases follows. The first line of each test case contains a single integer n (2≤n≤100) — the length of the array a. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤105). There are no constraints on the sum of n over all test cases.

// Output
// For each test case, print "Yes" (without quotes), if it is possible to make the array good, and "No" (without quotes) otherwise. You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

// Example
// InputCopy
// 5
// 2
// 8 9
// 3
// 1 1 2
// 4
// 1 1 4 5
// 5
// 2 3 3 3 3
// 4
// 100000 100000 100000 100000

// OutputCopy
// Yes
// Yes
// No
// No
// Yes

// Note
// In the first test case, [8,9] and [9,8] are good.
// In the second test case, [1,2,1] is good because a1+a2=a2+a3=3.
// In the third test case, it can be shown that no permutation is good.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// int maxx = 1e5+5;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     set<int> st;
//     //unordered_map<ll, ll> mp;
//     vector<int> freq(100005);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//         st.insert(a[i]);
//         freq[a[i]]++;
//     }

//     if(st.size()>2)
//     {
//         cout << "No" << endl;
//         return;
//     }

//     int one=0, two=0;
//     for(int i=0; i<100005; i++)
//     {
//         if(freq[i]!=0)
//         {
//             if(!one)
//             {
//                 one = a[i];
//             }
//             two = a[i];
//         }
//     }

//     if(one==two || abs(one-two)==1)
//     {
//         cout << "Yes" << endl;
//     }
//     else
//     {
//         cout << "No" << endl;
//     }

//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <set>
// #include <vector>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     set<int> st;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         st.insert(a[i]);
//     }

//     //If there are more than two distinct elements, it's impossible to make the array good
//     if (st.size() > 2)
//     {
//         cout << "No" << endl;
//         return;
//     }

//     //If there is exactly one distinct element, it's trivially good
//     if (st.size() == 1)
//     {
//         cout << "Yes" << endl;
//         return;
//     }

//     //Now we have exactly two distinct elements in the set
//     auto it = st.begin();

//     int one = *it;     // First distinct element
//     int two = *(++it); // Second distinct element

//     if (abs(one - two) == 1)
//     {
//         cout << "Yes" << endl;
//     }
//     else
//     {
//         cout << "No" << endl;
//     }

//     return;
// }

// int32_t main()
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

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;

        std::unordered_map<int, int> occ;
        for (int i = 0; i < n; ++i)
        {
            int x;
            std::cin >> x;
            occ[x]++;
        }

        if (occ.size() >= 3)
        {
            std::cout << "No" << std::endl;
        }
        else
        {
            auto it = occ.begin();
            int first = it->second;
            int second = (occ.size() == 2) ? (++it)->second : first;

            if (std::abs(first - second) <= 1)
            {
                std::cout << "Yes" << std::endl;
            }
            else
            {
                std::cout << "No" << std::endl;
            }
        }
    }
    return 0;
}
