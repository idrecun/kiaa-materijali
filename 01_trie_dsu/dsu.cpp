#include <iostream>
#include <vector>

using namespace std;

vector<int> roditelj;
vector<int> rang;

void napravi_dsu(int n) {
	roditelj.resize(n);
	rang.resize(n, 1);
	for(int i = 0; i < n; i++)
		roditelj[i] = i;
}

int predstavnik(int a) {
	int t = a;
	// odredjujemo predstavnika
	while(roditelj[t] != t)
		t = roditelj[t];

	// sve cvorove na putu vezujedmo direktno ka predstavniku
	// (opciona optimizacija, dovoljno je i bez ovoga)
	while(a != t) {
		int tmp = roditelj[a];
		roditelj[a] = t;
		a = tmp;
	}
	return a;
}

void unija(int a, int b) {
	a = predstavnik(a);
	b = predstavnik(b);
	if(a == b)
		return;
	if(rang[a] < rang[b]) {
		roditelj[a] = b;
		rang[b] += rang[a];
	}
	else {
		roditelj[b] = a;
		rang[a] += rang[b];
	}
}

int main() {
	int n, a, b;
	cin >> n;

	napravi_dsu(n);

	while(true) {
		string operacija;
		cin >> operacija;
		if(operacija == "unija") {
			cin >> a >> b;
			unija(a, b);
		}
		else if(operacija == "predstavnik") {
			cin >> a;
			cout << predstavnik(a) << '\n';
		}
	}

	return 0;
}
