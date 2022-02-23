#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll prime_factorize_count(ll inp){
    ll factors = 0;
    
    //factor out all possible twos, then inp must be an odd number
    while(inp % 2 == 0){
        factors++;
        inp /= 2;
    }

    //loop up until odd_prime^2 is > odd composite number
    //increment by 2. some numbers in increment will not be prime, but those will not get counted
    //as the smaller primes that compose them have already been factored out of inp.
    ll odd_prime = 3;
    ll copy = inp;
    for(odd_prime; odd_prime * odd_prime <= copy; odd_prime = odd_prime + 2){
        
        while(!(inp % odd_prime)){
            factors++;
            inp /= odd_prime;
        }
        
    }

    // if inp > 1, inp is a prime number, so a positive inp - 1 exists, so add one to potential factors of original
    // input value
    if (inp > 1){
        factors++;
    }
    return factors;
}

void solve(ll inp){
    //if inp == 1, the does not exist any positive integer such that p + 1 = 1. 
    //Also outside of possible input data
    if(inp == 1){
        cout << "0" << endl;
        return;
    }

    ll ans = prime_factorize_count(inp);
    cout << ans << endl;

}

// main part of problem is prime factorize a given number, and return the number of factors
int main(){
    ll inp;

    cin >> inp;

    solve(inp);

    return 0;
}