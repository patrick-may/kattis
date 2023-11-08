#include <vector>
#include <iostream>

using namespace std;

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

typedef struct wc {
    int w = 0;
    int h = 0;
    int currw = 0;
    int currh = 0; 
    
    void placeSame(Rect& block) {
        currw += block.width;
        currh = max(block.height, currh);
    }

    void placeNewRow(Rect& block) {
        update();
        currw += block.width;
        currh += block.height;
    }

    void update() {
        h += currh;
        currw = 0;
        currh = 0;
    }

    int getHeight() {
        return h;
    }

} wc;

int dp(int idx, vector<Rect>& words, wc wordcloud) {
    if (idx == words.size()) {
        return wordcloud.getHeight();
    }
    
    int res = 9999 * 9999;
    if (wordcloud.currw + words[idx].width <= wordcloud.w) {
        wc newwc = wordcloud;
        newwc.placeSame(words[idx]);
        res = dp(idx + 1, words, newwc);
    }
    
    wc otherwc = wordcloud;
    otherwc.placeNewRow(words[idx]);
    res = min(dp(idx + 1, words, otherwc), res);
 
    return res;
}

int main() {
    int n, width;
    cin >> n >> width;
    vector<Rect> nums(n); 

    for(int i = 0 ; i < n; ++i) {
        int h, w;
        cin >> w >> h;
        nums[i] = Rect(h, w);
    }
    wc wordcloud;
    wordcloud.w = width;
    cout << dp(0, nums, wordcloud) << "\n";
    return 0;
}
