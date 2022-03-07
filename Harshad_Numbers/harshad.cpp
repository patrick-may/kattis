#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; int sum = 0;
    cin >> n;
    //cout << n << endl;
    bool found = false;

    
    while(!found){
        
        string digits = to_string(n);
        
        sum = 0;
        for(int x = 0; x < digits.length(); x++) {
            
            sum += stoi(digits.substr(x, 1));
        }
        //cout <<"digits "<< digits << endl;
        //cout <<"sum "<< sum << endl;
        if(n % sum == 0){
            cout << n << endl;
            found = true;
        }
        n++;

    }
}