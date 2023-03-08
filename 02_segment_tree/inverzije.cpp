#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int velicina(int n) {
	return pow(2, ceil(log2(n)));
}

vector<int> napravi_stablo(vector<int>& niz, int n) {
	vector<int> stablo(2 * n);
	copy(begin(niz), end(niz), begin(stablo) + n);

	for(int k = n - 1; k > 0; k--)
		stablo[k] = stablo[2 * k] + stablo[2 * k + 1];

	return stablo;
}

void postavi(int i, int x, vector<int>& stablo, int n) {
	stablo[i += n] = x;
	for(i /= 2; i > 0; i /= 2)
		stablo[i] = stablo[2 * i] + stablo[2 * i + 1];
}

int upit(int l, int d, vector<int>& stablo, int n) {
	int zbir = 0;
	for(l += n, d += n; l <= d; l /= 2, d /= 2) {
		if(l % 2 == 1) zbir += stablo[l++];
		if(d % 2 == 0) zbir += stablo[d--];
	}
	return zbir;
}

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];

	int najveci = *max_element(begin(v), end(v));
	int sn = velicina(najveci + 1);
	vector<int> stablo(2 * sn);

	int brojInverzija = 0;
	for(int i = 0; i < n; i++) {
		brojInverzija += upit(v[i] + 1, najveci, stablo, sn);
		postavi(v[i], 1, stablo, sn);
	}
	cout << brojInverzija << '\n';

	return 0;
}
