#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    map<string, int> haydict;
    for(; m > 0; --m) {
        string title;
        int pay;
        cin >> title >> pay;
        haydict[title] = pay;
    }

    for(; n > 0; --n) {
        string desc;
        cin >> desc;
        int soln = 0;
        while (desc != ".") {
            soln += haydict[desc];
            cin >> desc;
        }
        cout << soln << "\n";

    }

}