#include <bits/stdc++.h>
using namespace std;

int main(){
    int blocks;
    cin >> blocks;
    int size = 1;
    while (size < blocks){
        blocks -= pow(size, 2);
        if (blocks < 0){
            break;
        }
        size += 2;
    }
    cout << (size)/2 << "\n";
    

    return 0;
}