#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct cvor {
	int vrednost = 0;
	int uvecanje = 0;
};

int velicina(int n) {
	return pow(2, ceil(log2(n)));
}

vector<cvor> napravi_stablo(vector<int>& niz, int n) {
	vector<cvor> stablo(2 * n);
	for(int i = 0; i < n; i++)
		stablo[n + i].vrednost = niz[i];
	for(int i = n - 1; i > 0; i--)
		stablo[i].vrednost = min(stablo[2 * i].vrednost, stablo[2 * i + 1].vrednost);
	return stablo;
}

void propagiraj(int i, int tl, int td, vector<cvor>& stablo) {
	stablo[i].vrednost += stablo[i].uvecanje;
	if(tl < td) { // ako nije list
		stablo[2 * i].uvecanje += stablo[i].uvecanje;
		stablo[2 * i + 1].uvecanje += stablo[i].uvecanje;
	}
	stablo[i].uvecanje = 0;
}

void uvecaj(int l, int d, int uvecanje, int idx, int tl, int td, vector<cvor>& stablo) {
	if(stablo[idx].uvecanje != 0)
		propagiraj(idx, tl, td, stablo);

	if(l > td || d < tl) return;

	if(tl >= l && td <= d) {
		stablo[idx].uvecanje += uvecanje;
		propagiraj(idx, tl, td, stablo);
	}
	else {
		int s = (tl + td) / 2;
		uvecaj(l, d, uvecanje, 2 * idx, tl, s, stablo);
		uvecaj(l, d, uvecanje, 2 * idx + 1, s + 1, td, stablo);
		stablo[idx].vrednost = min(stablo[2 * idx].vrednost, stablo[2 * idx + 1].vrednost);
	}
}

void uvecaj(int l, int d, int uvecanje, vector<cvor>& stablo, int n) {
	uvecaj(l, d, uvecanje, 1, 0, n - 1, stablo);
}

int upit(int l, int d, int idx, int tl, int td, vector<cvor>& stablo) {
	if(stablo[idx].uvecanje != 0)
		propagiraj(idx, tl, td, stablo);

	if(l > td || d < tl) return numeric_limits<int>::max();

	if(tl >= l && td <= d)
		return stablo[idx].vrednost;
	else {
		int s = (tl + td) / 2;
		int minL = upit(l, d, 2 * idx, tl, s, stablo);
		int minD = upit(l, d, 2 * idx + 1, s + 1, td, stablo);
		return min(minL, minD);
	}
}

int upit(int l, int d, vector<cvor>& stablo, int n) {
	return upit(l, d, 1, 0, n - 1, stablo);
}

int main() {

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	int sn = velicina(n);
	vector<cvor> stablo = napravi_stablo(a, sn);

	while(true) {
		string operacija;
		cin >> operacija;

		if(operacija == "uvecaj") {
			int l, d, u;
			cin >> l >> d >> u;
			uvecaj(l, d, u, stablo, sn);
		}
		else if(operacija == "upit") {
			int l, d;
			cin >> l >> d;
			cout << upit(l, d, stablo, sn) << '\n';
		}
	}

	return 0;
}
