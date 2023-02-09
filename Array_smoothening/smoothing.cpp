#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    // double hash approach?
    map<int, int> freq_map;

    for(size_t i = 0; i < n; ++i) {
        int num;
        cin >> num;
        // add to frequency map
        if (freq_map.count(num)){
            freq_map[num]+=1;
        }
        else {
            freq_map[num] = 1;
        }
    }

    int overall_max = freq_map.rend()->second;
    //cout << overall_max << "\n";
    for(auto it = freq_map.rbegin(); it != freq_map.rend(); it++){
        cout << it->first << " " << it->second << "\n";
        k -= it->second;
        
        if (k < 0){
            break;
        }
        overall_max = it->;
    }
    if (k > 0){
        overall_max = 0;
    }
    printf("%i\n", overall_max); // printf is faster ig
    return 0;
}