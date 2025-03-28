// A. Bonus Project

// time limit per test2 seconds
// memory limit per test512 megabytes

// There is a team of n software engineers numbered from 1 to n. Their boss promises to give them a bonus if they complete an additional project. The project requires k units of work in total. The bonus promised to the i-th engineer is ai burles. The boss doesn't assign specific tasks to engineers; it is expected that every engineer will voluntarily complete some integer amount of work units. The bonus will be paid to the entire team only if the project is completed; in other words, if the total amount of voluntary work units on the project is greater than or equal to k. The amount of work that can be performed by each engineer is not limited. However, all engineers value their labour. The i-th engineer estimates one unit of their work as bi burles. If the bonus is paid, the benefit si of the i-th engineer for completing c units of work is defined as si=ai−c⋅bi. If the bonus is not paid, the engineer will not volunteer to do any work. Engineers work together for many years, so they know how the bonus is going to be distributed and how much their colleagues value the labour. That is, all ai and all bi are known to every engineer in the team. Engineers are eager to get the bonus, so they agreed on the following process of work distribution between them:
// the first engineer says: "I will complete c1 units of work", where c1 is a non-negative integer;
// then, the second engineer says: "I will complete c2 units of work", where c2 is a non-negative integer and so on;
// finally, the n-th engineer says: "I will complete cn units of work", where cn is a non-negative integer.

// Every engineer voices ci in a way to maximize their own benefit si. If the expected benefit is going to be zero, an engineer will still agree to work to get the experience and to help their colleagues obtain the bonus. However, if the benefit is expected to be negative for some reason (an engineer needs to perform an excessive amount of work or the project is not going to be completed), that engineer will not work at all (completes zero amount of work units). Given that every engineer acts perfectly, your task is to find out the numbers ci voiced by every engineer.

// Input
// The first line contains two integers n and k (1≤n≤1000; 1≤k≤106) — the number of engineers in the company and the number of work units the project requires, respectively. The second line contains n integers a1,a2,…,an (1≤ai≤109), where ai is the bonus which will be paid to the i-th engineer if the project is completed. The third line contains n integers b1,b2,…,bn (1≤bi≤1000), where bi is the work unit cost for the i-th engineer.

// Output
// Print n integers c1,c2,…,cn (0≤ci≤k) — the amount of work completed by each engineer given that every engineer behaves optimally. Note that the answer is unique.

// Examples
// InputCopy
// 3 6
// 4 7 6
// 1 2 3
// OutputCopy
// 1 3 2
// InputCopy
// 3 12
// 4 7 6
// 1 2 3
// OutputCopy
// 0 0 0
// InputCopy
// 3 11
// 6 7 8
// 1 2 3
// OutputCopy
// 6 3 2

// Note
// In the first example, engineers distributed the work across them and got the bonus, even though the benefit for the third engineer is zero.
// In the second example, the bonus project requires too many work units to complete, so it's more beneficial for engineers not to work at all.

