// D. Not a Cheap String

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Let s be a string of lowercase Latin letters. Its price is the sum of the indices of letters (an integer between 1 and 26) that are included in it. For example, the price of the string abca is 1+2+3+1=7. The string w and the integer p are given. Remove the minimal number of letters from w so that its price becomes less than or equal to p and print the resulting string. Note that the resulting string may be empty. You can delete arbitrary letters, they do not have to go in a row. If the price of a given string w is less than or equal to p, then nothing needs to be deleted and w must be output. Note that when you delete a letter from w, the order of the remaining letters is preserved. For example, if you delete the letter e from the string test, you get tst.

// Input
// The first line of input contains an integer t (1≤t≤104) — the number of test cases in the test. The following are descriptions of t test cases. Each case consists of two lines. The first of them is the string w, it is non-empty and consists of lowercase Latin letters. Its length does not exceed 2⋅105. The second line contains an integer p (1≤p≤5200000). It is guaranteed that the sum of string lengths w over all test cases does not exceed 2⋅105.

// Output
// Output exactly t rows, the i-th of them should contain the answer to the i-th set of input data. Print the longest string that is obtained from w by deleting letters such that its price is less or equal to p. If there are several answers, then output any of them. Note that the empty string  — is one of the possible answers. In this case, just output an empty string.

// Example
// inputCopy
// 5
// abca
// 2
// abca
// 6
// codeforces
// 1
// codeforces
// 10
// codeforces
// 100

// outputCopy
// aa
// abc

// cdc
// codeforces

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         string w;
//         cin >> w;

//         int p;
//         cin >> p;

//         //Initializing a vector to store the frequency of each letter
//         vector<int> letterFreq(26,0);
//         for(int i=0; i<w.size(); i++)
//         {
//             letterFreq[w[i]-'a'] += 1;
//         }

//         sort(letterFreq.begin(), letterFreq.end());

//         int count = 0;
//         int sum = 0;
//         for(int i=0; i<26; i++)
//         {
//             if(sum>p)
//             {
//                 break;
//             }
//             else
//             {
//                 sum += letterFreq[i]*(i+1);
//                 count++;
//             }
//         }

//         cout << count << endl;
//     }
// }

//Alternate soln -

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        //Inputs
        string w;
        cin >> w;

        int p;
        cin >> p;

        //Initializing a vector to store the frequency of each letter
        vector<int> letterFreq(26, 0);
        for (char ch : w)
        {
            letterFreq[ch - 'a'] += 1;
        }

        int cumulativeSum = 0;
        int lastRemovedIndex = -1;

        //Iterating through the original string
        for (int i = w.size() - 1; i >= 0; i--)
        {
            int price = w[i] - 'a' + 1;
            cumulativeSum += price;

            if (cumulativeSum > p)
            {
                lastRemovedIndex = i;
                break;
            }
        }

        //Outputting the resulting string
        for (int i = 0; i <= lastRemovedIndex; i++)
        {
            cout << w[i];
        }

        cout << endl;
    }

    return 0;
}
