// needed to do a list thingy. ugh
#include <bits/stdc++.h>

using namespace std;

void tc() {
    string line;
    getline(cin, line);
    list<char> output;
    auto it = output.begin();

    for (char c : line) {
        if (c == ']') {
            it = output.end();
            continue;
        }
        else if (c == '[') {
            it = output.begin();
            continue;
        }

        else if (c == '<') {
            if (it != output.begin()) {
                it = output.erase(--it); 
            }
        }

        else {
            it = output.insert(it, c);
            ++it;
        }
    }
    for (auto c: output) {
        cout << c;
    }
    cout << "\n";
}

int main() { 
    int cases;
    cin >> cases;
    string del;
    getline(cin, del); // sync up whitespace stuff
    for (; cases > 0; --cases) {
        tc();
    }
    return 0;
}
