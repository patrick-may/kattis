#include <bits/stdc++.h>

using namespace std;

// quick way to see what is in a map

void debug_print(map<int, int>& m){
    cout << "person\tbalance\n";

    for(auto p :m) {
        cout << p.first << "\t" << p.second << "\n";
    }
    return;
}

int main() {
    int people, lines;
    cin >> people >> lines;
    // cout << people << lines;
    
    map<int, int> bals;
    int offset = 0;
    for (int i = 0; i < lines; ++i){
        string comm;
        int person, trans;
        cin >> comm;
        
        //debug_print(bals);
        switch(comm[0]){
            case 'S':
                cin >> person >> trans;
                bals[person] = trans;
                break;

            case 'P':
                cin >> person;
                //cout << "printing " << person << " offest " << offset << " balanace " << bals[person] << "\n";
                int val;
                if (bals.count(person) == 0){ // person's bal not set manually, so it will be whatever the overall reset val is
                    val = offset;
                }
                else {
                    val = bals[person]; // but if it has been explicitly set, then yield their proper value
                }               
                cout << val << "\n";
                break;

            case 'R':
                cin >> trans; // read in the reset value
                offset = trans; // remember as `offset`
                bals.clear(); // clear the memory of prior bank bals
                break;   // exit switch
        }
    }
    return 0;
}