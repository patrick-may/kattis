#include <bits/stdc++.h>

using namespace std;

// not sure on this one yet
// its some recurrence relation
int main(){
    long long int n, bags = 0;
    cin >> n;
    n /= 4;
    bags += 4*n;
    while (n > 1){
        cout << n << "\n";
        n /= 2;
        bags += n;
    }

    cout << bags + 2 << "\n";
    return 0;
}