#include <bits/stdc++.h>
using namespace std;

void tc(int n, int m) {
    set<int> jack;
    for (; n > 0; --n) {
        int t;
        cin >> t;
        jack.insert(t);
    }
    int soln = 0;
    for (; m > 0; --m) {
        int t;
        cin >> t;
        if (jack.count(t)) {
            soln += 1;
        }
    }
    cout << soln << "\n";
}

int main() {
    int m, n;
    // fast input allows this stupid approach to work. wtf.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> m >> n and (m != 0 and n != 0)) {
        tc(n, m);
    }
    return 0;
}
