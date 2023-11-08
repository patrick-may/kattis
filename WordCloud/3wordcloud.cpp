#include <vector>
#include <iostream>
#include <map>

using namespace std;

bool debug = 0;
typedef struct  Rect {
    
    Rect() {
        width = 0;
        height = 0;
    }
    Rect(int h, int w) {
        width = w;
        height = h;
    }
    int width = 0;
    int height = 0;

} Rect;

// returns the minimum 
int dp(int idx, vector<Rect>& words, const int WIDLIM, map<int,int>& fits, map<int, int>& nofits, int currw, int currh) {
    if (debug) {
        cout << idx << " " << currw << " " << endl;
    }
    if (idx == words.size()) {
        return currh; 
    }
    
    // dynamic proggie stuffs
    if (nofits.count(idx)) {
        int notake = nofits[idx];
        if (fits.count(idx) && words[idx].width + currw <= WIDLIM) {
            return min(notake, fits[idx]);
        }
        return notake;
    }

    int newline, sameline = -1;
    // if we can smush
    if (currw + words[idx].width <= WIDLIM) {
        sameline = dp(idx + 1, 
                words, 
                WIDLIM, 
                fits,
                nofits,
                currw + words[idx].width, 
                max(currh, words[idx].height)
                );
        fits[idx] = sameline;
    }
    
    // prior height, plus remaining height
    newline = currh + dp(idx + 1,
            words, 
            WIDLIM,
            fits,
            nofits,
            words[idx].width, 
            words[idx].height
            );

    nofits[idx] = newline;
    // if we had to place on a new spot
    if (sameline == -1) {
        return newline;
    }

    return min(newline, sameline);
 
}

int main() {
    int n, width;
    cin >> n >> width;
    vector<Rect> nums(n); 
    map<int, int> mem1, mem2;
    for(int i = 0 ; i < n; ++i) {
        int h, w;
        cin >> w >> h;
        nums[i] = Rect(h, w);
    }

    cout << dp(0, nums, width, mem1, mem2, 0, 0) << "\n";
    return 0;
}
