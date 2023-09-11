#include <iostream>
#include <string>

using namespace std;
int main() {
    int speed, cases;
    cin >> speed >> cases;

    for (int i = 0; i < cases; ++i) {
        string road;
        int maxspeed;
        cin >> road >> maxspeed;
        cout << road << (maxspeed >= speed ? " opin" : " lokud") << "\n";
    }
    return 0;
}
