#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool debugio = false;
bool debug = true;

void tc() {
    int milk, cats;
    cin >> milk >> cats;
    
    vector<vector<int>> dists(cats, vector<int>(cats));
    vector<vector<int>> edges((cats * (cats - 1)) / 2, vector<int>(3));

    if (debugio) {
        for (auto v : dists) {
            for (auto c : v) {
                cout << c << " ";
            }
            cout << endl;
        }
    }
    for (int i = 0; i < (cats * (cats - 1)) / 2; ++i) {
        int c1, c2, dist;
        cin >> c1 >> c2 >> dist; 
        dists[c1][c2] = dist;
        dists[c2][c1] = dist;
        edges[i] = {c1, c2, dist};
    }

    if (debugio) {
        cout << "inputted \n";
        for (auto v : dists) {
            for (auto c : v) {
                cout << c << " ";
            }
            cout << endl;
        }
    }

    // construct MST
    sort(edges.begin(), edges.end(), [](const auto& l, const auto& r) {
            return l[2] < r[2];
            });

    if (debug) {
        cout << "Sorted Edges: \n";
        for (auto t : edges) {
            for (auto v : t) {
                cout << v << " ";
            }
            cout << "\n";
        }
    }
    set<int> used;
    int mstcost = 0;
    for(const auto& edge: edges){
        int n1 = edge[0], n2 = edge[1], cost = edge[2];
        // early exit for when tree is populated
        if (used.size() == cats) {
            break;
        }

        // one node not in MST
        if (!used.count(n1) || !used.count(n2)) {
            mstcost += cost;
            used.insert(n1);
            used.insert(n2);
        }
    }

    int neededmilk = mstcost + cats; // drip 1 ml every unit of tree, + feed each cat 1 
    if (debug) cout << neededmilk << "\n";
    if (neededmilk <= milk) {
        cout << "yes\n";
    }
    else {
        cout << "no\n";
    }
}

int main() {
    int ct;
    cin >> ct;
    for (; ct > 0; --ct) {
        tc();
    }
    return 0;
}

