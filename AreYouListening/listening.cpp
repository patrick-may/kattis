#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
float dist(int x1, int y1, int x2, int y2, int r) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) - r;
}
int main() {
    int myx, myy, n;
    cin >> myx >> myy >> n;
    
    vector<float> closets(n);
    for (int i = 0; i < n; ++i) {
        int x, y, r;
        cin >> x >> y >> r;
        closets[i] = dist(myx, myy, x, y, r);
    }

    sort(closets.begin(), closets.end());
    
    if (false) {
        for (auto c : closets) {
            cout << c << " ";
        }
        cout << "\n";
    }
    int best = 0;
    int smallerThan = 0;
    int i = 0;
    while (best < floor(closets[2])) {
        ++best;  
    }
    cout << best << "\n";
    return 0;
}
