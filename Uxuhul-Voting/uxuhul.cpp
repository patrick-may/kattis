#include <bits/stdc++.h>

using namespace std;

void subcase(){
    int priests;
    cin >> priests;
    vector<int> prefs(8);
    vector<string> opt = {"NNN", "NNY", "NYN", "NYY", "YNY", "YYN", "YYY"};
    for (int i = 0; i < priests; ++i){
        for (int j = 0; j < 8; ++j) {
            int temp;
            cin >> temp;
            prefs[j] += temp;
        }
    }
    int idx = 0;

    for(int i = 0; i < 8; ++i){
        cout << prefs[i] << " ";
        if (prefs[i] < prefs[idx]){
            idx = i;
        }
    }
    cout << "IDX is " << idx;
    cout << "\n" << opt[idx] << "\n";
}

int main(){
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i){
        subcase();
    }
    return 0;
}