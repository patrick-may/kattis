#include <bits/stdc++.h>

using namespace std;

vector<int> get_adj(vector<vector<int>>& garden, pair<int,int> loc){
    vector<int> neighbors(4);
    // nort == 0
    // south == 1
    // each == 2
    // wesh == 3
    int rows = garden.size();
    int cols = garden[0].size();
    int x = loc.first;
    int y = loc.second;
    if (x == 0){
        neighbors[0] = 1000;
    }
    else{
        neighbors[0] = garden[x - 1][y];
    }
    if (y == 0) {
        neighbors[3] = 1000;
    }
    else {
        neighbors[3] = garden[x][y-1];
    }
    if (x == rows - 1){
        neighbors[1] = 1000;
    }
    else {
        neighbors[1] = garden[x + 1][y];
    }
    if (y == cols - 1){
        neighbors[2] = 1000;
    }
    else {
        neighbors[2] = garden[x][y + 1];
    }
    return neighbors;
}

int island_add(vector<vector<int>>& garden, pair<int, int> loc, set<pair<int,int>>& visited){
    // seek out larger than singleton spots
    // return how many points to add
    // add all the points to our visited set so we don't revisit island later
    int rows = garden.size();
    int cols = garden[0].size();
    int elevation = garden[loc.first][loc.second];
    set<pair<int,int>> same_elevation;
    deque<pair<int,int>> to_visit;
    to_visit.push_back(loc);
    bool exit = false;
    while (to_visit.size() && !exit) {
        // get first spot to see
        pair<int,int> working_space = to_visit[0];
        to_visit.pop_front();
        int x, y;
        x = working_space.first;
        y = working_space.second;
        visited.insert(working_space);
        same_elevation.insert(working_space);
        cout << "on location " << x << " " << y << "\n";

        vector<int> neighbors = get_adj(garden, working_space);

        //cout << "adjacent values are ";

        //for(int i: neighbors){
        //    cout << i << " ";
        //}
        //cout << "\n";

        /*cout << "known adjacent elevantions are";
        for(auto i:same_elevation){
            cout << i.first << " " << i.second << "\n";
        }*/
        for (int i = 0; i < 4; ++i){
            cout << neighbors[i] << " " << elevation << "\n";
            if (neighbors[i] < elevation){
                exit = true;
                break;
            }
            if (neighbors[i] == elevation){

                // ugly form to find which node is same elevation
                if (i == 0 && same_elevation.count(pair<int,int>(x, y - 1)) == 0 && y > 0){
                    to_visit.push_back(pair<int,int>(x , y-1));
                    //cout << "north added " << x << " " << y -1<< "\n";
                }
                else if (i == 1 && same_elevation.count(pair<int,int>(x, y + 1)) == 0 && y < cols - 1){
                    to_visit.push_back(pair<int,int>(x, y + 1));
                    //cout << "south added " << x  << " " << y+1 << "\n";
                }
                else if (i == 2 && same_elevation.count(pair<int,int>(x + 1, y)) == 0 && x < rows - 1){
                    to_visit.push_back(pair<int,int>(x + 1, y));
                    //cout << "east added " << x +1 << " " << y << "\n";
                }
                else if (i == 0 && same_elevation.count(pair<int,int>(x - 1, y)) == 0 && x > 0){
                    to_visit.push_back(pair<int,int>(x-1, y ));
                    //cout << "west added " << x-1 << " " << y  << "\n";
                }  

                
            }
        }
        
        
    }
    cout << "completed! island has no drainage and is of size" << same_elevation.size() << "\n";
    return (exit) ? same_elevation.size() : 0;
    
}
int main(){
    bool debug = true;
    int cols, rows;
    vector<vector<int>> garden;
    set<pair<int,int>> visited;
    int soln = 0;

    // gather input
    cin >> cols >> rows;
    for (int i = 0; i < rows; ++i){
        vector<int> curr_row(cols);
        for (int j = 0; j < cols; ++j) {
            cin >> curr_row[j];
        }
        garden.push_back(curr_row);
    }

    if (debug){
        for(auto i: garden){
            for(auto j: i){
                cout << j << " ";
            }
            cout << "\n";
        }
    }

    for(int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (visited.count(pair<int,int>(i, j))){
                continue;
            }
            int curr_level = garden[i][j];
            // ugly long if statements to find values of adjacent cells
            vector<int> neighbors = get_adj(garden, pair<int,int>(i, j));
            int n, s, w, e;
            n = neighbors[0]; s = neighbors[1]; w = neighbors[2]; e = neighbors[3];
            //cout << n << " " << s << " " << w  << " " << e << "\n";

            // simple case: singleton pool. value is less than all neighboring cells
            if (curr_level < n && curr_level < s && curr_level < e && curr_level < w){
                ++soln;
            }

            // second case will involve finding the "islands" and their bordering values
            else if (curr_level == n || curr_level == s || curr_level == e || curr_level == w){
                //cout << "rut rough shaggy" << "\n";
                soln += island_add(garden, pair<int,int>(i, j), visited);
            }
            // remember islands we have visited before at te end of each iteration
            visited.insert(pair<int,int>(i,j));
        }
        
    }
    cout << soln << "\n";
    return 0;
}