#include <iostream>
#include <vector>

using namespace std;

int dfs(int v, vector<bool>& obidjen, vector< vector<int> >& graf) {
	obidjen[v] = true;
	int brojCvorova = 0;
	for(int u : graf[v])
		if(!obidjen[u])
			brojCvorova += dfs(u, brojCvorova, obidjen, graf);
	return brojCvorova + 1;
}

// velicina komponente cvora 0
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

	vector<bool> obidjen(n);
	cout << dfs(0, obidjen, graf) << '\n';

	return 0;
}








