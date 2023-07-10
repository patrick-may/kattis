#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<char> text;
    string line;
    getline(cin, line);

    for(auto c: line){
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
