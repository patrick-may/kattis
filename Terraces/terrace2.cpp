// Patrick May
// Terraces (raaaaaa)

#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
using namespace std;

vector<int> adj(vector<vector<int>>& garden, pair<int,int> loc){
    vector<int> soln(4);
    //north
    soln[0] = garden[loc.first - 1][loc.second];
    //east
    soln[1] = garden[loc.first][loc.second + 1];
    //south
    soln[2] = garden[loc.first + 1][loc.second];
    //west
    soln[3] = garden[loc.first][loc.second - 1];
    return soln;
}

// visit all attached spaces of the same elevation based on current value loc
int visit(vector<vector<int>>& garden, pair<int,int> loc, set<pair<int,int>>& visited){
    bool debug = false;
    bool drain = false;
    int soln = 0;
    // establish a deque to traverse pockets of the same elevation
    deque<pair<int,int>> to_visit;
    int elev = garden[loc.first][loc.second];
    to_visit.pf(loc);
    while (to_visit.size() > 0) {
        pair<int,int> next = to_visit.front(); to_visit.pop_front();
        // if we have already visited a square, remove it from queue, don't count it
        if (visited.count(next)){
            continue;
        }

        // every new terrace square we visit makes our solution larger
        ++soln;
        if(debug){
            cout << "on loc" << next.first << " " << next.second << "\n";
        }
        
        vector<int> neighs = adj(garden, next);
        for (int i = 0; i < 4; ++i){
            // if a drainage was found, then we return 0 no matter what
            if (neighs[i] < elev){
                drain = true;
            } 
            // the following ifs are just a workaround to add the north, east, south, or west neighoring cell
            // if it matches the current elevation
            if (neighs[i] == elev && i == 0){
                to_visit.pb(pair<int,int>(next.first - 1, next.second));
            }
            else if (neighs[i] == elev && i == 1){
                to_visit.pb(pair<int,int>(next.first, next.second + 1));
            }
            else if (neighs[i] == elev && i == 2){
                to_visit.pb(pair<int,int>(next.first + 1, next.second));
            }
            else if (neighs[i] == elev && i == 3){
                to_visit.pb(pair<int,int>(next.first, next.second - 1));
            }
        }
        // VERY IMPORTANT! add the specific space to a set so that we remember
        // that we have already visited it
        visited.insert(next);

    }
    if (debug){
        cout << "returning " << (drain? 0 : soln) << "\n";
    }
    return drain? 0 : soln;
}

int main(){
    bool debug = false;
    int cols, rows;
    vector<vector<int>> garden;
    set<pair<int,int>> visited;
    int soln = 0;

    // gather input, with padding rows and cols of value 1000 (higher than any terrace level)
    cin >> cols >> rows;
    vector<int> border(cols+2, 1000);
    garden.pb(border);
    for (int i = 1; i < rows+1; ++i){
        vector<int> curr_row(cols+2);
        
        curr_row[0] = 1000; curr_row[cols + 1] = 1000;
        for (int j = 1; j < cols+1; ++j) {
            cin >> curr_row[j];
        }
        
        garden.pb(curr_row);
    }
    garden.pb(border);

    if (debug){
        for(auto i: garden){
            for(auto j: i){
                cout << j << " ";
            }
            cout << "\n";
        }
    }

    // visit every spot in the garden
    for(int i = 1; i < rows+1; ++i) {
        for (int j = 1; j < cols+1; ++j) {
            pair<int,int> curr_spot(i,j);
            // have we already visited this spot (we could have as visit can spindle outwards)
            if (visited.count(curr_spot)){
                continue;
            }
            soln += visit(garden, curr_spot, visited);
        }
        
    }
    cout << soln << "\n";
    return 0;
}