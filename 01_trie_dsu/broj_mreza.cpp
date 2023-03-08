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
	while(roditelj[a] != a)
		a = roditelj[a];
	return a;
}

// vraca da li je izvrseno spajanje
bool unija(int a, int b) {
	a = predstavnik(a);
	b = predstavnik(b);
	if(a == b)
		return false;
	if(rang[a] < rang[b]) {
		roditelj[a] = b;
		rang[b] += rang[a];
	}
	else {
		roditelj[b] = a;
		rang[a] += rang[b];
	}
	return true;
}

int main() {
	int n, m, a, b;
	cin >> n >> m;

	napravi_dsu(n);

	int brojMreza = n;
	while(m--) {
		cin >> a >> b;
		if(unija(a, b))
			brojMreza--;
		cout << brojMreza << '\n';
	}

	return 0;
}
