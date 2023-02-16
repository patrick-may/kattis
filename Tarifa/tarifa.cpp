#include <bits/stdc++.h>
using namespace std;

int main(){
    int mb_month, n;
    cin >> mb_month >> n;
    int total = 0;
    for (int i = 0; i < n; ++i){
        int used;
        cin >> used;
        total = (total + mb_month) - used;
    }
    cout << (total + mb_month) << "\n";
    
    return 0;
}