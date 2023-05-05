#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

struct grana {
	int sused;
	int duzina;
};

vector<int> dijkstra(int u, vector< vector<grana> >& graf) {
	vector<int> d(graf.size(), numeric_limits<int>::max());
	d[u] = 0;

	set< pair<int, int> > red; // (udaljenost, cvor)
	red.insert({0, u});

	while(!red.empty()) {
		int v = red.begin()->second;
		red.erase(red.begin());

		for(grana g : graf[v]) {
			if(d[v] + g.duzina < d[g.sused]) {
				red.erase({d[g.sused], g.sused});
				d[g.sused] = d[v] + g.duzina;
				red.insert({d[g.sused], g.sused});
			}
		}
	}

	return d;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector< vector<grana> > graf(n);
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		graf[a].push_back({b, c});
		graf[b].push_back({a, c});
	}

	vector<int> d = dijkstra(0, graf);
	for(auto x : d)
		cout << x << ' ';
	cout << '\n';

	return 0;
}
