/*
Problem Statement

Write a short program that prints (to STDOUT) the numbers from 1 to 100. But for multiples of three print "Fizz" instead of the number and for the multiples of five print "Buzz". For numbers which are multiples of both three and five print "FizzBuzz".

The goal is to write the shortest code possible.

Scoring: Your score is (200 - number of characters in your source code)/10

Expected output:

1 
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
16
............and so on
*/

#include <iostream>
using namespace std;
int main()
{
    for(int i=1;i<=100;i++){
        if((i%3 == 0) && (i%5==0))
            cout<<"FizzBuzz\n";
        else if(i%3 == 0)
            cout<<"Fizz\n";
        else if(i%5 == 0)
            cout<<"Buzz\n";
        else
            cout<<i<<"\n";
     }
    return 0;
}
