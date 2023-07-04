#include <bits/stdc++.h>

using namespace std;

void tc(int lines) {
  int soln = 0;
  int elapsed = 0; 
  for (; lines > 0; --lines) {
    int speed, hrs;
    
    cin >> speed >> hrs;
    hrs -= elapsed;
    soln += (speed * hrs);
    elapsed += hrs;
  }

  cout << soln << " miles\n"; 
}

int main() {
  int lines;
  while (cin >> lines && lines != -1){
    tc(lines);
  }
  return 0;
}
