#include <iostream>
#include <string>

using namespace std;

bool debug = true;
int main() {
    int n, width;
    cin >> n >> width;
    
    int currw = 0;
    int currh = 0;
    int maxheight = 0;
    int r = 0;    
    bool added = false;
    for(int i = 0 ; i < n; ++i) {
        int h, w;
        cin >> w >> h;
        if (debug) {
            cout << r << " " << maxheight << " " <<  w << " " << h << "\n";
        }
        // can we place the current box in the current row?
        if (currw + w < width) {
            // place it adjacent
            currh = max(currh, h);
            currw += w;
            added = false;
        }
        // place in new row
        else {
            r += 1;
            added = true;
            maxheight += currh;
            currh = 0;
            currw = w;
            currh = h;
        }
    }
    if (!added) {
        maxheight += currh;
    }

    cout << maxheight << "\n";
    return 0;
}
