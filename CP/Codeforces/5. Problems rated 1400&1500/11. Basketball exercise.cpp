// C. Basketball Exercise

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Finally, a basketball court has been opened in SIS, so Demid has decided to hold a basketball exercise session. 2⋅n students have come to Demid's exercise session, and he lined up them into two rows of the same size (there are exactly n people in each row). Students are numbered from 1 to n in each row in order from left to right.
// (figure)

// Now Demid wants to choose a team to play basketball. He will choose players from left to right, and the index of each chosen player (excluding the first one taken) will be strictly greater than the index of the previously chosen player. To avoid giving preference to one of the rows, Demid chooses students in such a way that no consecutive chosen students belong to the same row. The first student can be chosen among all 2n students (there are no additional constraints), and a team can consist of any number of students. Demid thinks, that in order to compose a perfect team, he should choose students in such a way, that the total height of all chosen students is maximum possible. Help Demid to find the maximum possible total height of players in a team he can choose.

// Input
// The first line of the input contains a single integer n (1≤n≤105) — the number of students in each row. The second line of the input contains n integers h1,1,h1,2,…,h1,n (1≤h1,i≤109), where h1,i is the height of the i-th student in the first row. The third line of the input contains n integers h2,1,h2,2,…,h2,n (1≤h2,i≤109), where h2,i is the height of the i-th student in the second row.

// Output
// Print a single integer — the maximum possible total height of players in a team Demid can choose.

// Examples
// inputCopy
// 5
// 9 3 5 7 3
// 5 8 1 4 5
// outputCopy
// 29

// inputCopy
// 3
// 1 2 9
// 10 1 1
// outputCopy
// 19

// inputCopy
// 1
// 7
// 4
// outputCopy
// 7

// Note
// In the first example Demid can choose the following team as follows: (figure)
// In the second example Demid can choose the following team as follows: (figure)

