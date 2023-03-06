#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, T;
    cin >> N >> T;
    vector<int> pots(N);
    for(int i = 0; i < N; ++i){
        cin >> pots[i];
    }

    // sort descending
    sort(pots.rbegin(), pots.rend());

    // drink longest-lasting potion, then time remaining is duration of potion
    int remaining = pots[0]; 

    // for all remaining potions
    for (int i = 1; i < pots.size(); ++i){
        //cout << "rem time " << remaining  << "\n" << "checking value " << pots[i] << " \n"; 
        
        // can I drink this potion in the remaining time? If it takes the remaining time or more,
        // a prior potion will wear off
        if (T >= remaining){
            cout << "NO" << "\n";
            exit(0);
        }
        
        // remaining time will either be how much time until current potion expires
        // or if the current potion would last longer than needed, then time remaining on prior potion after drinking
        remaining = min(remaining - T, pots[i]);
        
    }
    cout << "YES" << "\n";
    return 0;
}