// C. Sakurako's Field Trip

// time limit per test2 seconds
// memory limit per test256 megabytes

// Even in university, students need to relax. That is why Sakurakos teacher decided to go on a field trip. It is known that all of the students will be walking in one line. The student with index i has some topic of interest which is described as ai. As a teacher, you want to minimise the disturbance of the line of students. The disturbance of the line is defined as the number of neighbouring people with the same topic of interest. In other words, disturbance is the number of indices j (1≤j<n) such that aj=aj+1. In order to do this, you can choose index i (1≤i≤n) and swap students at positions i and n−i+1. You can perform any number of swaps. Your task is to determine the minimal amount of disturbance that you can achieve by doing the operation described above any number of times.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. Each test case is described by two lines. The first line contains one integer n (2≤n≤105) — the length of the line of students. The second line contains n integers ai (1≤ai≤n) — the topics of interest of students in line. It is guaranteed that the sum of n across all test cases does not exceed 2⋅105.

// Output
// For each test case, output the minimal possible disturbance of the line that you can achieve.

// Example
// InputCopy
// 9
// 5
// 1 1 1 2 3
// 6
// 2 1 2 2 1 1
// 4
// 1 2 1 1
// 6
// 2 1 1 2 2 4
// 4
// 2 1 2 3
// 6
// 1 2 2 1 2 1
// 5
// 4 5 5 1 5
// 7
// 1 4 3 5 1 1 3
// 7
// 3 1 3 2 2 3 3
// OutputCopy
// 1
// 2
// 1
// 0
// 0
// 1
// 1
// 0
// 2

// Note
// In the first example, it is necessary to apply the operation to i=2, thus the array will become [1,2,1,1,3], with the bold elements indicating those that have swapped places. The disturbance of this array is equal to 1.
// In the fourth example, it is sufficient to apply the operation to i=3, thus the array will become [2,1,2,1,2,4]. The disturbance of this array is equal to 0.
// In the eighth example, it is sufficient to apply the operation to i=3, thus the array will become [1,4,1,5,3,1,3]. The disturbance of this array is equal to 0.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    // int left = 0, right = 0;
    // if(n%2==0)
    // {
    //     left = n/2 - 1; //0 indexed
    //     right = left + 1;
    // }
    // else
    // {
    //     left = n/2 - 1;
    //     right = left + 2;
    // }

    // while(left>=0 && right<n)
    // {
    //     if((left-1>=0 && a[left]==a[left-1]) || (right+1<n && a[right]==a[right+1]))
    //     {
    //         int temp = a[left];
    //         a[left] = a[right];
    //         a[right] = temp;
    //     }

    //     left--;
    //     right++;
    // }

    for(int i=n/2-2; i>=0; i--)
    {
        if((a[i]==a[i+1]) ||(a[n-i-1]==a[n-i-2]))
        {
            swap(a[i],a[n-i-1]);
        }
    }

    int ans = 0;
    for(int i=1; i<a.size(); i++)
    {
        if(a[i-1]==a[i])
        {
            ans++;
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
