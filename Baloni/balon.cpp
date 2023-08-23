#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ct;
    cin >> ct;
    
    vector<int> heights(ct + 1, 0);

    int soln = 0;
    for (int i = 0; i < ct; ++i) {
        int nextbal;
        cin >> nextbal;
        if (heights[nextbal] > 0) {
            // arrow already flying at current height
            heights[nextbal]--;
            heights[nextbal-1]++;
        }
        else {
            // fire a new arrow
            heights[nextbal-1]++;
        }
        
    }
    for (const auto act : heights) {
        soln += act;
    }
    cout << soln << "\n";
    return 0;
}
