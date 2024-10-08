// C. Longest Regular Bracket Sequence

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// This is yet another problem dealing with regular bracket sequences. We should remind you that a bracket sequence is called regular, if by inserting «+» and «1» into it we can get a correct mathematical expression. For example, sequences «(())()», «()» and «(()(()))» are regular, while «)(», «(()» and «(()))(» are not. You are given a string of «(» and «)» characters. You are to find its longest substring that is a regular bracket sequence. You are to find the number of such substrings as well.

// Input
// The first line of the input file contains a non-empty string, consisting of «(» and «)» characters. Its length does not exceed 106.

// Output
// Print the length of the longest substring that is a regular bracket sequence, and the number of such substrings. If there are no such substrings, write the only line containing "0 1".

// Examples
// inputCopy
// )((())))(()())
// outputCopy
// 6 2

// inputCopy
// ))(
// outputCopy
// 0 1