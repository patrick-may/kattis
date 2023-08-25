#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool debug = false;
ll solve(const vector<int> seq,  int above, int below, int med, int left, int right) {
    if (debug) {
        cout << "SOLVING WITH: above " << above << " below " << below << " left " << left << " right " << right << "\n";
    }

    if (above != below) {
        if (debug) cout << "quitting\n";
        return 0;
    }
    // subtier sum
    ll soln = 1;

    // try going both to the left
    if (left - 2 >= 0) {
        int newa = above, newb = below;
        seq[left - 1] < med ? ++newb : ++newa;
        seq[left - 2] < med ? ++newb : ++newa;

        ll leftsub = solve(seq, newa, newb, med, left - 2, right);
        soln += leftsub;
        if (debug) cout << "left soln yielded " << leftsub << "\n";
    }
    if (right + 2 < seq.size()) {
        int newa = above, newb = below;
        seq[right + 1] < med ? ++newb : ++newa;
        seq[right + 2] < med ? ++newb : ++newa;

        ll rightsub = solve(seq, newa, newb, med, left, right + 2);
        soln += rightsub;

        if (debug) cout << "right soln yielded " << rightsub << "\n";
    }
    if (left - 1 >= 0 && right + 1 < seq.size()) {
        int newa = above, newb = below;
        seq[left - 1] < med ? ++newb : ++newa;
        seq[right + 1] < med ? ++newb : ++newa;

        ll midgrow = solve(seq, newa, newb, med, left - 1, right + 1);
        soln += midgrow;
        if (debug) cout << "middle soln yielded " << midgrow << "\n";
    }
    
    return soln;

}

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

    ll soln = 0; // trivial case 
    soln += solve(seq, 0, 0, b, loc, loc);
    cout << soln << "\n";
    return 0;
}
