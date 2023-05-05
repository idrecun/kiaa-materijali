#include <iostream>
#include <vector>

using namespace std;

// low link vrednost cvora u
int dfs(int u, int p, int& t, vector<int>& num,
		vector< vector<int> >& graf) {
	int low = num[u] = ++t;
	bool ap = false;
	int count = 0;

	for(int v : graf[u])
		if(num[v] == 0) {
			int v_low = dfs(v, u, t, num, graf);

			if(num[u] > 1 && num[u] <= v_low)
				ap = true;

			low = min(low, v_low);
			count++;
		}
		else if(v != p)
			low = min(low, num[v]);

	if(ap || (num[u] == 1 && count > 1))
		cout << u << ' ';

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
