//
// Created by pmayn on 9/3/2021.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int num_unis; int counter = 0;
    cin >> num_unis;
    string unis = " ";
    string team = "";
    string uni_name;

    for(int x = 0; x <= num_unis; ++x) {
        getline(cin,team);
        uni_name = team.substr(0, team.find(" "));
        if(unis.find(uni_name) == string::npos && counter < 12) {
            cout << team << endl;
            unis = unis + " " + uni_name;
            ++counter;
        }
    }
    return 0;
}

