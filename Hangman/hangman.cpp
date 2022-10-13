#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


int main(){
    string word, guess;
    cin >> word >> guess;

    int lives = 10;

    for(int x = 0; x < guess.length(); ++x){
        if(word == ""){
            cout << "WIN" << endl;
            return 0;
        }
        string letter = guess.substr(x, 1);

        //cout << "letter " << letter << endl;
        if(word.find(letter) == string::npos){
            lives--;
            //cout << " lives -1 " << endl;
            if(lives == 0){
                cout << "LOSE" << endl;
                return 0;
            }
        }
        while(word.find(letter) != string::npos){
            word.erase(word.find(letter), 1);
            //cout << "new word: " << word << endl;
        }
    }
    cout << "WIN" << endl;

    return 0;
}