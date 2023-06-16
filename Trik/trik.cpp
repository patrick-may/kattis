#include <bits/stdc++.h>

using namespace std;


int main() {
    string moves;
    cin >> moves;

    int loc = 1;
    for (char c : moves) {
        
        switch(c) {
            case 'A': 
                if (loc == 1){
                    loc = 2;
                }
                else if(loc == 2) {
                    loc = 1;
                }
                break;

            case 'B':
                if (loc == 2){
                    loc = 3;
                }
                else if(loc == 3) {
                    loc = 2;
                }
                break;

            case 'C':
                if (loc == 1) {
                    loc = 3;
                }
                else if (loc == 3) {
                    loc = 1;
                }
                break;
        }
    }
    cout << loc << "\n";
}