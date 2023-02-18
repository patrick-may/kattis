#include <bits/stdc++.h>

using namespace std;
long long fact(int n){
    return (n == 1 || n == 0)? 1 : n * fact(n-1);
}

long long binomial(int n, int k){
    if (k > n || n <= 0 || k <= 0){
        return 0;
    }
    return fact(n) / ((fact(k)*fact(n - k)));
}

int main(){
    bool debug = false;
    map<int, int> mem;
    long long soln = 0;
    int cases, divisor;

    cin >> cases >> divisor;
    for (int i = 0; i < cases; ++i) {
        int a;
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