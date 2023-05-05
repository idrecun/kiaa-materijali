#include <iostream>

using namespace std;

// Vraća broj iz [0, m)
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

int main() {
	int a = 10, c = 6, m = 19;
	int seed = 1;

	int x = seed;
	do {
		x = add(mul(a, x, m), c, m);
		cout << x << ' ';
	} while(x != 1);
	cout << '\n';

	return 0;
}
