// C. Two Movies

// time limit per test2 seconds
// memory limit per test256 megabytes

// A movie company has released 2 movies. These 2 movies were watched by n people. For each person, we know their attitude towards the first movie (liked it, neutral, or disliked it) and towards the second movie. If a person is asked to leave a review for the movie, then: if that person liked the movie, they will leave a positive review, and the movie's rating will increase by 1; if that person disliked the movie, they will leave a negative review, and the movie's rating will decrease by 1; otherwise, they will leave a neutral review, and the movie's rating will not change. Every person will review exactly one movie — and for every person, you can choose which movie they will review. The company's rating is the minimum of the ratings of the two movies. Your task is to calculate the maximum possible rating of the company.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains a single integer n (1≤n≤2⋅105). The second line contains n integers a1,a2,…,an (−1≤ai≤1), where ai is equal to −1 if the first movie was disliked by the i-th viewer; equal to 1 if the first movie was liked; and 0 if the attitude is neutral. The third line contains n integers b1,b2,…,bn (−1≤bi≤1), where bi is equal to −1 if the second movie was disliked by the i-th viewer; equal to 1 if the second movie was liked; and 0 if the attitude is neutral. Additional constraint on the input: the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print a single integer — the maximum possible rating of the company, if for each person, choose which movie to leave a review on.

// Example
// InputCopy
// 4
// 2
// -1 1
// -1 -1
// 1
// -1
// -1
// 5
// 0 -1 1 0 1
// -1 1 0 0 1
// 4
// -1 -1 -1 1
// -1 1 1 1
// OutputCopy
// 0
// -1
// 1
// 1

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> b[i];
    }

    vector<int> a2, b2;
    for(int i=0; i<n; i++)
    {
        if(a[i]==b[i])
        {
            continue;
        }
        else if(a[i]>b[i])
        {
            a2.push_back(a[i]);
        }
        else
        {
            b2.push_back(b[i]);
        }
    }

    int suma = 0;
    int sumb = 0;
    for(int i=0; i<a2.size(); i++)
    {
        suma += a2[i];
    }
    for(int i=0; i<b2.size(); i++)
    {
        sumb += b2[i];
    }

    //Now for those indexes with same review(for both movie)
    for(int i=0; i<n; i++)
    {
        if(a[i]==b[i])
        {
            if(a[i]==-1)
            {
                if(suma>=sumb)
                {
                    suma -= 1;
                }
                else
                {
                    sumb -= 1;
                }
            }
            else if(a[i]==1)
            {
                if(suma>=sumb)
                {
                    sumb += 1;
                }
                else
                {
                    suma += 1;
                }
            }
            else
            {
                continue;
            }
        }
    }

    cout << min(suma,sumb) << endl;

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
