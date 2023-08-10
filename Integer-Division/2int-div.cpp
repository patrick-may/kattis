#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (){
	int n; ll div;
	cin >> n >> div;

	map<ll, ll> res;
	ll soln = 0;
	for(int i = 0; i < n; ++i) {
		ll temp;
		cin >> temp;
		soln += res[temp/div];
		++res[temp/div];
	}
	cout << soln << "\n";
	return 0;
	
}
