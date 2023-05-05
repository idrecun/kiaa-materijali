#include <iostream>
#include <vector>

using namespace std;

int main() {
	uint64_t n;
	cin >> n;

	uint64_t r = 1;
	for(uint64_t p = 2; p * p <= n; p++) {
		int st = 0;
		while(n % p == 0) {
			n /= p;
			st++;
		}
		if(st % 2 == 1)
			r *= p;
	}

	r *= n;

	cout << r << '\n';
	return 0;
}
