#include <iostream>
#include <tuple>

using namespace std;

// r0 = a
// r1 = b
int64_t euklid(int64_t a, int64_t b, int64_t& x, int64_t& y) {
	x = 1; y = 0;
	int64_t xb = 0, yb = 1;
	while(b > 0) {
		int64_t q = a / b;
		tie(a, b)  = make_tuple(b,  a - q * b);
		tie(x, xb) = make_tuple(xb, x - q * xb);
		tie(y, yb) = make_tuple(yb, y - q * yb);
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while(n--) {
		int64_t a, b;
		cin >> a >> b;
		
		int64_t x, y;
		int64_t d = euklid(a, b, x, y);

		int64_t t1 = min(abs(a * x), abs(b * y));
		int64_t t2 = max(abs(a * x), abs(b * y));

		cout << d << ' ' << t1 << ' ' << t2 << '\n';
	}

	return 0;
}

