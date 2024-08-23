// C. Make Them Equal

// time limit per test2 seconds
// memory limit per test256 megabytes

// Theofanis has a string s1s2…sn and a character c. He wants to make all characters of the string equal to c using the minimum number of operations. In one operation he can choose a number x (1≤x≤n) and for every position i, where i is not divisible by x, replace si with c. Find the minimum number of operations required to make all the characters equal to c and the x-s that he should use in his operations.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains the integer n (3≤n≤3⋅105) and a lowercase Latin letter c — the length of the string s and the character the resulting string should consist of. The second line of each test case contains a string s of lowercase Latin letters — the initial string. It is guaranteed that the sum of n over all test cases does not exceed 3⋅105.

// Output
// For each test case, firstly print one integer m — the minimum number of operations required to make all the characters equal to c. Next, print m integers x1,x2,…,xm (1≤xj≤n) — the x-s that should be used in the order they are given. It can be proved that under given constraints, an answer always exists. If there are multiple answers, print any.

// Example
// InputCopy
// 3
// 4 a
// aaaa
// 4 a
// baaa
// 4 b
// bzyx

// OutputCopy
// 0
// 1
// 2
// 2 
// 2 3

// Note

// Let's describe what happens in the third test case:
// x1=2: we choose all positions that are not divisible by 2 and replace them, i. e. bzyx → bzbx;
// x2=3: we choose all positions that are not divisible by 3 and replace them, i. e. bzbx → bbbb.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n;
//     cin >> n;

//     char ch;
//     cin >> ch;

//     string s;
//     cin >> s;

//     vector<int> unequalCharsIDX;
//     for(int i=0; i<s.size(); i++)
//     {
//         if(s[i]!=ch)
//         {
//             unequalCharsIDX.push_back(i+1);
//         }
//     }

//     sort(unequalCharsIDX.begin(),unequalCharsIDX.end());
//     int len = unequalCharsIDX.size();

//     int minOps = 0;
//     vector<int> resArray;
//     for(int i=2; i<len && !unequalCharsIDX.empty(); i++)
//     {
//         for(int j=i+1; j<len && !unequalCharsIDX.empty(); j++)
//         {
//             if(unequalCharsIDX[j]%unequalCharsIDX[i]!=0)
//             {
//                 unequalCharsIDX.erase(unequalCharsIDX.begin()+j);
//                 j--;
//                 len--;
//             }
//         }
//         minOps++;
//         resArray.push_back(i);
//     }

//     cout << minOps << endl;
//     for(int i=0; i<minOps; i++)
//     {
//         if(i==0){
//             cout << resArray[i];
//         }
//         else if(i==minOps-1){
//             cout << " " << resArray[i] << endl;
//         }
//         else{
//             cout << " " << resArray[i];
//         }
//     }

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

//Alternate soln -
