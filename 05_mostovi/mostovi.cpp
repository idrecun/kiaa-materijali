#include <iostream>
#include <vector>

using namespace std;

// low link vrednost cvora u
int dfs(int u, int p, int& t, vector<int>& num,
		vector< vector<int> >& graf) {
	int low = num[u] = ++t;

	for(int v : graf[u])
		if(num[v] == 0) {
			int v_low = dfs(v, u, t, num, graf);

			if(num[u] < v_low)
				cout << u << ' ' << v << '\n';

			low = min(low, v_low);
		}
		else if(v != p)
			low = min(low, num[v]);

	return low;
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

	int t = 0;
	vector<int> num(n, 0);
	dfs(0, 0, t, num, graf);

	return 0;
}
