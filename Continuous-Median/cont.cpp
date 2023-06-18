#include <bits/stdc++.h>

using namespace std;

void tc(){
    int ct;
    cin >> ct;
    long long int soln = 0; 
    vector<int> nums;

    for(int i = 0; i < ct; ++i) {
        int temp;
        cin >> temp;
        auto insertidx = lower_bound(nums.begin(), nums.end(), temp);
        nums.insert(insertidx, temp);

        if (nums.size() % 2 == 0) {
            // odd
            int lmid = (nums.size() - 1) / 2;
            int rmid = lmid + 1;
            //cout << "odd, size is " << nums.size() << "indexes: " << lmid << " " << rmid << "\n";
            soln += ((nums[lmid] + nums[rmid]) / 2);
        }
        else {
            int mid = (nums.size() - 1) / 2;

            //cout << "even. size is " << nums.size() << " mid index is " << mid << "\n";
            soln += (nums[mid]);
        }
    }

    cout << soln << "\n";
}

int main(){
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; ++i) {
        tc();
    }

    return 0;
}