#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
bool debug = true;

void relatives(ll n) {
    ll soln = n;
    // for all possible prime divisors
    for (ll i = 2; i * i < n; ++i) {
        // if i is a factor of n
        if (n % i == 0) {
            // factor out n until cant
            while (n % i == 0) {
                   n /= i;
                }
            // update solution s.t. these numbers are NOT part of 
            // overall value, as soln / i is the count of numbers
            // that are factors (not rel prime)
            soln -= soln / i;
            }
        }
    if (n > 1) {
       soln -= soln / n;
    }
    cout << soln << "\n";
}

int main(){
    ll num;
    cin >> num;
    while (num) {
        relatives(num);
        cin >> num;
    }
    return 0;
}
