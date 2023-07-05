#include<iostream>
using namespace std;

int main(){
  long long int solns[15] = {0,6,12,90,360,2040,10080,54810,290640,1588356,
 8676360,47977776,266378112,1488801600,8355739392,};
  // yeah, this is a terrible solution in terms of understanding it. I'll hopefully do a writeup
  // of this problem, as it is actually pretty interesting
  int size;
  cin >> size;

  for(; size > 0; --size) {
    int len;
    cin >> len;
    cout << solns[len - 1] << "\n";
  }
  return 0;
}
