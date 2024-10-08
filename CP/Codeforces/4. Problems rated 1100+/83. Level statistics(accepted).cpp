// A. Level Statistics

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Polycarp has recently created a new level in this cool new game Berlio Maker 85 and uploaded it online. Now players from all over the world can try his level. All levels in this game have two stats to them: the number of plays and the number of clears. So when a player attempts the level, the number of plays increases by 1. If he manages to finish the level successfully then the number of clears increases by 1 as well. Note that both of the statistics update at the same time (so if the player finishes the level successfully then the number of plays will increase at the same time as the number of clears). Polycarp is very excited about his level, so he keeps peeking at the stats to know how hard his level turns out to be. So he peeked at the stats n times and wrote down n pairs of integers — (p1,c1),(p2,c2),…,(pn,cn), where pi is the number of plays at the i-th moment of time and ci is the number of clears at the same moment of time. The stats are given in chronological order (i.e. the order of given pairs is exactly the same as Polycarp has written down). Between two consecutive moments of time Polycarp peeked at the stats many players (but possibly zero) could attempt the level. Finally, Polycarp wonders if he hasn't messed up any records and all the pairs are correct. If there could exist such a sequence of plays (and clears, respectively) that the stats were exactly as Polycarp has written down, then he considers his records correct. Help him to check the correctness of his records. For your convenience you have to answer multiple independent test cases.

// Input
// The first line contains a single integer T (1≤T≤500) — the number of test cases. The first line of each test case contains a single integer n (1≤n≤100) — the number of moments of time Polycarp peeked at the stats. Each of the next n lines contains two integers pi and ci (0≤pi,ci≤1000) — the number of plays and the number of clears of the level at the i-th moment of time. Note that the stats are given in chronological order.

// Output
// For each test case print a single line. If there could exist such a sequence of plays (and clears, respectively) that the stats were exactly as Polycarp has written down, then print "YES". Otherwise, print "NO". You can print each letter in any case (upper or lower).

// Example
// inputCopy
// 6
// 3
// 0 0
// 1 1
// 1 2
// 2
// 1 0
// 1000 3
// 4
// 10 1
// 15 2
// 10 2
// 15 2
// 1
// 765 432
// 2
// 4 4
// 4 3
// 5
// 0 0
// 1 0
// 1 0
// 1 0
// 1 0
// outputCopy
// NO
// YES
// NO
// YES
// NO
// YES

// Note
// In the first test case at the third moment of time the number of clears increased but the number of plays did not, that couldn't have happened.
// The second test case is a nice example of a Super Expert level.
// In the third test case the number of plays decreased, which is impossible.
// The fourth test case is probably an auto level with a single jump over the spike.
// In the fifth test case the number of clears decreased, which is also impossible.
// Nobody wanted to play the sixth test case - Polycarp's mom attempted it to make him feel better, however, she couldn't clear it.

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        //Inputs
        int n;
        cin >> n;

        vector<pair<int,int>> plays_and_clears(n);
        for(int i=0; i<n; i++)
        {
            cin >> plays_and_clears[i].first >> plays_and_clears[i].second;
        }

        if(plays_and_clears[0].first < plays_and_clears[0].second)
        {
            cout << "NO" << endl;
            continue;
        }

        //MAIN logic
        bool correctRecords = true;
        for(int i=1; i<n; i++)
        {
            //Both play count and clear count should be non-decreasing
            if(plays_and_clears[i-1].first > plays_and_clears[i].first)
            {
                correctRecords = false;
                break;
            }
            if(plays_and_clears[i-1].second > plays_and_clears[i].second)
            {
                correctRecords = false;
                break;
            }
            //The play count should always be greater than or equal to the clear count
            if(plays_and_clears[i].first < plays_and_clears[i].second)
            {
                correctRecords = false;
                break;
            }
            if(abs(plays_and_clears[i-1].first - plays_and_clears[i].first) < abs(plays_and_clears[i-1].second - plays_and_clears[i].second))
            {
                correctRecords = false;
                break;
            }
        }

        //Outputs
        if(correctRecords)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
