#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    // double hash approach?
    map<int, int> freq_map;
    map<int, int> num_occurances;

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
        // thought: double hash, with second map counting the number of times a certain frequency occurs
        // then loop through K at the end taking slices off the top of these indicies until done
        int occurances = freq_map[num]
        if (num_occurances.count(occurances)){
            if occurances > 
        }
    }
    printf("%i\n", overall_max); // printf is faster ig
    return 0;
}