#include <iostream>
#include <vector>

using namespace std;

vector<int> topolosko(vector< vector<int> >& graf) {
	int n = graf.size();

	vector<int> indeg(n);
	for(int u = 0; u < n; u++)
		for(int v : graf[u])
			indeg[v]++;

	vector<int> q;
	for(int u = 0; u < n; u++)
		if(indeg[u] == 0)
			q.push_back(u);

	for(int i = 0; i < q.size(); i++) {
		int u = q[i];
		for(int v : graf[u]) {
			indeg[v]--;
			if(indeg[v] == 0)
				q.push_back(v);
		}
	}

	return q;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector< vector<int> > graf(n);
	while(m--) {
		int a, b; // a -> b
		cin >> a >> b;
		graf[a].push_back(b);
	}

	vector<int> top = topolosko(graf);
	if(top.size() < n) {
		cout << "ciklus" << '\n';
	}
	else {
		for(int u : top)
			cout << u << ' ';
		cout << '\n';
	}
}
