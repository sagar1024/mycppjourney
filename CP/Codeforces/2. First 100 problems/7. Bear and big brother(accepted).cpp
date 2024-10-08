// A. Bear and Big Brother

// time limit per test: 1 second
// memory limit per test: 256 megabytes
// input: standard input
// output: standard output

// Bear Limak wants to become the largest of bears, or at least to become larger than his brother Bob. Right now, Limak and Bob weigh a and b respectively. It's guaranteed that Limak's weight is smaller than or equal to his brother's weight. Limak eats a lot and his weight is tripled after every year, while Bob's weight is doubled after every year. After how many full years will Limak become strictly larger (strictly heavier) than Bob?

// Input
// The only line of the input contains two integers a and b (1 ≤ a ≤ b ≤ 10) — the weight of Limak and the weight of Bob respectively.

// Output
// Print one integer, denoting the integer number of years after which Limak will become strictly larger than Bob.

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int years = 0;

    if(1<=a && a<=b && b<=10)
    {
        while(a<=b)
        {
            a = 3*a;
            b = 2*b;

            years++;
        }
    }

    else
    {
        return -1;
    }

    cout << years << endl;

    return 0;
}