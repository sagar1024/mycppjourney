// A. Olympiad Date

// time limit per test1 second
// memory limit per test256 megabytes

// The final of the first Olympiad by IT Campus "NEIMARK" is scheduled for March 1, 2025. A nameless intern was tasked with forming the date of the Olympiad using digits — 01.03.2025. To accomplish this, the intern took a large bag of digits and began drawing them one by one. In total, he drew n digits — the digit ai was drawn in the i-th turn. You suspect that the intern did extra work. Determine at which step the intern could have first assembled the digits to form the date of the Olympiad (the separating dots can be ignored), or report that it is impossible to form this date from the drawn digits. Note that leading zeros must be displayed.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The first line of each test case contains a single integer n (1≤n≤20). The second line of each test case contains n integers ai (0≤ai≤9) — the numbers that the intern pulled out in chronological order.

// Output
// For each test case, output the minimum number of digits that the intern could pull out. If all the digits cannot be used to make a date, output the number 0.

// Example
// InputCopy
// 4
// 10
// 2 0 1 2 3 2 5 0 0 1
// 8
// 2 0 1 2 3 2 5 0
// 8
// 2 0 1 0 3 2 5 0
// 16
// 2 3 1 2 3 0 1 9 2 1 0 3 5 4 0 3
// OutputCopy
// 9
// 0
// 8
// 15

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<int> digits(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> digits[i];
//     }

//     string target = "01032025";

//     int zero = 3;
//     int one = 1;
//     int two = 2;
//     int three = 1;
//     int five = 1;

//     int ans = 0;
//     for(int i=0; i<n; i++)
//     {
//         if(digits[i]==zero) zero--;
//         if(digits[i]==one) one--;
//         if(digits[i]==two) two--;
//         if(digits[i]==three) three--;
//         if(digits[i]==five) five--;

//         if(zero<=0 && one<=0 && two<=0 && three<=0 && five<=0)
//         {
//             ans = i+1;
//             break;
//         }
//     }

//     if(ans) cout << ans << endl;
//     else cout << "0" << endl;

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

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> digits(n);
    for (int i = 0; i < n; i++)
    {
        cin >> digits[i];
    }

    string target = "01032025";
    vector<int> target_count(10, 0);
    for (char c : target)
    {
        target_count[c - '0']++;
    }

    int ans = 0;
    vector<int> current_count(10, 0);

    for (int i = 0; i < n; i++)
    {
        current_count[digits[i]]++;
        bool possible = true;
        for (int j = 0; j < 10; j++)
        {
            if (current_count[j] < target_count[j])
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            ans = i + 1;
            break;
        }
    }

    cout << ans << endl;
    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}