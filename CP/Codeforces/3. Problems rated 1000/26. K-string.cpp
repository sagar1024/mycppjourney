// A. k-String

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A string is called a k-string if it can be represented as k concatenated copies of some string. For example, the string "aabaabaabaab" is at the same time a 1-string, a 2-string and a 4-string, but it is not a 3-string, a 5-string, or a 6-string and so on. Obviously any string is a 1-string. You are given a string s, consisting of lowercase English letters and a positive integer k. Your task is to reorder the letters in the string s in such a way that the resulting string is a k-string.

// Input
// The first input line contains integer k (1 ≤ k ≤ 1000). The second line contains s, all characters in s are lowercase English letters. The string length s satisfies the inequality 1 ≤ |s| ≤ 1000, where |s| is the length of string s.

// Output
// Rearrange the letters in string s in such a way that the result is a k-string. Print the result on a single output line. If there are multiple solutions, print any of them. If the solution doesn't exist, print "-1" (without quotes).

// Examples
// inputCopy
// 2
// aazz
// outputCopy
// azaz

// inputCopy
// 3
// abcabcabz
// outputCopy
// -1

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;

    string s;
    cin >> s;

    if((s.size()%k!=0) || s.size()<k)
    {
        cout << -1 << endl;
        return 0;
    }

    //Sort the string alphabetically
    sort(s.begin(), s.end());

    int sLength = s.size();
    int segmentSize = sLength/k;

    //Declaring a vector named frequency of size 26 and initializing all elements to 0
    vector<int> frequency(26, 0);

    //Iterating over each character c in the string s. The expression c - 'a' is used to map the character c to an index in the range [0, 25] based on its ASCII value
    for(char c: s)
    {
        frequency[c - 'a']++;
    }

    //Check if each character appears exactly k times
    for(int i=0; i<26; i++)
    {
        if(frequency[i]%k!=0)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    //Reorder the string
    string result;
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<26; j++)
        {
            if(frequency[j]!=0)
            {
                result += (char)('a' + j);
            }
        }
    }

    cout << result << endl;

    return 0;
}
