#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

//nothing special here, just make sure to reduce fraction properly
void calculate(){
    ll x1, y1, x2, y2;
    char op;
    cin >> x1 >> y1 >> op >> x2 >> y2;

    if(op == '+'){
        ll top = x1*y2 + x2*y1;
        ll bot = y2*y1;
        ll g = gcd(top, bot);
        if(bot < 0){
            bot*=-1;
            top*=-1;
        }
        
        cout << (top / g) << " / " << (bot/g) << endl; 
    }

    if(op == '-'){
        ll top = (x1*y2) - (x2*y1);
        ll bot = y2*y1;
        ll g = gcd(top, bot);
        g = abs(g);
        if(bot < 0){
            bot*=-1;
            top*=-1;
        }
         
        cout << (top / g) << " / " << (bot/g) << endl; 
    }
    
    if(op == '*'){
        ll top = x1*x2;
        ll bot = y2*y1;
        ll g = gcd(top, bot);
        
        if(bot < 0){
            bot*=-1;
            top*=-1;
        }
        cout << (top / g) << " / " << (bot/g) << endl; 
    }

    if(op == '/'){
        ll top = x1*y2;
        ll bot = x2*y1;
        ll g = gcd(top, bot);
        if(bot < 0){
            bot*=-1;
            top*=-1;
        }
       
        cout << (top / g) << " / " << (bot/g) << endl; 
    }

}

int main(){
    int iterations;
    cin >> iterations;
    
    for(int x = 0; x < iterations; ++x){
        calculate();
    }

    return 0;
}