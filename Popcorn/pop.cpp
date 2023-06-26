#include <bits/stdc++.h>

using namespace std;

// not sure on this one yet
// its some recurrence relation
int main(){
unsigned long long int n, bags = 0;
	cin >> n;
	// now there are 4 winners, no matter what
	long long int groups = n / 4;
	bags += 2 * (groups *(groups - 1));
	bags += 4;

	cout << bags << "\n";
}
