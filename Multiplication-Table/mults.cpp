#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// used for checking work in smaller cases
void naive(ll n, ll m){
    ll soln = 0;
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j){
            ll val = i * j;
            if (val == m){
                cout << i << " " << j << "\n";
                soln += 1;
            }
        }
    }
    cout << "tabular soln is " << soln << "\n";
}

int main(){
    ll n, m;
    cin >> n >> m;

    ll soln = 0;
    // generate all factorings of m
    //cout << sqrt(m) << "\n";
    for (ll i = 1; i <= sqrt(m); ++i){
        if (i > n){
            break;
        }
        if (m % i == 0) {
            ll pair = m / i;
            
            if (pair <= n && i <= n) { // check if this pair is within the bounds of our n x n matrix
                //cout << "pair found: " << i << " " << pair << "\n";
                soln += 2; // account for the fact that i * pair means pair * i also in table
                // however, if they are a i * i match, then actually only 1 pair exists in the table (on the diagonal)
                if (pair == i){
                    soln -= 1;
                }
            }
        }
    }
    
    cout << soln << "\n";
    //naive(n, m);
    return 0;
}