#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multi_precision;
using namespace std;

// not sure on this one yet
// its some recurrence relation
int main(){
	cpp_int n;
	cpp_int bags = 0;
	cin >> n;
	// now there are 4 winners, no matter what
	cpp_int groups = n / 4;
	bags += 2 * (groups *(groups - 1));
	bags += 4;

	cout << int(bags) << "\n";
}
