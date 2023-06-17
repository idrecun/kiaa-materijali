#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct grana {
	int sused;
	int duzina;
};

int addinf(int x, int y) {
	if(x == numeric_limits<int>::max() ||
	   y == numeric_limits<int>::max())
	  return numeric_limits<int>::max();

	return x + y;
}

vector<int> bellman_ford(int u, vector< vector<grana> >& graf) {
	int n = graf.size();
	vector<int> d(n, numeric_limits<int>::max());
	d[u] = 0;

	for(int i = 0; i < n - 1; i++)
		for(int v = 0; v < n; v++)
			if(d[v] < numeric_limits<int>::max())
				for(grana g : graf[v])
					d[g.sused] = min(d[g.sused], addinf(d[v], g.duzina));

	return d;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector< vector<grana> > graf(n);
	for(int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graf[a].push_back({b, c});
	}

	vector< vector<int> > D = floyd_warshall(graf);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << D[i][j] << ' ';
		cout << '\n';
	}
}
