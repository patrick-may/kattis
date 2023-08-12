#include <bits/stdc++.h>
#define pb push_back
#define MODNUM 1000000007
using namespace std;

vector<int> lengths(int start, int a, int b, int c, int N) {
    vector<int> soln(N);
    soln[0] = start;
    for (int i = 1; i < N; ++i) {
        soln[i] = (a * soln[i - 1] + b) % c + 1;
    }
    return soln;
}

int main() {
    // we can just brute force this, yeah?
    long long N, T;
    cin >> N >> T;
    int a, b, c, t0;
    cin >> a >> b >> c >> t0;
    vector<int> speeds = lengths(t0, a, b, c, N);

    sort(speeds.begin(), speeds.end());

    long long completed = 0, penalty = 0, prior = 0;
    
    for (auto finprob : speeds) {
        if (finprob > T) {
            break;
        }
        ++completed;
        T -= finprob;
        prior += finprob;
        penalty += (prior);
        penalty %= MODNUM;
    }

    cout << completed << " " << penalty << "\n";
    return 0;
}
