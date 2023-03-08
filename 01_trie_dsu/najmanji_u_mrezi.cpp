#include <iostream>
#include <vector>

using namespace std;

vector<int> roditelj;
vector<int> rang;
vector<int> najmanji;

void napravi_dsu(int n) {
	roditelj.resize(n);
	rang.resize(n, 1);
	najmanji.resize(n);
	for(int i = 0; i < n; i++) {
		roditelj[i] = i;
		najmanji[i] = i;
	}
}

int predstavnik(int a) {
	while(roditelj[a] != a)
		a = roditelj[a];
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
		najmanji[b] = min(najmanji[a], najmanji[b]);
	}
	else {
		roditelj[b] = a;
		rang[a] += rang[b];
		najmanji[a] = min(najmanji[a], najmanji[b]);
	}
}

int main() {
	int n, m, a, b;
	cin >> n >> m;

	napravi_dsu(n);

	while(m--) {
		string upit;
		cin >> upit;
		if(upit == "povezi") {
			cin >> a >> b;
			unija(a, b);
		}
		else if(upit == "najmanji") {
			cin >> a;
			cout << najmanji[predstavnik(a)] << '\n';
		}
	}

	return 0;
}
