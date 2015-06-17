/*
Problem Statement

You're given an array containing integer values. You need to print the fraction of count of positive numbers, negative numbers and zeroes to the total numbers. Print the value of the fractions correct to 3 decimal places.

Input Format

First line contains N, which is the size of the array. 
Next line contains N integers A1,A2,A3,⋯,An, separated by space.

Constraints 
1≤N≤100 
−100≤Ai≤100
Output Format

Output three values on different lines equal to the fraction of count of positive numbers, negative numbers and zeroes to the total numbers respectively correct to 3 decimal places.

Sample Input

6
-4 3 -9 0 4 1          
Sample Output

0.500
0.333
0.167
Explanation

There are 3 positive numbers, 2 negative numbers and 1 zero in the array. 
Fraction of the positive numbers, negative numbers and zeroes are 36=0.500, 26=0.333 and 16=0.167 respectively.

Note With this challeng we are introducing you to precision problems. Here you can even print output to 4 decimal places and above but only the difference at 3rd decimal digit is noted. That is the reason you'll notice testcases have much higher precision that required.
*/
#include <cmath>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N;
    double positive = 0, negative = 0, zeroes = 0;
    cin>>N;
    for (int i = 0; i < N; i++)
        {
        int num;
        cin>>num;
        if (num > 0)
            positive ++;
        else if (num < 0)
            negative ++;
        else 
            zeroes++;
    }
    cout.precision(3);
    cout.fixed;
    cout<<(positive/N)<<endl;
    cout<<(negative/N)<<endl;
    cout<<(zeroes/N)<<endl;
    return 0;
}
