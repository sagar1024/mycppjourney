// B. Red and Blue

// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output

// Monocarp had a sequence a consisting of n+m integers a1,a2,…,an+m. He painted the elements into two colors, red and blue; n elements were painted red, all other m elements were painted blue. After painting the elements, he has written two sequences r1,r2,…,rn and b1,b2,…,bm. The sequence r consisted of all red elements of a in the order they appeared in a; similarly, the sequence b consisted of all blue elements of a in the order they appeared in a as well. Unfortunately, the original sequence was lost, and Monocarp only has the sequences r and b. He wants to restore the original sequence. In case there are multiple ways to restore it, he wants to choose a way to restore that maximizes the value of

// f(a)=max(0,a1,(a1+a2),(a1+a2+a3),…,(a1+a2+a3+⋯+an+m))

// Help Monocarp to calculate the maximum possible value of f(a).

// Input
// The first line contains one integer t (1≤t≤1000) — the number of test cases. Then the test cases follow. Each test case consists of four lines. The first line of each test case contains one integer n (1≤n≤100). The second line contains n integers r1,r2,…,rn (−100≤ri≤100). The third line contains one integer m (1≤m≤100). The fourth line contains m integers b1,b2,…,bm (−100≤bi≤100).

// Output
// For each test case, print one integer — the maximum possible value of f(a).

// Example
// inputCopy
// 4
// 4
// 6 -5 7 -3
// 3
// 2 3 -4
// 2
// 1 1
// 4
// 10 -3 2 2
// 5
// -1 -2 -3 -4 -5
// 5
// -1 -2 -3 -4 -5
// 1
// 0
// 1
// 0
// outputCopy
// 13
// 13
// 0
// 0

// Note
// In the explanations for the sample test cases, red elements are marked as bold.
// In the first test case, one of the possible sequences a is [6,2,−5,3,7,−3,−4].
// In the second test case, one of the possible sequences a is [10,1,−3,1,2,2].
// In the third test case, one of the possible sequences a is [−1,−1,−2,−3,−2,−4,−5,−3,−4,−5].
// In the fourth test case, one of the possible sequences a is [0,0].

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
        //Num of elements painted red
        int n;
        cin >> n;

        vector<int> redElements(n);
        for(int i=0; i<n; i++)
        {
            cin >> redElements[i];
        }

        //Num of elements painted blue
        int m;
        cin >> m;

        vector<int> blueElements(m);
        for(int i=0; i<m; i++)
        {
            cin >> blueElements[i];
        }

        //Main logic
        //Dynamic array to store the merged elements
        vector<int> originalSeq;

        //Pushing back the larger number first
        int x=0, y=0;
        while(x<n || y<m)
        {
            //if(redElements[x]>=blueElements[y])
            if(x<n && (y>=m || redElements[x] >= blueElements[y]))
            {
                originalSeq.push_back(redElements[x]);
                x++;
            }
            else
            {
                originalSeq.push_back(blueElements[y]);
                y++;
            }
        }

        //Creating an array to store the cumulative sum
        vector<int> cumulativeSums(n+m);
        int cumulativeSum = 0;
        int maxValueInCumSum = 0;
        for(int i=0; i<(n+m); i++)
        {
            cumulativeSum += originalSeq[i];
            cumulativeSums[i] = cumulativeSum;

            //Also finding the max value in the array
            if(cumulativeSums[i]>maxValueInCumSum)
            {
                maxValueInCumSum = cumulativeSums[i];
            }
        }

        //Given function
        int maxFUNCTION = max(0, maxValueInCumSum);
        cout << maxFUNCTION << endl;
    }

    return 0;
}
