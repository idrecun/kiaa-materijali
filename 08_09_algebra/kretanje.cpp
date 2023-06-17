/*

Igrac se krece po matrici uzajamno prostih dimenzija n, m. Odrediti posle koliko koraka ce doci do (c, d) ako krene iz (a, b) i pomera se za vektor (1, -1) u svakom koraku. Ukoliko ispadne sa jednog kraja matrice, izbija na drugi kraj.

Resenje:
Posle x koraka se igrac nalazi na koordinatama (a + x, b - x). Trazimo:

a + x = c (mod n)
b - x = d (mod m)

odnosno

x = c - a (mod n)
x = b - d (mod m)
*/

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int mod(int a, int m) {
	return (m + a % m) % m;
}

int add(int a, int b, int m) {
	return mod(mod(a, m) + mod(b, m), m);
}

int sub(int a, int b, int m) {
	return mod(mod(a, m) - mod(b, m), m);
}

int mul(int a, int b, int m) {
	return mod(mod(a, m) * mod(b, m), m);
}

int euklid(int a, int b, int& x, int& y) {
	int r1 = a, r2 = b;
	int x1 = 1, y1 = 0;
	int x2 = 0, y2 = 1;

	while(r2 > 0) {
		int q = r1 / r2;
		tie(r1, r2) = make_pair(r2, r1 - q * r2);
		tie(x1, x2) = make_pair(x2, x1 - q * x2);
		tie(y1, y2) = make_pair(y2, y1 - q * y2);
	}

	x = x1;
	y = y1;
	return r1;
}

bool diofant(int a, int b, int c, int& x, int& y) {
	int d = euklid(abs(a), abs(b), x, y);
	if(c % d != 0)
		return false;
	if(a < 0)
		x *= -1;
	if(b < 0)
		y *= -1;
	x *= c / d;
	y *= c / d;
	return true;
}

int inverz(int a, int m) {
	int x, k;
	diofant(a, m, 1, x, k);
	return mod(x, m);
}

int kto(vector<int> as, vector<int> ns) {
	int N = 1;
	for(int n : ns)
		N *= n;

	int x = 0;
	for(int i = 0; i < as.size(); i++) {
		int Ni = N / ns[i];
		int m = inverz(Ni, ns[i]);
		int t = mul(as[i], mul(Ni, m, N), N);
		x = add(x, t, N);
	}

	return x;
}

int main() {
	int n, m, a, b, c, d;
	cin >> n >> m >> a >> b >> c >> d;

	cout << kto({mod(c - a, n), mod(b - d, m)}, {n, m}) << '\n';
	return 0;
}
