#include <bits/stdc++.h>
using namespace std;

long long proper_divs(int n){
    int sum = 1;
    set<int> seen;
    for (int i = 2; i <= sqrt(n); ++i){
        
        if (n % i == 0 && seen.count(i) == 0 && seen.count(n/i) == 0){
            //cout << sum << " plus " << i << " " << n/i << "\n";
            sum += i + n/i;
            if (i == n/i){
                sum -= i;
            }
            seen.insert(i);
        }
    }
    return sum;
}
void perfect(int n){
    int sum = proper_divs(n);
    if (sum == n){
        cout << n << " perfect\n";
    }
    else if (sum > n - 3 && sum < n + 3){
        cout << n << " almost perfect\n";
    }
    else{
        cout << n << " not perfect\n";
    }
}

int main(){
    int n;
    while (cin >> n){ // go to EOF
        perfect(n);
    }

    return 0;
}