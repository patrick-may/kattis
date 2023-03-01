#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> knots;
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i){
        int temp;
        cin >> temp;
        knots.insert(temp);
    }
    for (int i = 0; i < cases - 1; ++i){
        int temp;
        cin >> temp;
        knots.erase(temp);
    }
    cout << *knots.begin() << "\n";
    
    return 0;
}