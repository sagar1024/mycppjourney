// C1. Game on Tree (Easy)

// time limit per test1 second
// memory limit per test256 megabytes

// This is the easy version of the problem. The difference in this version is that t=1 and we work on an array-like tree. Ron and Hermione are playing a game on a tree of n nodes that are initially inactive. This tree is special because it has exactly two leaves. It can thus be seen as an array. The game consists of t rounds, each of which starts with a stone on exactly one node, which is considered as activated. A move consists of picking an inactive neighbor of the node with a stone on it and moving the stone there (thus activating this neighbor). Ron makes the first move, after which he alternates with Hermione until no valid move is available. The player that cannot make a move loses the round. If both players play optimally, who wins each round of this game? Note that all the rounds are played with the same tree; only the starting node changes. Moreover, after each round, all active nodes are considered inactive again.

// Input
// The first line contains integers n (2≤n≤2×105), t (t=1), the number of nodes in the tree and the number of rounds, respectively. The next n−1 lines contain two integers 1≤u,v≤n each, corresponding to an edge of the tree. It is guaranteed that the tree has exactly two leaves. The next line contains t integers 1≤u1,…,ut≤n, corresponding to the node where the stone is initially put.

// Output
// The output consists of t=1 line which is either "Ron" or "Hermione".

// Examples
// InputCopy
// 3 1
// 2 3
// 3 1
// 3
// OutputCopy
// Ron
// InputCopy
// 5 1
// 1 2
// 2 3
// 3 4
// 4 5
// 5
// OutputCopy
// Hermione

