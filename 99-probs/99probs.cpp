#include <bits/stdc++.h>

using namespace std;

void removeAbove(vector<long long int>& diffs, long long int d) {
    // get first element strictly larger than d
    cout << "manual binary search\n";
    int left = 0;
    int right = diffs.size() - 1;
    long long int mid = left + (right - left) / 2;

    while (left < right) {
        if (diffs[mid] > d) {
            left = mid + 1;
        } else if (diffs[mid] < d) {
            right = mid - 1;
        } else {
            break;
        }
    }
    cout << "For target " << d << "Got index " << mid << "\n";
    auto stl = lower_bound(diffs.begin(), diffs.end(), d);
    cout << (stl != diffs.end() ? *stl : -1) << "\n";
    if (stl != diffs.end()) {
        int idx = stl - diffs.begin();
        diffs.erase(stl);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long int> diffs(n);
    for (int i = 0; i < n; ++i) {
        cin >> diffs[i];
    }
    for (; q > 0; --q) {
        int type;
        long long int query;
        cin >> type >> query;
        switch (type) {
            case 1:
                removeAbove(diffs, query);
                break;
            case 2:
                // removeAt(diffs, query);
                break;
        }
    }
    return 0;
}
