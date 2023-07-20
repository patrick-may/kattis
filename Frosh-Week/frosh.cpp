#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int merge(vector<ll>& arr, int l, int m, int r) {
    int inversions = 0;
    while ((l <= mid - 1) && (mid <= r)) {
        if (arr[l] <=) }
}
int mergeSort(vector<ll>& arr, int l, int r) {
    int mid, inversions = 0;
    if (l >= r) {
        return 0;  // all done
    }

    mid = l + (r - l) / 2;
    inversions += mergeSort(arr, l, mid);
    inversions += mergeSort(arr, mid + 1, r);
    `` inversions += merge(arr, l, mid + 1, r);

    return inv_count;
}

int inversionCt(vector<ll>& arr) { mergeSort(arr, 0, arr.size() - 1); }

int main() {
    ll cases;
    cin >> cases;
    vector<ll> students(cases);
    for (ll i = 0; i <= cases; ++i) {
        cin >> students[i];
    }

    return 0;
}
