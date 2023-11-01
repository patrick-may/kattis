#include <iostream>
#include <vector>

using namespace std;

bool debug = false;
int main() {

    int n;
    cin >> n;

    if (n == 1) {
        int temp;
        cin >> temp;
        cout << "1 " << temp << endl;
        return 0;
    }

    vector<int>arr(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> leftmax(n), rightmin(n);
    leftmax[0] = arr[0];

    size_t last = n - 1;
    rightmin[last] = arr[last]; 
    for (int i = 1; i < n; ++i) {
        leftmax[i] = max(arr[i], leftmax[i - 1]);
    }
    for (int i = last - 1; i >= 0; --i) {
        rightmin[i] = min(arr[i], rightmin[i + 1]);
    }

    if (debug) {
        for (auto c : arr) {
            cout << c << "\t";
        }
        cout << endl;
        for (auto c : leftmax) {
            cout << c << "\t";
        }
        cout << endl; 
        for (auto c : rightmin) {
            cout << c << "\t";
        }
        cout << endl;       
    } 

    vector<int> pivots;
    int found = 0;
    // check left most
    if (arr[0] < rightmin[1]) {
        ++found;
        pivots.push_back(arr[0]);
    }
    for (int i = 1; i < n - 1; ++i) {
        if (leftmax[i - 1] <= arr[i] && arr[i] < rightmin[i + 1]){
            ++found;
            pivots.push_back(arr[i]);
        }
    }
    // check right most
    if (arr[last] >= leftmax[last - 1]) {
        ++found;
        pivots.push_back(arr[last]);
    }

    cout << found << " ";
    for(int i = 0; i < min(pivots.size(), size_t(100)); ++i) {
        cout << pivots[i] << " ";
    }
    cout << endl;
    return 0;
}
