#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int v, vector< vector<int> >& graf) {
	vector<int> udaljenost(graf.size(), -1);
	queue<int> q;

	q.push(v);
	udaljenost[v] = 0;

	while(!q.empty()) {
		int t = q.front(); q.pop();

		for(int u : graf[t])
			if(udaljenost[u] == -1) {
				q.push(u);
				udaljenost[u] = udaljenost[t] + 1;
			}
	}

	return udaljenost;
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

	bfs(0, graf);

	return 0;
}





