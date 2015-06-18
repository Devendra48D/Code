/*
Problem Statement

You are given a square matrix of size N×N. Calculate the absolute difference of the sums across the two main diagonals.

Input Format

The first line contains a single integer N. The next N lines contain N integers describing the matrix.

Constraints 
1≤N≤100 
−100≤A[i]≤100
Output Format

Output a single integer equal to the absolute difference in the the sums across the diagonals.

Sample Input

3
11 2 4
4 5 6
10 8 -12
Sample Output

15
Explanation

The first diagonal of the matrix is:

11
    5
        -12
Sum across the first diagonal = 11+5-12= 4

The second diagonal of the matrix is:

        4
    5
10
Sum across the second diagonal = 4+5+10 = 19 
Difference: |4-19| =15
*/
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, sum1 = 0, sum2 = 0;
    cin>>N;
    int size = N*N;
    int array[size];
    for (int i = 0; i < size; i++)
        {
        cin>>array[i];
    }
    for (int j = 0; j < size; j += (N+1) )
        {
        sum1 += array[j];
    }
    for (int k = (N - 1); k < (size - N + 1); k += (N-1) )
        {
        sum2 += array[k];
    }
    if (sum2 > sum1)
        cout<<(sum2 - sum1);
    else if (sum1 > sum2)
        cout<<(sum1 - sum2);
    else
        cout<<0;  
    return 0;
}
