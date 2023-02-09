#include <bits/stdc++.h>

using namespace std;
int lookup(char card, char suit, char dom) {
    if (card == 'A'){
        return 11;
    }
    if (card == 'K'){
        return 4;
    }
    if (card == 'Q'){
        return 3;
    }
    if (card == 'J') {
        if (suit == dom){
            return 20;
        }
        return 2;
    }
    if (card == 'T'){
        return 10;
    }
    if (card == '9' && suit == dom){
        return 14;
    }
    return 0;
}
int main(){
    int hands;
    char dom;
    cin >> hands >> dom;
    int sum = 0;
    for (int i = 0; i < 4*hands; ++i){
        char val, s;
        cin >> val >> s;
        sum += lookup(val, s, dom);
    }
    cout << sum << "\n";


    return 0;
}