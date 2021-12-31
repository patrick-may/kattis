#include <bits/stdc++.h>

using namespace std;

int main() {
    int trees, people;

    cin >> people >> trees;
    vector<int> p_loc;
    vector<int> t_loc;

    for(int x = 0; x< people; ++x) {
        int temp;
        cin >> temp;
        p_loc.push_back(temp);

    }
     for(int x = 0; x < trees; ++x) {
        int temp;
        cin >> temp;
        t_loc.push_back(temp);
    }

    sort(p_loc.begin(), p_loc.end());
    sort(t_loc.begin(), t_loc.end());
    
    int none = 0;
    
    for(int x = 0; x < trees; ++x) {
        
        int t_loc_one = t_loc[x];
        int t_loc_two = t_loc[x+1];
        int tree_attacker = 0;

       // cout << "LEFT TREE: " << t_loc_one << endl;
        //cout << "RIGHT TREE: " << t_loc_two << endl;

        for(int y = 0; y < p_loc.size(); ++y) {
            int person_loc = p_loc[y];
            int r_dist, l_dist;
            l_dist = abs(person_loc - t_loc_one);
            r_dist = abs(person_loc - t_loc_two);
            //cout << "person " << y << "location " << person_loc << endl;
            //cout << "left tree dist: " << l_dist << endl;
            //cout << "right tree_dist: " << r_dist << endl;
            if(l_dist <= r_dist && person_loc != -1){
                tree_attacker++;
                //cout << "someone going for tree " << x << endl;
                p_loc[y] = -1;
                
            }
            
        }
        
        if(tree_attacker > 1){
            none += tree_attacker-1;
        }
        
    }
    
    cout << none << endl;
    return 0;
}