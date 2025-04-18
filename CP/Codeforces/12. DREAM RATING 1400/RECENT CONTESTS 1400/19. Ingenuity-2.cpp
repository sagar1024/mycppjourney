// D. Ingenuity-2

// time limit per test2 seconds
// memory limit per test256 megabytes

// Let's imagine the surface of Mars as an infinite coordinate plane. Initially, the rover Perseverance-2 and the helicopter Ingenuity-2 are located at the point with coordinates (0,0). A set of instructions s consisting of n instructions of the following types was specially developed for them:
// N: move one meter north (from point (x,y) to (x,y+1));
// S: move one meter south (from point (x,y) to (x,y−1));
// E: move one meter east (from point (x,y) to (x+1,y));
// W: move one meter west (from point (x,y) to (x−1,y)).

// Each instruction must be executed either by the rover or by the helicopter. Moreover, each device must execute at least one instruction. Your task is to distribute the instructions in such a way that after executing all n instructions, the helicopter and the rover end up at the same point, or determine that this is impossible.

// Input
// The first line of input contains t (1≤t≤104) — the number of test cases. The first line of each test case contains a single integer n (1≤n≤2⋅105) — the number of instructions. The second line of each test case contains a string s of length n consisting of the characters 'N', 'S', 'E', 'W' — the sequence of instructions. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, if the required distribution of instructions exists, output a string p of length n consisting of the characters 'R', 'H'. If the i-th operation should be executed by the rover, then pi=R, if the i-th operation should be executed by the helicopter, then pi=H. If there are multiple solutions, output any of them. Otherwise, output NO.

// Example
// InputCopy
// 10
// 6
// NENSNE
// 3
// WWW
// 6
// NESSWS
// 2
// SN
// 2
// WE
// 4
// SSNN
// 4
// WESN
// 2
// SS
// 4
// EWNN
// 4
// WEWE
// OutputCopy
// RRHRRH
// NO
// HRRHRH
// NO
// NO
// RHRH
// RRHH
// RH
// RRRH
// RRHH

// Note
// Let's consider the first example: the string S=NENSNE. One of the possible solutions, shown in the figure below, is p=RRHRRH, using which both the rover and the helicopter will end up one meter north and one meter east.
// For WWW, the solution is impossible.

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     int x = 0, y = 0;
//     for(int i=0; i<n; i++)
//     {
//         if(s[i]=='N') y++;
//         else if(s[i]=='S') y--;
//         else if(s[i]=='E') x++;
//         else if(s[i]=='W') x--;
//     }

//     if(x%2==1 || y%2==1)
//     {
//         cout << "NO" << endl;
//         return;
//     }

//     string ans;
//     int rx=0, ry=0, hx=0, hy=0;
//     for(int i=0; i<n; i++)
//     {
//         if(s[i]=='N')
//         {
//             if(abs(ry-hy)<1)
//             {
//                 ry++;
//                 ans += 'R';
//             }
//             else
//             {
//                 hy++;
//                 ans += 'H';
//             }
//         }
//         else if(s[i]=='S')
//         {
//             if(abs(ry-hy)<1)
//             {
//                 ry--;
//                 ans += 'R';
//             }
//             else
//             {
//                 hy--;
//                 ans += 'H';
//             }
//         }
//         else if(s[i]=='E')
//         {
//             if(abs(rx-hx)<1)
//             {
//                 rx++;
//                 ans += 'R';
//             }
//             else
//             {
//                 hx++;
//                 ans += 'H';
//             }
//         }
//         else
//         {
//             if(abs(rx-hx)<1)
//             {
//                 rx--;
//                 ans += 'R';
//             }
//             else
//             {
//                 hx--;
//                 ans += 'H';
//             }
//         }
//     }

//     if(rx==hx && ry==hy) cout << ans << endl;
//     else cout << "NO" << endl;

//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

#include <iostream>
#include <string>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int dx = 0, dy = 0;
    for (char c : s)
    {
        if (c == 'N')
            dy++;
        if (c == 'S')
            dy--;
        if (c == 'E')
            dx++;
        if (c == 'W')
            dx--;
    }

    if (dx % 2 != 0 || dy % 2 != 0)
    {
        cout << "NO\n";
        return;
    }

    int targetX = dx / 2, targetY = dy / 2;

    string ans = "";
    int currX = 0, currY = 0;
    int usedR = 0, usedH = 0;

    for (char c : s)
    {
        bool giveToR = false;

        if (c == 'N' && targetY > 0)
        {
            targetY--;
            giveToR = true;
        }
        else if (c == 'S' && targetY < 0)
        {
            targetY++;
            giveToR = true;
        }
        else if (c == 'E' && targetX > 0)
        {
            targetX--;
            giveToR = true;
        }
        else if (c == 'W' && targetX < 0)
        {
            targetX++;
            giveToR = true;
        }

        if (giveToR)
        {
            ans += 'R';
            usedR++;
        }
        else
        {
            ans += 'H';
            usedH++;
        }
    }

    if (usedR == 0 || usedH == 0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << ans << "\n";
    }

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
