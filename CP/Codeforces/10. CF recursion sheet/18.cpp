// R. Palindrome Array

// time limit per test1 second
// memory limit per test256 megabytes

// Given a number N and an array A of N numbers. Determine if it's palindrome or not. Note: An array is called palindrome if it reads the same backward and forward, for example, arrays { 1 } and { 1,2,3,2,1 } are palindromes, while arrays { 1,12 } and { 4,7,5,4 } are not. NOTE: Solve it using recursion.

// Input
// First line contains a number N (1 ≤ N ≤ 105) number of elements. Second line contains N numbers (1 ≤ Ai ≤ 109).

// Output
// Print "YES" (without quotes) if A is a palindrome array, otherwise, print "NO" (without quotes).

// Examples
// InputCopy
// 5
// 1 3 2 3 1
// OutputCopy
// YES

// InputCopy
// 4
// 1 2 3 4
// OutputCopy
// NO

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void evenn(vector<long long int>&a, int n, stack<int>&st)
// {
//     if(n==0)
//     {
//         return;
//     }
//     evenn(a,n-1,st);
//     if(a[n]==st.top())
//     {
//         st.pop();
//     }
//     else
//     {
//         st.push(a[n]);
//     }
// }

// void oddn(vector<long long int>&a, int n, stack<int>&st)
// {
//     //Just return
//     return;
// }

// int32_t main()
// {
//     int n;
//     cin >> n;

//     vector<long long int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     stack<int> st;

//     if(n%2==0) evenn(a,n,st);
//     else oddn(a,n,st);

//     if(st.empty())
//     {
//         cout << "YES" << endl;
//     }
//     else
//     {
//         cout << "NO" << endl;
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool yes(vector<long long int>&arr, int left, int right)
{
    if(left>=right)
    {
        return true;
    }
    if(arr[left]!=arr[right])
    {
        return false;
    }

    yes(arr,left+1,right-1);
}

int32_t main()
{
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    if(yes(a,0,n-1))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
