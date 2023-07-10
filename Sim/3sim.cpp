// TLE... shucks!
#include <bits/stdc++.h>

using namespace std;

void tc() {
    string line;
    getline(cin, line);
    vector<char> f, b;
    bool preflag = false;
    
    for (char c : line) {
        if (c == ']') {
            preflag = false;
            continue;
        }
        else if (c == '[') {
            preflag = true;
            // prepend existing f into the beginning of b
            //b.resize(b.size() + f.size());
            f.insert(f.end(), b.begin(), b.end());
            b = f;
            f.clear();
            continue;
        }

        else if (c == '<') {
            if (preflag && f.empty()) {
                continue;
            }
            
            if (preflag && !f.empty()) {
                f.pop_back();
            }
            else if(!preflag && !b.empty()) {
                b.pop_back();
            }
            else if(!f.empty()){
                f.pop_back();
            }
        }

        else {
            if (preflag) {
                f.push_back(c);
            }
            else {
                b.push_back(c);
            }
        }
   }
    for (auto s: f) {
        cout << s;
    }
    for (auto s: b) {
        cout << s;
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
