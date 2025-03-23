// D. Robert Hood and Mrs Hood

// time limit per test2 seconds
// memory limit per test256 megabytes

// Impress thy brother, yet fret not thy mother. Robin's brother and mother are visiting, and Robin gets to choose the start day for each visitor. All days are numbered from 1 to n. Visitors stay for d continuous days, all of those d days must be between day 1 and n inclusive. Robin has a total of k risky 'jobs' planned. The i-th job takes place between days li and ri inclusive, for 1≤i≤k. If a job takes place on any of the d days, the visit overlaps with this job (the length of overlap is unimportant). Robin wants his brother's visit to overlap with the maximum number of distinct jobs, and his mother's the minimum. Find suitable start days for the visits of Robin's brother and mother. If there are multiple suitable days, choose the earliest one.

// Input
// The first line of the input contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case consists of three integers n, d, k (1≤n≤105,1≤d,k≤n) — the number of total days, duration of the visits, and the number of jobs. Then follow k lines of each test case, each with two integers li and ri (1≤li≤ri≤n) — the start and end day of each job. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output two integers, the best starting days of Robin's brother and mother respectively. Both visits must fit between day 1 and n inclusive.

// Example
// InputCopy
// 6
// 2 1 1
// 1 2
// 4 1 2
// 1 2
// 2 4
// 7 2 3
// 1 2
// 1 3
// 6 7
// 5 1 2
// 1 2
// 3 5
// 9 2 1
// 2 8
// 9 2 4
// 7 9
// 4 8
// 1 3
// 2 3
// OutputCopy
// 1 1
// 2 1
// 1 4
// 1 1
// 1 1
// 3 4

// Note
// In the first test case, the only job fills all 2 days, both should visit on day 1.
// In the second test case, day 2 overlaps with 2 jobs and day 1 overlaps with only 1.
// In the third test case, Robert visits for days [1,2], Mrs. Hood visits for days [4,5].

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n, d, k;
    cin >> n >> d >> k;

    //vector<pair<int,int>> job(k), job_count(n+2,0);
    vector<int> job_count(n+2,0);
    for(int i=0; i<k; i++)
    {
        //cin >> job[i].first >> job[i].second;
        int l, r;
        cin >> l >> r;
        job_count[l]++;
        job_count[r+1]--;
    }

    vector<int> jobs(n+1,0);
    for(int i=1; i<=n; i++)
    {
        jobs[i] = jobs[i-1] + job_count[i];
    }

    //Sliding window
    int max_job = -1, min_job = 1e9; //In any given window
    int bro = 1, mom = 1; //Best start dates
    int curr_window_jobs = 0;
    for(int i=1; i<=d; i++)
    {
        curr_window_jobs += jobs[i];
    }

    max_job = curr_window_jobs;
    min_job = curr_window_jobs;

    for(int i=2; i<=n-d+1; i++)
    {
        curr_window_jobs -= jobs[i];
        curr_window_jobs += jobs[i+d-1];

        if(curr_window_jobs>max_job)
        {
            max_job = curr_window_jobs;
            bro = i;
        }
        if(curr_window_jobs<min_job)
        {
            min_job = curr_window_jobs;
            mom = i;
        }
    }

    cout << bro << " " << mom << endl;

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
