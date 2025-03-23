// A. Draw a Square

// time limit per test1 second
// memory limit per test256 megabytes

// The pink soldiers have given you 4 distinct points on the plane. The 4 points' coordinates are (−l,0), (r,0), (0,−d), (0,u) correspondingly, where l, r, d, u are positive integers. In the diagram, a square is drawn by connecting the four points L, R, D, U. Please determine if it is possible to draw a square∗ with the given points as its vertices. A square is defined as a polygon consisting of 4 vertices, of which all sides have equal length and all inner angles are equal. No two edges of the polygon may intersect each other.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The first line of each test case contains four integers l, r, d, u (1≤l,r,d,u≤10).

// Output
// For each test case, if you can draw a square using the four points, output "Yes". Otherwise, output "No". You can output the answer in any case. For example, the strings "yEs", "yes", and "YES" will also be recognized as positive responses.

// Example
// InputCopy
// 2
// 2 2 2 2
// 1 2 3 4
// OutputCopy
// Yes
// No

// Note
// On the first test case, the four given points form a square, so the answer is "Yes".
// On the second test case, the four given points do not form a square, so the answer is "No".

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int l,r,d,u;
    cin >>l>>r>>d>>u;

    int d1 = abs(l) + abs(r);
    int d2 = abs(d) + abs(u);

    int s1 = sqrt(pow(abs(l),2) + pow(abs(u),2));
    int s2 = sqrt(pow(abs(r),2) + pow(abs(d),2));
    int s3 = sqrt(pow(abs(l),2) + pow(abs(d),2));
    int s4 = sqrt(pow(abs(r),2) + pow(abs(u),2));

    if(s1==s2 && s2==s3 && s3==s4 && d1==d2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
