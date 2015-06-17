/*
Problem Statement

Your teacher has given you the task to draw the structure of a staircase. Being an expert programmer, you decided to make a program for the same. You are given the height of the staircase. You need to print a staircase as shown in the example.

Input Format

You are given an integer N depicting the height of the staircase.

Constraints 
1≤N≤100
Output Format

Draw a staircase of height N in the format given below.

For example:

     #
    ##
   ###
  ####
 #####
######
Staircase of height 6, note that last line has 0 spaces before it.

Sample Input

6
Sample Output

     #
    ##
   ###
  ####
 #####
######
*/

#include <cmath>
#include <string>
#include <iostream>
using namespace std;


int main() {
    int N;
    cin>>N;
    for (int i = 1; i <= N; i++)
        {
        int j = (N - i);
        char space = ' ', hash = '#';
        cout<<string (j , space)<<string (i , hash)<<endl;
    }
    return 0;
}
