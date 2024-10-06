// E. Alternating String

// time limit per test2 seconds
// memory limit per test256 megabytes

// Sakurako really loves alternating strings. She calls a string s of lowercase Latin letters an alternating string if characters in the even positions are the same, if characters in the odd positions are the same, and the length of the string is even. For example, the strings 'abab' and 'gg' are alternating, while the strings 'aba' and 'ggwp' are not. As a good friend, you decided to gift such a string, but you couldn't find one. Luckily, you can perform two types of operations on the string: Choose an index i and delete the i-th character from the string, which will reduce the length of the string by 1. This type of operation can be performed no more than 1 time; 
// Choose an index i and replace si with any other letter.

// Since you are in a hurry, you need to determine the minimum number of operations required to make the string an alternating one.

// Input
// The first line contains a single integer t (1≤t≤104)  — the number of test cases. The first line of each test case contains a single number n (1≤n≤2⋅105)  — the length of the string. The second line of each test case contains a string s, consisting of lowercase Latin letters. It is guaranteed that the sum of n across all test cases does not exceed 2⋅105.

// Output
// For each test case, output a single integer — the minimum number of operations required to turn the string s into an alternating one.

// Example
// InputCopy
// 10
// 1
// a
// 2
// ca
// 3
// aab
// 5
// ababa
// 6
// acdada
// 9
// ejibmyyju
// 6
// bbccbc
// 6
// abacba
// 5
// bcbca
// 5
// dcbdb
// OutputCopy
// 1
// 0
// 1
// 1
// 2
// 6
// 2
// 3
// 1
// 1

// Note
// For the string ababa, you can delete the first character to get baba, which is an alternating string.
// For the string acdada, you can change the first two characters to get dadada, which is an alternating string.

// My original soln -

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     if (n == 1)
//     {
//         cout << 1 << endl;
//         return;
//     }

//     //Frequency counts for even and odd indexed characters
//     vector<int> freq_even(26, 0);
//     vector<int> freq_odd(26, 0);

//     for (int i = 0; i < n; ++i)
//     {
//         if (i % 2 == 0)
//         {
//             freq_even[s[i] - 'a']++;
//         }
//         else
//         {
//             freq_odd[s[i] - 'a']++;
//         }
//     }

//     int max_even = *max_element(freq_even.begin(), freq_even.end());
//     int max_odd = *max_element(freq_odd.begin(), freq_odd.end());

//     //Minimum replacements needed without deletion
//     int min_operations = ((n + 1) / 2 - max_even) + (n / 2 - max_odd);

//     //If length is odd, consider the cost of deleting one character
//     if (n % 2 != 0)
//     {
//         int min_delete_operations = INT_MAX;

//         //Case 1: Delete one character from even positions
//         for (int i = 0; i < 26; ++i)
//         {
//             int new_max_odd = freq_odd[i];
//             int new_operations = ((n / 2) - max_even) + (((n + 1) / 2) - new_max_odd);
//             min_delete_operations = min(min_delete_operations, new_operations);
//         }

//         //Case 2: Delete one character from odd positions
//         for (int i = 0; i < 26; ++i)
//         {
//             int new_max_even = freq_even[i];
//             int new_operations = (((n + 1) / 2) - new_max_even) + ((n / 2) - max_odd);
//             min_delete_operations = min(min_delete_operations, new_operations);
//         }

//         //The minimum operations considering deletion of one character
//         min_operations = min(min_operations, min_delete_operations);
//     }

//     cout << min_operations << endl;
//     return;
// }

// int main()
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

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>

// using namespace std;

// // Function to check if the string is alternating
// bool isAlternating(const string &s)
// {
//     if (s.length() < 2)
//         return true; // Single character or empty string is trivially alternating

//     char evenChar = s[0];
//     char oddChar = s[1];

//     for (size_t i = 2; i < s.length(); ++i)
//     {
//         if ((i % 2 == 0 && s[i] != evenChar) ||
//             (i % 2 != 0 && s[i] != oddChar))
//         {
//             return false;
//         }
//     }
//     return true;
// }

// // Function to count the minimum replacements needed to make the string alternating
// int countReplacements(const string &s)
// {
//     vector<int> counts(26, 0);
//     for (int i = 0; i < s.length(); i += 2)
//     {
//         counts[s[i] - 'a']++;
//     }
//     int maxEvenCount = *max_element(counts.begin(), counts.end());

//     counts.assign(26, 0);
//     for (int i = 1; i < s.length(); i += 2)
//     {
//         counts[s[i] - 'a']++;
//     }
//     int maxOddCount = *max_element(counts.begin(), counts.end());

//     return (s.length() / 2 - maxEvenCount) + (s.length() / 2 - maxOddCount);
// }

// // Function to solve the problem for a given string
// int solve(const string &s)
// {
//     int n = s.length();

//     // Check if already alternating
//     if (n % 2 != 0 || !isAlternating(s))
//     {
//         // Try deleting one character
//         int minDeletions = INT_MAX;
//         for (int i = 0; i < n; ++i)
//         {
//             string temp = s.substr(0, i) + s.substr(i + 1);
//             if (temp.length() % 2 == 0 && isAlternating(temp))
//             {
//                 return 1; // Deleting one character is enough
//             }
//         }

//         // Count minimum replacements for even-length case
//         vector<int> counts(26, 0);
//         for (int i = 0; i < n; i += 2)
//         {
//             counts[s[i] - 'a']++;
//         }
//         int maxEvenCount = *max_element(counts.begin(), counts.end());

//         counts.assign(26, 0);
//         for (int i = 1; i < n; i += 2)
//         {
//             counts[s[i] - 'a']++;
//         }
//         int maxOddCount = *max_element(counts.begin(), counts.end());

//         int evenLengthCost = (n / 2 - maxEvenCount) + (n / 2 - maxOddCount);

//         // Count minimum replacements for odd-length case
//         int oddLengthCost = INT_MAX;
//         for (int i = 0; i < n; ++i)
//         {
//             string temp = s.substr(0, i) + s.substr(i + 1);
//             if (temp.length() % 2 == 0)
//             {
//                 int cost = countReplacements(temp);
//                 if (cost < oddLengthCost)
//                 {
//                     oddLengthCost = cost;
//                 }
//             }
//         }

//         return min(evenLengthCost, oddLengthCost);
//     }

//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         string s;
//         cin >> n >> s;

//         cout << solve(s) << '\n';
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to check if the string is alternating
bool isAlternating(const string &s)
{
    if (s.length() < 2)
        return true; // Single character or empty string is trivially alternating

    char evenChar = s[0];
    char oddChar = s[1];

    for (size_t i = 2; i < s.length(); ++i)
    {
        if ((i % 2 == 0 && s[i] != evenChar) ||
            (i % 2 != 0 && s[i] != oddChar))
        {
            return false;
        }
    }
    return true;
}

// Function to solve the problem for a given string
int solve(const string &s)
{
    int n = s.length();

    // Function to count replacements needed for a substring
    auto countReplacements = [&](const string &sub) -> int
    {
        vector<int> evenCounts(26, 0), oddCounts(26, 0);
        for (int i = 0; i < sub.length(); i++)
        {
            if (i % 2 == 0)
                evenCounts[sub[i] - 'a']++;
            else
                oddCounts[sub[i] - 'a']++;
        }
        return sub.length() / 2 - *max_element(evenCounts.begin(), evenCounts.end()) +
               sub.length() / 2 - *max_element(oddCounts.begin(), oddCounts.end());
    };

    // Base case: already alternating
    if (n % 2 == 0 && isAlternating(s))
        return 0;

    // Case 1: Delete one character
    int minDeleteCost = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        string temp = s.substr(0, i) + s.substr(i + 1);
        if (temp.length() % 2 == 0)
        {
            minDeleteCost = min(minDeleteCost, 1 + countReplacements(temp));
        }
    }

    // Case 2: Replace characters
    int replaceCost = countReplacements(s);

    // Return minimum cost
    return min(minDeleteCost, replaceCost);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        cout << solve(s) << '\n';
    }

    return 0;
}
