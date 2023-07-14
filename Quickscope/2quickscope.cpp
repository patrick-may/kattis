#include <bits/stdc++.h>

using namespace std;

typedef struct Quickscoper {
    map<string, vector<string>> variables;
    stack<set<string>> scope;

    Quickscoper() {
        set<string> a;
        scope.push(a);
    }
    void step_in() {
        set<string> a;
        scope.push(a);
    }

    void step_out() {
        for (auto key : scope.top()) {
            variables[key].pop_back();
        }
        scope.pop();  // remove last frame
    }

    void declare(string ident, string type) {
        if (scope.top().count(ident)) {
            cout << "MULTIPLE DECLARATION\n";
            exit(0);
        }

        variables[ident].push_back(type);
        scope.top().insert(ident);
    }

    void type_of(string ident) {
        if (variables.count(ident) && variables[ident].size() > 0) {
            cout << *variables[ident].rbegin() << "\n";
            return;
        }

        cout << "UNDECLARED\n";
        return;
    }

    void printqs() {
        cout << "Map:\n";
        for (auto p : variables) {
            cout << p.first << "\n";
            for (auto v : p.second) {
                cout << "\t" << v << "\n";
            }
        }
    }

} Quickscoper;

int main() {
    int lines;
    cin >> lines;
    Quickscoper qs = Quickscoper();
    for (; lines > 0; --lines) {
        string command;
        cin >> command;
        if (command == "{") {
            qs.step_in();

        } else if (command == "}") {
            qs.step_out();

        } else if (command == "TYPEOF") {
            string a;
            cin >> a;
            qs.type_of(a);

        } else if (command == "DECLARE") {
            string a, b;
            cin >> a >> b;
            qs.declare(a, b);
        }
        // qs.printqs();
    }
}
