// C. Berland Regional

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Polycarp is an organizer of a Berland ICPC regional event. There are n universities in Berland numbered from 1 to n. Polycarp knows all competitive programmers in the region. There are n students: the i-th student is enrolled at a university ui and has a programming skill si. Polycarp has to decide on the rules now. In particular, the number of members in the team. Polycarp knows that if he chooses the size of the team to be some integer k, each university will send their k strongest (with the highest programming skill s) students in the first team, the next k strongest students in the second team and so on. If there are fewer than k students left, then the team can't be formed. Note that there might be universities that send zero teams. The strength of the region is the total skill of the members of all present teams. If there are no teams present, then the strength is 0. Help Polycarp to find the strength of the region for each choice of k from 1 to n.

// Input
// The first line contains a single integer t (1≤t≤1000) — the number of testcases. The first line of each testcase contains a single integer n (1≤n≤2⋅105) — the number of universities and the number of students. The second line of each testcase contains n integers u1,u2,…,un (1≤ui≤n) — the university the i-th student is enrolled at. The third line of each testcase contains n integers s1,s2,…,sn (1≤si≤109) — the programming skill of the i-th student. The sum of n over all testcases doesn't exceed 2⋅105.

// Output
// For each testcase print n integers: the strength of the region — the total skill of the members of the present teams — for each choice of team size k.

// Example
// inputCopy
// 4
// 7
// 1 2 1 2 1 2 1
// 6 8 3 1 5 1 5
// 10
// 1 1 1 2 2 2 2 3 3 3
// 3435 3014 2241 2233 2893 2102 2286 2175 1961 2567
// 6
// 3 3 3 3 3 3
// 5 9 6 7 9 7
// 1
// 1
// 3083

// outputCopy
// 29 28 26 19 0 0 0 
// 24907 20705 22805 9514 0 0 0 0 0 0 
// 43 43 43 32 38 43 
// 3083

// Note
// In the first testcase the teams from each university for each k are:

// k=1:
// university 1: [6],[5],[5],[3];
// university 2: [8],[1],[1];

// k=2:
// university 1: [6,5],[5,3];
// university 2: [8,1];

// k=3:
// university 1: [6,5,5];
// university 2: [8,1,1];

// k=4:
// university 1: [6,5,5,3];

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<long long int> university(n+1), skill(n+1);
//     for(int i=0; i<n; i++)
//     {
//         cin >> university[i];
//     }
//     for(int i=0; i<n; i++)
//     {
//         cin >> skill[i];
//     }

//     //MAIN logic
//     //Array of skills for each ith university
//     vector<vector<long long int>> student(n+1);
//     for(int i=0; i<n; i++)
//     {
//         student[university[i]].push_back(skill[i]);
//     }

//     //For each k value less than equal to n
//     int k = n;
//     vector<long long int> answer(n+1);
//     for(int i=k; i>=1; i--)
//     {
//         int sum = 0;
//         if(student[i][0]!=0)
//         {
//             for(int j=0; j<(student[i].size()/i)*i; j++)
//             {
//                 sum += student[i][j];
//             }
//         }

//         answer.push_back(sum);
//     }

//     //Output
//     for(int i=0; i<n; i++)
//     {
//         cout << answer[i] << " ";
//     }

//     cout << endl;
//     return;
// }

void solve()
{
    int n;
    cin >> n;

    vector<long long int> university(n), skill(n);
    for(int i = 0; i < n; i++)
    {
        cin >> university[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> skill[i];
    }

    //Initializing an array to store the top k skills from each university
    vector<vector<long long int>> topSkills(n + 1);

    //Populate the topSkills array
    for(int i = 0; i < n; i++)
    {
        topSkills[university[i]].push_back(skill[i]);
    }

    //Calculating the strength of the region for each choice of team size k
    for(int k = 1; k <= n; k++)
    {
        long long int totalStrength = 0;
        for(int i = 1; i <= n; i++)
        {
            //Sort the skills of students from university i in descending order
            sort(topSkills[i].rbegin(), topSkills[i].rend());

            //Calculating the strength of the teams formed from university i
            int teams = (topSkills[i].size() + k - 1) / k;
            for(int j = 0; j < teams; j++)
            {
                int cnt = min(k, (int)topSkills[i].size() - j * k);
                for(int l = 0; l < cnt; l++)
                {
                    totalStrength += topSkills[i][j * k + l];
                }
            }
        }

        cout << totalStrength << " ";
    }

    cout << endl;
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
