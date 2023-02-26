#include <bits/stdc++.h>

using namespace std;


int main(){
    int guess = 500;
    int left = 1; 
    int right = 1000;
    string response;
    cout << guess << endl;
    fflush(stdout);
    while (cin >> response){
        if(response == "correct"){
            return 0;
        }

        if(response == "lower"){
            right = guess - 1;
        }
        else if(response == "higher"){
            left = guess + 1;
        }
        guess = (right + left)/2;
        cout << guess << endl;
        fflush(stdout);
    }
    return 0;

}