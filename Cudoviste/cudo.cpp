#include <bits/stdc++.h>
#define pb push_back

using namespace std;


int main() {
    bool debug = false;
    int row, col;
    cin >> row >> col;
    vector<vector<char>> lot;
    map<int, int> soln;
    for(int i = 0; i < row; ++i){
        vector<char> inp(col);
        for(int j = 0; j < col; ++j) {
            cin >> inp[j];
        }
        lot.pb(inp);
    }

    if (debug){
        for(auto i: lot){
            for(auto j: i){
                cout << j << " ";
            }
            cout << "\n";
        }
    }

    for(int i = 0; i < row - 1; ++i){
        for(int j = 0; j < col - 1; ++j){
            int bldg;
            int cars = 0;
            if (lot[i][j] == '#' || lot[i+1][j] == '#' || lot[i][j+1] == '#' || lot[i+1][j+1] == '#'){
                continue;
            }
            cars += (lot[i][j] == 'X') + (lot[i+1][j] == 'X') + (lot[i][j+1] == 'X') + (lot[i+1][j+1] == 'X');
            ++soln[cars];
        }
    }
    for (int i = 0; i < 5; ++i){
        cout << soln[i] << "\n";
    }
    return 0;
}