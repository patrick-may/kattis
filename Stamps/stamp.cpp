#include <vector>
#include <set>
#include <iostream>

using namespace std;

bool debug = false;
int main() {
    int s, q;
    cin >> s >> q;

    vector<int> stamps(s);
    for (int i = 0; i < s; ++i) {
        cin >> stamps[i];
    }

    vector<int> pre(s), post(s);

    set<int> combs;
    combs.insert(0);
    for (int i = 0; i < s; ++i) {
        pre[i] = stamps[i] + (i > 0 ? pre[i - 1] : 0);
        combs.insert(pre[i]);
    }
    for (int i = s - 1; i >= 0; --i) {
        post[i] = stamps[i] + (i < s - 1 ? post[i + 1] : 0);
        combs.insert(post[i]);
    }

    if (debug){
        for (auto s: pre) {
            cout << s << " ";
        }
        cout << "\n";
        for (auto s : post) {
            cout << s << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < s; ++i) {
        if (debug) cout << pre[i] << "\n";
        for (int j = i + 1; j < s; ++j) {
            if (debug) cout << "\t" << post[j] << "\n";
            combs.insert(pre[i] + post[j]);
        }
    }
    
    if (debug) {
        for (auto v : combs) {
            cout << v << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < q; ++i) {
        int query;
        cin >> query;
        cout << (combs.count(query) ? "Yes" : "No") << "\n";
    } 

    return 0;
}
