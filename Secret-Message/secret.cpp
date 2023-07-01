#include <bits/stdc++.h>

using namespace std;

void tc() {
  string og;
  cin >> og;
  long int square = 1;
  while (square * square < og.size()) {
    ++square;
  }

  string padded = og;
  for (int i = 0; i < (square * square - og.size()); ++i){
    padded += "*";
  }
  
  string secret = "";
  for (int i = 0; i < square; ++i) {
    for (int j = square * (square - 1) + i; j > -1; j-=square){
      if (padded[j] != '*'){
        secret += padded[j];
      }

    }
  } 
  cout << secret << "\n";
}

int main() {
  int cases;
  cin >> cases;
  for(; cases > 0; --cases){
    tc();
  }
  return 0;
}
