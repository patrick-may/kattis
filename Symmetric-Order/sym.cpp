#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int main(){
	int names = 1;
	int c = 1;

	while (cin >> names){
		if (names == 0){
			break;
		}
		vector<string> n1;
		vector<string> n2;
		for (int i = 0; i < names; ++i){
			string n;
			cin >> n;
			if (! (i % 2)){
				n1.pb(n);
			}
			else{
				n2.pb(n);
			}
		}
		cout << "SET " << c << "\n";
		for (auto i: n1){
			cout << i <<"\n";
		}
		for (auto i = n2.rbegin(); i != n2.rend(); ++i){
			cout << *i << "\n";
		}
		++c;
	}

	return 0;
}
