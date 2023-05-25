#include <iostream>
#include <vector>

using namespace std;

vector<int> zNiz(string s) {
	int n = s.size();
	vector<int> z(n);

	int l = 0, d = 0;
	for(int i = 1; i < n; i++) {
		if(i <= d)
			z[i] = min(z[i - l], d - i + 1);
		
		while(i + z[i] < n && s[i + z[i]] == s[z[i]])
			z[i]++;

		if(i + z[i] - 1 > d) {
			l = i;
			d = i + z[i] - 1;
		}
	}

	return z;
}

int main() {
	string s, t;
	cin >> s >> t;

	string p = s + "#" + t;
	vector<int> z = zNiz(p);

	for(int i = s.size() + 1; i < p.size(); i++)
		if(z[i] == s.size())
			cout << i - (s.size() + 1) << '\n';

	return 0;
}
