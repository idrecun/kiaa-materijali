#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<bool>& obidjen, vector< vector<int> >& graf) {
	obidjen[v] = true;
	cout << v << '\n';
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

	vector<bool> obidjen(n);
	dfs(0, obidjen, graf);

	return 0;
}
