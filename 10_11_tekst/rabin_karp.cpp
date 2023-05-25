#include <iostream>
#include <vector>
#include <string>

using namespace std;

int add(int a, int b, int M) {
	return ((int64_t)a + b) % M;
}

int sub(int a, int b, int M) {
	return ((int64_t)M + a - b) % M;
}

int mul(int a, int b, int M) {
	return ((int64_t)a * b) % M;
}

int num(char c) {
	return  (int)(c - 'a' + 1);
}

int hash_str(string s) {
	int p = 31, M = 1000000009;

	int h = 0;
	for(char c : s)
		h = add(mul(p, h, M), num(c), M);

	return h;
}

void search(string s, string t) {
	int p = 31, M = 1000000009;

	int n = s.size();
	int m = t.size();

	int sh = hash_str(s);
	int th = hash_str(t.substr(0, n));

	int pn = 1;
	for(int i = 0; i < n-1; i++)
		pn = mul(pn, p, M);

	if(sh == th)
		cout << 0 << ' ';

	for(int i = n; i < m; i++) {
		th = sub(th, mul(pn, num(t[i - n]), M), M);
		th = mul(th, p, M);
		th = add(th, num(t[i]), M);

		if(sh == th)
			cout << i - n + 1 << ' ';
	}
}

int main() {
	string s, t;
	cin >> s >> t;

	search(s, t);
	cout << '\n';

	return 0;
}
