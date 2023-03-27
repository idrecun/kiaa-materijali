#include <iostream>
#include <vector>

using namespace std;

// boja = 0 - nije obidjen
// boja = 1 - crn
// boja = 2 - plav
// suprotna boja = 3 - boja
bool dfs(int v, int boja, vector<int>& boje, vector< vector<int> >& graf) {
	boje[v] = boja;
	for(int u : graf[v])
		if(boje[u] == 0) {
			if(!dfs(u, 3 - boja, boje, graf))
				return false;
		}
		else if(boje[u] == boje[v])
			return false;
	return true;
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





