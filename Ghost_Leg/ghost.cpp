#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, rungs;
    cin >> n >> rungs;
    map<pair<int,int>, int> ghostyboi;

    for(int i = 0; i < rungs; ++i){
        int n_rung;
        cin >> n_rung;
        pair<int,int> my_pair = pair<int,int>(i, n_rung);
        ghostyboi[my_pair] = n_rung + 1;
        ghostyboi[pair<int,int>(i, n_rung + 1)] = n_rung; 
    }
    
    int perm[n + 1];
    for(int i = 1; i <= n; ++i) {
        // starting position is i
        int position = i;
        int traverse = 0;
        while(traverse < rungs){
            if(ghostyboi.count(pair<int,int>(traverse, position))){
                position = ghostyboi[pair<int,int>(traverse, position)];
            }
            traverse++;
        }
        perm[position] = i;
    }
    for(int i = 1; i <= n; ++i) {
        cout << perm[i] << "\n";
    }
    return 0;
}