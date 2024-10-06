// E. Add Modulo 10

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given an array of n integers a1,a2,…,an. You can apply the following operation an arbitrary number of times: select an index i (1≤i≤n) and replace the value of the element ai with the value ai+(aimod10), where aimod10 is the remainder of the integer dividing ai by 10. For a single index (value i), this operation can be applied multiple times. If the operation is applied repeatedly to the same index, then the current value of ai is taken into account each time. For example, if ai=47 then after the first operation we get ai=47+7=54, and after the second operation we get ai=54+4=58. Check if it is possible to make all array elements equal by applying multiple (possibly zero) operations. For example, you have an array [6,11].

// Let's apply this operation to the first element of the array. Let's replace a1=6 with a1+(a1mod10)=6+(6mod10)=6+6=12. We get the array [12,11].
// Then apply this operation to the second element of the array. Let's replace a2=11 with a2+(a2mod10)=11+(11mod10)=11+1=12. We get the array [12,12].

// Thus, by applying 2 operations, you can make all elements of an array equal.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. What follows is a description of each test case. The first line of each test case contains one integer n (1≤n≤2⋅105) — the size of the array. The second line of each test case contains n integers ai (0≤ai≤109) — array elements. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case print:

// YES if it is possible to make all array elements equal;
// NO otherwise.

// You can print YES and NO in any case (for example, the strings yEs, yes, Yes and YES will be recognized as a positive answer) .

// Example
// InputCopy
// 10
// 2
// 6 11
// 3
// 2 18 22
// 5
// 5 10 5 10 5
// 4
// 1 2 4 8
// 2
// 4 5
// 3
// 93 96 102
// 2
// 40 6
// 2
// 50 30
// 2
// 22 44
// 2
// 1 5
// OutputCopy
// Yes
// No
// Yes
// Yes
// No
// Yes
// No
// No
// Yes
// No

// Note
// The first test case is clarified above.
// In the second test case, it is impossible to make all array elements equal.
// In the third test case, you need to apply this operation once to all elements equal to 5.
// In the fourth test case, you need to apply this operation to all elements until they become equal to 8.
// In the fifth test case, it is impossible to make all array elements equal.
// In the sixth test case, you need to apply this operation to all elements until they become equal to 102.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    bool flag1 = false; //To check if element divisible by 5 exists
    for(int i=0; i<n; i++)
    {
        cin >> a[i];

        //Speacial case when the element is multiple of 5
        //The elements divisible by 5 is only replacable once
        //After that it becomes divisible by 10(unchangeable)
        if(a[i]%5==0)
        {
            flag1 = true; //Element 5 exists
            a[i] += a[i]%10; //Changing it(one time thing)
        }
    }

    if(flag1)
    {
        ll int minn = *min_element(a.begin(),a.end());
        ll int maxx = *max_element(a.begin(),a.end());

        if(minn==maxx)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else
    {
        bool flag20 = false, flag12 = false;
        for(int i=0; i<n; i++)
        {
            int x = a[i];
            
            //Replacing till it has 2 as last digit
            //Why stop at last digit 2?
            //Because once a number reaches a last digit of 2, the operation x = x + x % 10 will continue adding 2 to x
            //Which will lead to cycles between numbers that end in 2
            //For example, 12 becomes 14, then 16, and so on, but always keeps the last digit 2
            while(x%10!=2)
            {
                x = x + x%10;
            }

            //Checking for 20
            if(x%20==2)
            {
                flag20 = true;
            }
            //Checking for 12
            else
            {
                flag12 = true;
            }
        }

        //If both type of elements are present at the same time, only then NO, else YES
        if(flag12 && flag20) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

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
