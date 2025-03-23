// C1. Message Transmission Error (easy version)

// time limit per test2 seconds
// memory limit per test256 megabytes

// This is a simplified version of the problem. It differs from the difficult one only in its constraints. At the Berland State University, the local network between servers does not always operate without errors. When transmitting two identical messages consecutively, an error may occur, resulting in the two messages merging into one. In this merging, the end of the first message coincides with the beginning of the second. Of course, the merging can only occur at identical characters. The length of the merging must be a positive number less than the length of the message text. For example, when transmitting two messages "abrakadabra" consecutively, it is possible that it will be transmitted with the described type of error, resulting in a message like "abrakadabrabrakadabra" or "abrakadabrakadabra' (in the first case, the merging occurred at one character, and in the second case, at four). Given the received message t, determine if it is possible that this is the result of an error of the described type in the operation of the local network, and if so, determine a possible value of s. A situation where two messages completely overlap each other should not be considered an error. For example, if the received message is "abcd", it should be considered that there is no error in it. Similarly, simply appending one message after another is not a sign of an error. For instance, if the received message is "abcabc", it should also be considered that there is no error in it.

// Input
// The input consists of a single non-empty string t, consisting of lowercase letters of the Latin alphabet. The length of the string t does not exceed 100 characters.

// Output
// If the message t cannot contain an error, output "NO" (without quotes) in a single line of output. Otherwise, in the first line, output "YES" (without quotes), and in the next line, output the string s — a possible message that could have led to the error. If there are multiple possible answers, any of them is acceptable.

// Examples
// InputCopy
// abrakadabrabrakadabra
// OutputCopy
// YES
// abrakadabra
// InputCopy
// acacacaca
// OutputCopy
// YES
// acaca
// InputCopy
// abcabc
// OutputCopy
// NO
// InputCopy
// abababab
// OutputCopy
// YES
// ababab
// InputCopy
// tatbt
// OutputCopy
// NO

// Note
// In the second example, a suitable answer could also be the string "acacaca".

//My intuition -

//Iterate the string from the back
//Keep appending the chars from the back
//Keep checking if this string - is same as - the string of same length right next to it
//All while iterating backwards
//If matching string is found, output YES and the string(newly found string + rest of the chars)
//Else output NO

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    int i = n-1; //Index from backwards
    string curr; //Tracking the curr string, while keep appending from back
    int currIDX = 0; //Curr index for checking if theres a match
    while(i!=(n-1)/2)
    {
        curr += s[i];
        currIDX = i-1;
        string temp;
        int curr_len = curr.size();
        while(curr_len--)
        {
            temp += s[currIDX];
            currIDX--;
        }

        if(currIDX<0)
        {
            cout << "NO" << endl;
            return;
        }

        //If theres a match
        reverse(curr.begin(),curr.end());
        reverse(temp.begin(),temp.end());
        if(curr==temp)
        {
            cout << "YES" << endl;
            string ans;
            for(int i=0; i<=currIDX; i++)
            {
                ans += s[i];
            }
            ans += temp;
            cout << ans << endl;
            return;
        }

        reverse(curr.begin(),curr.end());
        i--;
    }

    cout << "NO" << endl;

    return;
}

int32_t main()
{
    solve();
    return 0;
}
