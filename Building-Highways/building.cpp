#include <bits/stdc++.h>

using namespace std;
 
 // hacky MST. trivial!
int main() {
    int cities;
    cin >> cities;
    vector<pair<int,int>> probs;
    for(int i = 0; i < cities; ++i){
        int p;
        cin >> p;
        pair<int, int> temp{p, i};
        probs.push_back(temp);    
    }

    sort(probs.begin(), probs.end());
    
    long long int soln = 0; // hehe
    int edges = 0;
    set<int> visited;

    for(int i = 0; i < probs.size(); ++i) {
        int p1 = probs[i].first;
        int city1 = probs[i].second;

        for (int j = i + 1; j < probs.size(); ++j) {
            int p2 = probs[j].first;
            int city2 = probs[j].second;
            // skip, would make cycle
            if (visited.count(city1) && visited.count(city2)) {
                continue;
            }

            if (cities == edges + 1) {
                break;
            }
            // add sum to soln;
            soln += (p1 + p2);
            edges += 1;
            visited.insert(city1);
            visited.insert(city2);
        }

        if (cities == edges + 1) {
            break;
        }
    } 

    cout << soln;
    return 0;
} 