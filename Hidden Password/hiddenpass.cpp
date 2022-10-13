#include <bits/stdc++.h>

using namespace std;

int main() {
    string password, message;
    cin >> password >> message;

    string copypass = password;
    
    int len = password.length();

    string pass_char;
    size_t correct_loc, not_loc;
    
    for(int x = 0; x < len; ++x) {
        
        pass_char = password.substr(0,1);
        correct_loc = message.find(pass_char);
        
        if(correct_loc == string::npos) {
            cout << "FAIL\n";
            return 0;
        }

        for (int y = 1; y < password.length(); ++y) {
            
            if(message.find(password[y]) < correct_loc) {
                cout << "FAIL\n";
                return 0;
            }
            
        }
        
        password = password.substr(1);
        message = message.substr(correct_loc+1);
        cout << endl << endl;
    }

    cout << "PASS\n";    
    
    return 0;
}