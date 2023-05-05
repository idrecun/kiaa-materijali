#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

struct grana {
	int sused;
	int tezina;
};

vector<grana> prim(vector< vector<grana> >& graf) {
	vector<bool> dodat(graf.size());
	vector<grana> stablo(graf.size(), {-1, numeric_limits<int>::max()});
	set< pair<int, int> > red; // (tezina, cvor)

	red.insert({0, 0});
	while(!red.empty()) {
		int v = red.begin()->second;
		red.erase(red.begin());
		dodat[v] = true;

		for(auto g : graf[v]) {
			if(!dodat[g.sused] && g.tezina < stablo[g.sused].tezina) {
				red.erase({stablo[g.sused].tezina, g.sused});
				stablo[g.sused] = {v, g.tezina};
				red.insert({stablo[g.sused].tezina, g.sused});
			}
		}
	}
	return stablo;
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

	vector<grana> stablo = prim(graf);

	int mst = 0;
	for(grana g : stablo)
		if(g.sused != -1)
			mst += g.tezina;

	cout << mst << '\n';
	return 0;
}
