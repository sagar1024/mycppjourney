// A. Primary Task

// time limit per test1 second
// memory limit per test256 megabytes

// Dmitry wrote down t integers on the board, and that is good. He is sure that he lost an important integer n among them, and that is bad. The integer n had the form 10^x (x≥2), where the symbol '^' denotes exponentiation.. Something went wrong, and Dmitry missed the symbol '^' when writing the important integer. For example, instead of the integer 105, he would have written 105, and instead of 1019, he would have written 1019. Dmitry wants to understand which of the integers on the board could have been the important integer and which could not.

// Input
// The first line of the input contains one integer t (1≤t≤104) — the number of integers on the board. The next t lines each contain an integer a (1≤a≤10000) — the next integer from the board.

// Output
// For each integer on the board, output "YES" if it could have been the important integer and "NO" otherwise. You may output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

// Example
// InputCopy
// 7
// 100
// 1010
// 101
// 105
// 2033
// 1019
// 1002

// OutputCopy
// NO
// YES
// NO
// YES
// NO
// YES
// NO

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a;
        cin >> a;

        string s = to_string(a);
        int n = s.size();

        if(n<3) 
        {
            cout << "NO" << endl;
            continue;
        }

        if (s[0] == '1' && s[1] == '0')
        {
            if (s[2] == '0' || s[2] == '1')
            {
                if (s[2] == '0')
                {
                    cout << "NO" << endl;
                }
                else if (s[2] == '1')
                {
                    if (s[3]!='\0' && n>3)
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
