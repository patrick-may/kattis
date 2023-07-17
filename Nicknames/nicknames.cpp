#include <bits/stdc++.h>

using namespace std;

int main() {
    int namect, nickct;
    unordered_map<string, int> aliases;
    cin >> namect;
    for (; namect > 0; --namect) {
        string n;
        cin >> n;
        for (int i = 0; i < n.length(); ++i) {
            ++aliases[n.substr(0, i + 1)];
        }
    }

    /*for (auto p : aliases) {
        cout << p.first << "\t" << p.second << "\n";
    }*/

    cin >> nickct;
    for (; nickct > 0; --nickct) {
        string n;
        cin >> n;
        cout << aliases[n] << "\n";
    }

    return 0;
}
