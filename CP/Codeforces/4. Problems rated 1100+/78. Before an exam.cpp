// B. Before an Exam

// time limit per test0.5 second
// memory limit per test64 megabytes
// inputstandard input
// outputstandard output

// Tomorrow Peter has a Biology exam. He does not like this subject much, but d days ago he learnt that he would have to take this exam. Peter's strict parents made him prepare for the exam immediately, for this purpose he has to study not less than minTimei and not more than maxTimei hours per each i-th day. Moreover, they warned Peter that a day before the exam they would check how he has followed their instructions. So, today is the day when Peter's parents ask him to show the timetable of his preparatory studies. But the boy has counted only the sum of hours sumTime spent him on preparation, and now he wants to know if he can show his parents a timetable sсhedule with d numbers, where each number sсhedulei stands for the time in hours spent by Peter each i-th day on biology studies, and satisfying the limitations imposed by his parents, and at the same time the sum total of all schedulei should equal to sumTime.

// Input
// The first input line contains two integer numbers d, sumTime (1 ≤ d ≤ 30, 0 ≤ sumTime ≤ 240) — the amount of days, during which Peter studied, and the total amount of hours, spent on preparation. Each of the following d lines contains two integer numbers minTimei, maxTimei (0 ≤ minTimei ≤ maxTimei ≤ 8), separated by a space — minimum and maximum amount of hours that Peter could spent in the i-th day.

// Output
// In the first line print YES, and in the second line print d numbers (separated by a space), each of the numbers — amount of hours, spent by Peter on preparation in the corresponding day, if he followed his parents' instructions; or print NO in the unique line. If there are many solutions, print any of them.

// Examples
// inputCopy
// 1 48
// 5 7
// outputCopy
// NO
// inputCopy
// 2 5
// 0 1
// 3 5
// outputCopy
// YES
// 1 4 

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Inputs
    int d;
    cin >> d;

    int sumTime;
    cin >> sumTime;

    vector<pair<int,int>> minMaxTimeAllowed(d);
    int minSum = 0;
    int maxSum = 0;
    for(int i=0; i<d; i++)
    {
        cin >> minMaxTimeAllowed[i].first;
        minSum += minMaxTimeAllowed[i].first;
        cin >> minMaxTimeAllowed[i].second;
        maxSum += minMaxTimeAllowed[i].second;
    }

    // if(sumTime>=minSum)
    // {
    //     cout << "YES" << endl;
    //     for(int i=0; i<d && sumTime>0; i++)
    //     {
    //         cout << minMaxTimeAllowed[i].first << " ";
    //         sumTime -= minMaxTimeAllowed[i].first;
    //     }
    // }
    // else if(sumTime<= maxSum)
    // {
    //     cout << "YES" << endl;
    //     for(int i=0; i<d && sumTime>0; i++)
    //     {
    //         cout << minMaxTimeAllowed[i].second << " ";
    //         sumTime -= minMaxTimeAllowed[i].second;
    //     }
    // }
    // else
    // {
    //     cout << "NO" << endl;
    // }

    //Outputs
    //For NO
    if (sumTime<minSum || sumTime>maxSum)
    {
        cout << "NO" << endl;
        return 0;
    }

    //For YES
    cout << "YES" << endl;
    for(int i=0; i<d; i++)
    {
        //The order of the statements is imp
        //Updating the total time studied
        sumTime -= minMaxTimeAllowed[i].second;
        
        //Until the total time becomes zero
        if(sumTime<=0)
        {
            cout << max(0, sumTime + minMaxTimeAllowed[i].second) << " ";
        }
        else
        {
            //Keep outputting the max num of hours allowed
            cout << minMaxTimeAllowed[i].second << " ";
        }
    }

    return 0;
}
