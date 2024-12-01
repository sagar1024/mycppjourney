// B. Generate Permutation

// time limit per test1.5 seconds
// memory limit per test256 megabytes

// There is an integer sequence a of length n, where each element is initially −1. Misuki has two typewriters where the first one writes letters from left to right, with a pointer initially pointing to 1, and another writes letters from right to left with a pointer initially pointing to n. Misuki would choose one of the typewriters and use it to perform the following operations until a becomes a permutation of [1,2,…,n]

// write number: write the minimum positive integer that isn't present in the array a to the element ai, i is the position where the pointer points at. Such operation can be performed only when ai=−1.
// carriage return: return the pointer to its initial position (i.e. 1 for the first typewriter, n for the second)
// move pointer: move the pointer to the next position, let i be the position the pointer points at before this operation, if Misuki is using the first typewriter, i:=i+1 would happen, and i:=i−1 otherwise. Such operation can be performed only if after the operation, 1≤i≤n holds.

// Your task is to construct any permutation p of length n, such that the minimum number of carriage return operations needed to make a=p is the same no matter which typewriter Misuki is using.

// Input
// Each test contains multiple test cases. The first line of input contains a single integer t (1≤t≤500) — the number of test cases. The description of the test cases follows. The first line of each test case contains a single integer n (1≤n≤2⋅105) — the length of the permutation. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output a line of n integers, representing the permutation p of length n such that the minimum number of carriage return operations needed to make a=p is the same no matter which typewriter Misuki is using, or −1 if it is impossible to do so. If there are multiple valid permutations, you can output any of them.

// Example
// InputCopy
// 3
// 1
// 2
// 3
// OutputCopy
// 1
// -1
// 3 1 2

// Note
// In the first testcase, it's possible to make a=p=[1] using 0 carriage return operations.

// In the second testcase, it is possible to make a=p=[1,2] with the minimal number of carriage returns as follows:

// If Misuki is using the first typewriter:
// Write number: write 1 to a1, a becomes [1,−1]
// Move pointer: move the pointer to the next position. (i.e. 2)
// Write number: write 2 to a2, a becomes [1,2]
// If Misuki is using the second typewriter:
// Move pointer: move the pointer to the next position. (i.e. 1)
// Write number: write 1 to a1, a becomes [1,−1]
// Carriage return: return the pointer to 2.
// Write number: write 2 to a2, a becomes [1,2]
// It can be proven that the minimum number of carriage returns needed to transform a into p when using the first typewriter is 0 and it is 1 when using the second one, so this permutation is not valid.

// Similarly, p=[2,1] is also not valid, so there is no solution for n=2.

// In the third testcase, it is possibile to make a=p=[3,1,2] with 1 carriage return with both the first and the second typewriter. It can be proven that, for both typewriters, it is impossible to write p with 0 carriage returns.
// With the first typewriter it is possible to:
// Move pointer: move the pointer to the next position. (i.e. 2)
// Write number: write 1 to a2, a becomes [−1,1,−1]
// Move pointer: move the pointer to the next position. (i.e. 3)
// Write number: write 2 to a3, a becomes [−1,1,2]
// Carriage return: return the pointer to 1.
// Write number: write 3 to a1, a becomes [3,1,2]
// With the second typewriter it is possible to:
// Move pointer: move the pointer to the next position. (i.e. 2)
// Write number: write 1 to a2, a becomes [−1,1,−1]
// Carriage return: return the pointer to 3.
// Write number: write 2 to a3, a becomes [−1,1,2]
// Move pointer: move the pointer to the next position. (i.e. 2)
// Move pointer: move the pointer to the next position. (i.e. 1)
// Write number: write 3 to a1, a becomes [3,1,2]

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        vector<int> p(n);
        iota(p.begin(), p.end(), 1); //Assign every element to 1 in this range
        for (int i = 1; i < n; i += 2)
        {
            swap(p[i], p[i + 1]);
        }
        for (int i = 0; i < n; i++)
        {
            cout << p[i] << " \n"[i + 1 == n];
        }
    }

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
