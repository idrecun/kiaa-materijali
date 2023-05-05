#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> x(n);
	for(int i = 0; i < n; i++)
		cin >> x[i];

	int m = *max_element(begin(x), end(x));
	vector<int> d(m + 1); // d[i] - najveci prost delilac od i
	for(int p = 2; p <= m; p++)
		if(d[p] == 0)
			for(int i = p; i <= m; i += p)
				d[i] = p;

	vector<int> f;
	for(int a : x)
		while(a != 1) {
			f.push_back(d[a]);
			a /= d[a];
		}

	sort(begin(f), end(f));

	for(int a : f)
		cout << a << ' ';
	cout << '\n';

	return 0;
}











