#include <bits/stdc++.h>

using namespace std;

typedef struct disjoint_set {
    disjoint_set* parent;
    string friend_name;

    disjoint_set(string fname){
        parent = this;
        friend_name = fname;
    }

    disjoint_set* find_root(){
        if (parent == this){

        }
    }
    
} disjoint_set;