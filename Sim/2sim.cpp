// this also wasnt it, as we need to merge the two stacks every time we switch back to append to end of file from being at the beginning of the file
// take 3!
#include <bits/stdc++.h>

using namespace std;

void tc() {
    string line;
    getline(cin, line);
    stack<char> end;
    stack<char> front;

    bool preflag = false;
    
    for (char c : line) {
        cout << c << "\n";
        if (c == ']') {
            preflag = false;
            continue;
        }
        else if (c == '[') {
            preflag = true;
            continue;
        }

        if (c == '<') {
            if(preflag) {
                front.pop();
            }
            else{
                if (end.empty()){
                    front.pop();
                }
                else{
                    end.pop();
                }
            }
        }

        else {
            if(preflag){
                front.push(c);
            }
            else{
                end.push(c);
            }
        }
    }

    string fsoln = "";
    while(!front.empty()) {
        fsoln += front.top();
        front.pop();
    }
    string bsoln = "";
    while (!end.empty()) {
        bsoln += end.top();
        end.pop();
    }
    cout << fsoln << "\n" << bsoln;
    cout << "\n\n";
    for(auto it = fsoln.rbegin(); it != fsoln.rend(); ++it) {
        cout << *it;
    }
    for (auto it = bsoln.rbegin(); it != bsoln.rend(); ++it) {
        cout << *it;
    }
    cout << "\n\n";

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
