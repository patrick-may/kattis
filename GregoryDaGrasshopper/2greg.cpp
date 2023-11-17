#include <set>
#include <iostream>
#include <deque>
#include <vector>

#define INF 999999
using namespace std;

bool checkValid(int r, int c, int jumpr, int jumpc) {
    return (jumpr < r && jumpr >= 0 && jumpc < c && jumpc >= 0);
}

void minJumps(int row, int col, pair<int,int> start, pair<int,int> goal) {
    start.first -= 1;
    start.second -= 1;
    goal.first -= 1;
    goal.second -= 1;

    vector<vector<int>> board(row, vector<int>(col, INF));
    deque<pair<int,int>> to_visit = {start};

    // 0 dist to start
    board[start.first][start.second] = 0;
    while(!to_visit.empty()) {
        pair<int,int> front = to_visit[0];
        to_visit.pop_front();
        int jumpdist = board[front.first][front.second];
        // reached goal
        if (front == goal) {
            cout << jumpdist << endl;
            return;
        }

        pair<int, int> mods[8] = {{+2, +1},{+2, -1}, {+1, +2}, {+1, -2},
            {-1, +2}, {-1, -2}, {-2, +1}, {-2, -1}};
        
        for (const pair<int,int> p : mods) {
            int xshift = p.first, yshift = p.second;
            if (checkValid(row, col, front.first + xshift, front.second + yshift) && board[front.first + xshift][front.second + yshift] == INF) {
                board[front.first + xshift][front.second + yshift] = jumpdist + 1;
                to_visit.push_back({front.first + xshift, front.second + yshift});
            }     
        }

    }
    cout << "impossible" << endl;
    return;

}

int main() {
    
    int R, C, Rstart, Cstart, Rgoal, Cgoal;
    
    while (cin >> R >> C >> Rstart >> Cstart >> Rgoal >> Cgoal) {
        minJumps(R, C, {Rstart, Cstart}, {Rgoal, Cgoal});
    }; 
    
}
