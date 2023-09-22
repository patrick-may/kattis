#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;
bool debug = false;

ll countClose (vector<int>& winners, vector<int>& losers, ll close){
    ll soln = 0;
    int w = 0, l = 0;
    while (w < winners.size()) {
        if (winners[w] - losers[l] > close){
            ++w;
        }
        else{
            ++w;
            ++l;
            ++soln;
        }
    }
    return soln;
    
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int c;
    ll range;
    cin >> c >> range;
    vector<ll> nums(pow(2, c));

    for(ll i = 0; i < pow(2, c); ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end(), [](ll l, ll r) {
            return l > r;
            });

    if (debug){
    for(auto n : nums) {
        cout << n << " ";
    }
    cout << "\n";
    }
    
    vector<ll> others;
    ll soln = 0;
    for(ll cutoff = 1; cutoff <= pow(2, c); cutoff *= 2) {
        ll offset = cutoff/2;
        vector<int> w(nums.begin(), nums.begin() + offset); 
        vector<int> l(nums.begin() + offset, nums.begin() + cutoff);
        if(debug) {
            cout << "winners\n";
            for (auto i : w) {
                cout << i << " "; 
            }
            cout << "\nlosers\n";
            for (auto i : l) {
                cout << i << " ";
            }
            cout << "\n";
        }
        soln += countClose(w, l, range);
    } 
    cout << soln << "\n";
    return 0;
}
