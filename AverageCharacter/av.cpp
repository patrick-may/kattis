#include <iostream>
#include <string>

using namespace std;

int main() {

    string s;
    getline(cin, s); 
    int l = 0;
    for (char c : s) {
        l += c;
    }
    cout << char(l / s.length()) << "\n";
}
