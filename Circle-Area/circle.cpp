#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define pb push_back

typedef long long int ll;
using namespace std;

int main() {
    double a, b, c;

    while (cin >> a >> b >> c){
        if (a == 0 && b == 0 && c == 0){
            break;
        }
        double calc = M_PI * pow(a, 2);
        double est = 4 * pow(a,2) * (c / b);
        cout << calc << " " << est << "\n";
    }
    return 0;
}