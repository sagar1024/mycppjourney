// C. Largest Subsequence

// time limit per test1 second
// memory limit per test256 megabytes

// Given is a string s of length n. In one operation you can select the lexicographically largest† subsequence of string s and cyclic shift it to the right‡. Your task is to calculate the minimum number of operations it would take for s to become sorted, or report that it never reaches a sorted state. A string a is lexicographically smaller than a string b if and only if one of the following holds:
// a is a prefix of b, but a≠b;

// In the first position where a and b differ, the string a has a letter that appears earlier in the alphabet than the corresponding letter in b. By cyclic shifting the string t1t2…tm to the right, we get the string tmt1…tm−1.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows. The first line of each test case contains a single integer n (1≤n≤2⋅105) — the length of the string s. The second line of each test case contains a single string s of length n, consisting of lowercase English letters. It is guaranteed that sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output a single integer — the minimum number of operations required to make s sorted, or −1 if it's impossible.

// Example
// InputCopy
// 6
// 5
// aaabc
// 3
// acb
// 3
// bac
// 4
// zbca
// 15
// czddeneeeemigec
// 13
// cdefmopqsvxzz
// OutputCopy
// 0
// 1
// -1
// 2
// 6
// 0

// Note
// In the first test case, the string s is already sorted, so we need no operations.
// In the second test case, doing one operation, we will select cb and cyclic shift it. The string s is now abc which is sorted.
// In the third test case, s cannot be sorted.
// In the fourth test case we will perform the following operations:
// The lexicographically largest subsequence is zca. Then s becomes abzc.
// The lexicographically largest subsequence is zc. Then s becomes abcz. The string becomes sorted.
// Thus, we need 2 operations.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

//Function to check if a string is sorted
bool is_sorted_string(const string &s)
{
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] < s[i - 1]) return false;
    }

    return true;
}

//Function to get the lexicographically largest subsequence
string get_largest_subsequence(const string &s)
{
    string result;
    char max_char = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] >= max_char)
        {
            max_char = s[i];
            result += s[i];
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

//Apply the right cyclic shift of the subsequence to the original string
void apply_shift(string &s, const string &subseq)
{
    string shifted = subseq.back() + subseq.substr(0, subseq.size() - 1);
    int idx = 0;
    char max_c = *max_element(subseq.begin(), subseq.end());

    for (int i = s.size() - 1; i >= 0 && idx < shifted.size(); --i)
    {
        if (s[i] >= max_c) s[i] = shifted[idx++];
    }
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (is_sorted_string(s))
    {
        cout << 0 << "\n";
        return;
    }

    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());

    //Optional: If characters mismatch with sorted version, sorting is impossible
    //But since characters are always from lowercase letters and there's no deletion, we skip this.
    int operations = 0;
    for (int i = 0; i < n; i++)
    {
        string before = s;
        string largest = get_largest_subsequence(s);
        apply_shift(s, largest);
        operations++;

        if (s == before) break;

        if (is_sorted_string(s))
        {
            cout << operations << "\n";
            return;
        }
    }

    cout << -1 << endl;
    return;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
