#include <bits/stdc++.h>

using namespace std;

int digit_sum(int n){
    int sum = 0;
    while (n > 0){
        sum += n % 10;
        n /= 10;
    }
    //cout << "sum of " << n << " is " << sum << "\n";
    return sum;
}

int main(){
    int l, d, x;
    cin >> l >> d >> x;

    int minimal = l; int maximal = d;
    
    while (digit_sum(minimal) != x){
        ++minimal;
        //cout << minimal << "\n";
    }
    while (digit_sum(maximal) != x) {
        --maximal;
        //cout << maximal << "\n";
    }
    cout << minimal << "\n" << maximal << "\n";
    return 0;
}