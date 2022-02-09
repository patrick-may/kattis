#include <bits/stdc++.h>

using namespace std;

int main() {
    int trees, people;
    // Reading input
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

    //p_loc is a vector of all locations of people,
    //t_loc is a vector of all tree locations
    sort(p_loc.begin(), p_loc.end());
    sort(t_loc.begin(), t_loc.end());
    
    //counter for how many people do not get a tree
    int none = 0;
    
    //iterate through every tree, assigning it a person
    for(int x = 0; x < trees; ++x) {
        //people will always go for either tree on "left" or tree on "right"
        int t_loc_one = t_loc[x];
        int t_loc_two = t_loc[x+1];
        int tree_attacker = 0;

       //find how many people are going for first tree (tree 1)
        for(int y = 0; y < p_loc.size(); ++y) {
            int person_loc = p_loc[y];
            int r_dist, l_dist;
            l_dist = abs(person_loc - t_loc_one);
            r_dist = abs(person_loc - t_loc_two);
            
            
            if(l_dist <= r_dist && person_loc != -1){
                tree_attacker++;
                
                p_loc[y] = -1;
                
            }
            
        }
        //if more than 1 person is going for the tree, then everyone except 1 person is left without a tree
        if(tree_attacker > 1){
            none += tree_attacker-1;
        }
        
    }
    
    cout << none << endl;
    return 0;
}
