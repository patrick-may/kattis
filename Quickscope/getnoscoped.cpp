#include <bits/stdc++.h>

using namespace std;

typedef struct Quickscoper {
  map<string, string> variables;
  stack<string> scope;

  void step_in() { scope.push("{"); }

  void step_out() {

    while (scope.top() != "{") {
      variables.erase(scope.top());
      scope.pop();
    }
    scope.pop(); // remove the {
  }

  void declare(string ident, string type) {
    if (variables.count(ident)) {
      cout << "MULTIPLE DECLARATION\n";
      exit(0);
    }

    variables[ident] = type;
    scope.push(ident);
  }

  void type_of(string ident) {
    if (variables.count(ident)) {
      cout << variables[ident] << "\n";
      return;
    }

    cout << "UNDECLARED\n";
    return;
  }

} Quickscoper;

int main() {
  int lines;
  cin >> lines;
  Quickscoper qs;
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
  }
}
