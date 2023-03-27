#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<bool>& obidjen, vector< vector<int> >& graf) {
	obidjen[v] = true;
	for(int u : graf[v])
		if(!obidjen[u])
			dfs(u, obidjen, graf);
}

int main() {
	int n, m;
	cin >> n >> m;

	vector< vector<int> > graf(n);
	while(m--) {
		int a, b;
		cin >> a >> b;

		graf[a].push_back(b);
		graf[b].push_back(a);
	}

	int brojKomponenti = 0;
	vector<bool> obidjen(n);
	for(int v = 0; v < n; v++)
		if(!obidjen[v]) {
			dfs(v, obidjen, graf);
			brojKomponenti++;
		}

	cout << brojKomponenti << '\n';
	return 0;
}








