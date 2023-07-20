// so basically, dynamic programming
// have to weigh cost of taking full run vs cost of unlocking half run
// super ugly brutish approach at heart though...?

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	vector<pair<int,int>> runs;
	for (; n > 0; --n) {
		int run;
		cin >> run;
		runs.push_back(pair<int,int>(run, run/2));
	}

	for (auto p: runs){
		cout << p.first << " " << p.second << "\n";
	}
	
	return 0;
}
