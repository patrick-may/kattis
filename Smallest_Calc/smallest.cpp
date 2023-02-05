#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> possibles;

    bool ab_div = (a % b) == 0;
    bool bc_div = (b % c) == 0;

    possibles.pb((a + b) + c); // ++
    possibles.pb((a + b) - c); // +-
    possibles.pb((a + b) * c); // +*
    
    if ((a + b) % c == 0){
        possibles.pb((a + b) / c); // +/
    }
    
    possibles.pb((a - b) + c); // -+
    possibles.pb((a - b) - c); // --
    possibles.pb((a - b) * c); // -*

    if ((a - b) % c == 0){
        possibles.pb((a - b) / c); // -/
    }

    possibles.pb((a * b) + c); // *+
    possibles.pb((a * b) - c); // *-
    possibles.pb((a * b) * c); // **

    if ((a * b) % c == 0){
        possibles.pb((a * b) / c); // */
    }
    
    if (ab_div) {
        possibles.pb( (a / b) + c); // /+
        possibles.pb( (a / b) - c); // /-
        possibles.pb( (a / b) * c); // /*

        if ((a/b) % c == 0){
            possibles.pb( (a / b) / c); // //
        }
        
    }

    int max = *max_element(possibles.begin(), possibles.end());

    for(int i: possibles){
        if (i < max && i > -1){
            max = i;
        }
    }

    cout << max << "\n";


    return 0;
}