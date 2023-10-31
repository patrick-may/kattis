#include <iostream>
using namespace std;
int main() {
    int a[10];
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }

    int b, c;
    cin >> b >> c;
    int d = 0;
    for (int i = 1; i < 10; i+=2) {
        d += (a[i - 1] * a[i]);
    }
    d /= 5;

    cout << (b * d) / (c) << "\n";

}
