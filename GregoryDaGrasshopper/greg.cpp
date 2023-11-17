#include <set>
#include <iostream>
#include <deque>

using namespace std;

typedef struct node{
    pair<int, int> loc = {0, 0};
    int dist = 0;

    node(pair<int, int> l, int d) {
        loc = l;
        dist = d;
    }
    node () {
        loc = {-1, -1};
        dist = -1;
    }
} node;

deque<node> extendJumps(int R, int C, node& curr){

    int cR = curr.loc.first, cC = curr.loc.second;  

    deque<node> addme;
    if (cR + 1 < R) {
        if (cC + 2 < C) {
            addme.push_back(node({cR + 1, cC + 2}, curr.dist + 1));
        }
        if (cC - 2 >= 0) {
            addme.push_back(node({cR + 1, cC - 2}, curr.dist + 1));
        }
    }

    if (cR + 2 < R) {
        if (cC + 1 < C) {
            addme.push_back(node({cR + 2, cC + 1}, curr.dist + 1));
        }
        if (cC - 1 >= 0) {
            addme.push_back(node({cR + 2, cC - 1}, curr.dist + 1));
        }
    }


    if (cR - 1 >= 0) {
        if (cC + 2 < C) {
            addme.push_back(node({cR - 1, cC + 2}, curr.dist + 1));
        }
        if (cC - 2 >= 0) {
            addme.push_back(node({cR - 1, cC - 2}, curr.dist + 1));
        }
    }

    if (cR - 2 >= 0) {
        if (cC + 1 < C) {
            addme.push_back(node({cR - 2, cC + 1}, curr.dist + 1));
        }
        if (cC - 1 >= 0) {
            addme.push_back(node({cR - 2, cC - 1}, curr.dist + 1));
        }
    }

    return addme;
}

void minJumps(int row, int col, pair<int,int> start, pair<int,int> goal) {
    set<pair<int,int>> visited;
    deque<node> to_visit = {node(start, 0)};
    
    while (!to_visit.empty()) {
        node worker = to_visit[0]; 
        to_visit.pop_front();
        if (worker.loc == goal) {
            cout << worker.dist << endl;
            return;
        }
        
        if (visited.count(worker.loc)) {
            continue;
        }

        visited.insert(worker.loc);
        for (const node neighbor : extendJumps(row, col, worker)) {
            if (!visited.count(neighbor.loc)) {
                to_visit.push_back(neighbor);
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
