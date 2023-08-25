#include <bits/stdc++.h>

using namespace std;

int main() {
    // fast input
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b;
    cin >> n >> b;
    vector<int> seq(n);
    int loc;
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
        if (seq[i] == b) {
            loc = i;
        }
    }

    int befbelow = 0, befabove = 0, aftabove = 0, aftbelow;
    for (int i = 0; i < n; ++i) {
        if (i < loc) {
            seq[i] < b ? ++befbelow : ++befabove;
        }
        else if (i > loc && seq[i] > b) {
            seq[i] < b ? ++aftbelow : ++aftabove; 
        }
    }

     

}
