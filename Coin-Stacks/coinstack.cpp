#include <bits/stdc++.h>

using namespace std;

int main(){
    int stacks;
    int total_coins = 0;
    vector<int> vals(stacks);
    cin >> stacks;
    for(int i = 0; i < stacks; ++i) {
        int temp;
        cin >> temp;
        vals[i] = temp;
        total_coins += temp;

    }
    if (total_coins % 2){
        cout << "no\n";
        exit();
    }

    return 0;
}