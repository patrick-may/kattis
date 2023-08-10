#include <bits/stdc++.h>
using namespace std;
typedef ll long long;

long long fact(ll n){
    return (n == 1 || n == 0)? 1 : n * fact(n-1);
}

long long binomial(ll n, ll k){
    if (k > n || n <= 0 || k <= 0){
        return 0;
    }
    return fact(n) / ((fact(k)*fact(n - k)));
}

int main(){
    bool debug = false;
    map<ll, ll> mem;
    long long soln = 0;
    ll cases, divisor;

    cin >> cases >> divisor;
    for (int i = 0; i < cases; ++i) {
        ll a;
        cin >> a;
        ++mem[a/divisor];
    }
    for (auto p:mem){
        soln += binomial(p.second, 2);
    }
    if (debug){
        for(auto p:mem){
            cout << p.first << " " << p.second << "\n";
        }
    }
    cout << soln << "\n";
    return 0;
}
