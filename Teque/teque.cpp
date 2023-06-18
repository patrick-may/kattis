#include <bits/stdc++.h>

using namespace std;

typedef struct teque {
    deque<int> h1, h2;

    void pf(int a) {
        h1.push_front(a);
        if (h1.size() > h2.size()) {
            h2.push_front(h1.back());
            h1.pop_back();
        }
    }
    void pb(int a) {
        h2.push_back(a);
        if (h2.size() > h1.size()) {
            h1.push_back(h2.front());
            h2.pop_back();
        }
    }
    void pm(int a) {
        if (h1.size() <= h2.size()) {
            h1.push_back(a);
        }
        else {
            h2.push_front(a);
        }
        /*h2.push_front(a);
        while (h2.size() > h1.size()) {
            h1.push_back(h2.front());
            h2.pop_front();
        }*/
    }
    int get(int idx) {
        if (idx < h1.size()) {
            return h1[idx];
        }
        return h2[idx - h1.size()];
    }

    void print() {
        for (int i = 0; i < h1.size() + h2.size(); ++i){
            cout << i << " ";
        }
        cout << "\n";
        for (int i: h1) {
            cout << i << " ";
        }
        cout << "  ";
        for (int i: h2) {
            cout << i << " ";
        }
        cout << "\n";
    }
} teque;

int main() {
    int comms;
    cin >> comms;
    teque myteck;
    for(; comms > 0; --comms) {
        string ins;
        int num;
        cin >> ins >> num;

        myteck.print();
        if (ins == "push_back") {
            myteck.pb(num);
        }
        else if (ins == "push_front") {
            myteck.pf(num);
        }
        else if (ins == "push_middle") {
            myteck.pm(num);
        }
        else if (ins == "get") {
            cout << myteck.get(num) << "\n";
        }    
    }

    return 0;
}