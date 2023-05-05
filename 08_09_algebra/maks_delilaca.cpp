#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	int m = *max_element(begin(a), end(a));

	vector<int> d(m + 1);
	for(int i = 1; i <= m; i++)
		for(int j = i; j <= m; j += i)
			d[j]++;

	int maxd = 1;
	for(int x : a)
		if(d[x] > d[maxd])
			maxd = x;

	cout << maxd << ' ' << d[maxd] << '\n';

	return 0;
}
