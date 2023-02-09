#include <iostream>
#include <math.h>
using namespace std;

typedef long long int lli;

lli msb(lli n){
    lli ans = 0;
    while(n > 0){
        //cout << n << " ";
        ++ans;
        n /= 2;
    }
    return ans;
}

int main(){
    lli n;
    cin >> n;
    lli soln = 0;
    while (n > 0) {
        lli complete = msb(n) - 1;
        //cout << "\n complete is " << complete << "\n";
        n -= pow(2, complete);
        soln += pow(3, complete);
    }
    cout << soln << "\n";
    return 0;

}
