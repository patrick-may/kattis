#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int shipment, bottle1_vol, bottle2_vol;
    int b1, b2;
    cin >> shipment >> bottle1_vol >> bottle2_vol;

    bool found = false;
    
    for(int x = shipment / bottle1_vol; x >= 0; x--) {

        int remainder = shipment - (bottle1_vol*x);
        if(remainder % bottle2_vol == 0) {
            b2 = remainder / bottle2_vol;
            cout << x << " " << b2 << "\n";
            found = true;
            break;
        }   
    }
    
    if(!found) {
        cout << "Impossible\n";
    }  
   
    return 0;
}