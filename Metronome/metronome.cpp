#include <bits/stdc++.h>
using namespace std;

int main(){
    int steps;
    cin >> steps;

    int full = steps/4;
    int partial = (steps % 4) * 25;
    cout << to_string(full) + "." + to_string(partial) << "\n";

    return 0;
}