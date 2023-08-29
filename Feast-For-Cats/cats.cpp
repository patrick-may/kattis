#include <algorithm>
#include <vector>
#include <iostream>
#include <tuple>
#include <set>

using namespace std;

bool debugio = false;
bool debug = true;

void tc() {
    int milk, cats;
    cin >> milk >> cats;
    
    vector<vector<int>> dists(cats, vector<int>(cats));
    vector<tuple<int,int,int>> edges(cats * (cats - 1));

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
            // TIL about tuples. Love it
            return get<2>(l) < get<2>(r);
            });

    set<int> used;
    int mstcost = 0;
    for(const auto& edge: edges){
        int n1 = get<0>(edge), n2 = get<1>(edge), cost = get<2>(edge);
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

