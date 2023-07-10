// this approach didn't work, including it because it had some good ideas though
#include <bits/stdc++.h>

using namespace std;

void process(string& bs) {
    cout << bs << "\n";
    stack<char> text;

    for(auto c: bs){
        if (c == '<') {
            text.pop();
        }
        else {
            text.push(c);
        }
    }

    string actual = "";
    while (!text.empty()) {
        actual += text.top();
        text.pop();
    }
    
    string reversed = "";
    for(auto i = actual.rbegin(); i != actual.rend(); ++i) {
        cout << *i;
    }

}

void tc() {
    string line;
    getline(cin, line);
    string bs = "";
    string prepend = "";
    bool preflag = false;
    for (char c : line) {
        if (c == ']') {
            preflag = false;
            bs = prepend + bs;
            prepend = "";
            continue;
        }
        else if (c == '[') {
            preflag = true;
            continue;
        }

        if (preflag) {
            prepend += c;
        }
        else {
            bs += c;
        }
    }

    if (prepend != "") {
        bs = prepend + bs;
    }
    // do delete procs too
    process(bs);
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
