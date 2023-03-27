#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases;
    cin >> cases;
    // read
    vector<int> prices(cases);
    for(int i = 0; i < cases; ++i){
        cin >> prices[i];
    }
    // sort descending
    sort(prices.rbegin(), prices.rend());
    int price = 0;
    // skip every third
    for(int i = 1; i <= cases; ++i){
        if (i % 3 == 0){
            continue;
        }
        price += prices[i - 1];
    }
    cout << price <<"\n";
    return 0;
}