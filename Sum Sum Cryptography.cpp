/*
Sum Sum Cryptography
Memory Limit: 1024MB Runtime Limit: 5s Score: 150
Alice and Bob are sending encrypted messages to each other. Your task is to intercept and decode the message that Alice has received.

Bob sends Alice a positive integer N) as the message, and Alice will decode each message by solving the equation x2 + y2 + z2 = N where x, y, z are positive non-zero integers.

To create the decoded output, Alice sums up all components of all unique (x,y,z) tuples together.

For example, (1,2,3) and (2,3,4) are unique tuples; (1,2,3) and (2,3,1) are not unique tuples.

Note that an entirely naive solution will timeout!


Input Specifications

The only input line will be a number 3 ≤ N ≤ 3000000.


Output Specifications

The output will contain one positive integer as the decoded result.


Sample Input/Output

INPUT
42
OUTPUT
10
EXPLANATION
For 42, the unique (x, y, z) would be (1, 4, 5), and 1 + 4 + 5 is 10.
INPUT
99
OUTPUT
47
EXPLANATION
For 99, the unique (x, y, z) could be (1, 7, 7), (3, 3, 9), (5, 5, 7), and 1 + 7 + 7 + 3 + 3 + 9 + 5 + 5 + 7 = 47
INPUT
1234566
OUTPUT
478112
EXPLANATION
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
int N = 3000000;
int upper_bound = ceil(sqrt(N/3));
int count = 0;
int ans = 0;

for (int i = 0; i < upper_bound; i++) {
  int i2 = i * i;
  int j = i;
  int k = floor (sqrt(N-i2));

  while (j <= k) {
    int j2 = j * j;
    int k2 = k * k;
    int sum = i2 + j2 + k2;

    if (sum < N) {
      j ++;
    } else if (sum > N) {
      k --;
    } else {
      cout<<i<<" " << j << " "<<k<<endl;
      ans += i + j + k;
      count ++;
      j ++;
    }
  }
}
cout<<ans<<endl;
return 0;}
