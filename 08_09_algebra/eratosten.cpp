#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<bool> p(n + 1);
	p[1] = true;
	for(int d = 2; d * d <= n; d++)
		if(!p[d])
			for(int i = d * d; i <= n; i += d)
				p[i] = true;

	for(int d = 2; d <= n; d++)
		if(!p[d])
			cout << d << ' ';
	cout << '\n';

	return 0;
}
