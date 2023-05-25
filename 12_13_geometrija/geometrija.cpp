#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using point = pair<int, int>;

point vec(point a, point b) {
	return {b.first - a.first, b.second - a.second};
}

int dot(point u, point v) {
	return u.first * v.first + u.second * v.second;
}

int cross(point u, point v) {
	return u.first * v.second - u.second * v.first;
}

int orient(point a, point b, point c) {
	return cross(vec(a, b), vec(a, c));
}

bool colinear(point a, point b, point c) {
	return orient(a, b, c) == 0;
}

// proverava da li je tacka u trouglu ili na stranici trougla
bool inTriangle(point a, point b, point c, point x) {
	if(orient(a, b, x) >= 0 && orient(b, c, x) >= 0 && orient(c, a, x) >= 0)
		return true;
	if(orient(a, b, x) <= 0 && orient(b, c, x) <= 0 && orient(c, a, x) <= 0)
		return true;
	return false;
}

// proverava konveksnost mnogougla
bool checkConvex(vector<point>& p) {
	bool pos = false, neg = false;
	for(int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		int k = (i + 2) % p.size();
		if(orient(p[i], p[j], p[k]) > 0)
			pos = true;
		if(orient(p[i], p[j], p[k]) < 0)
			neg = true;
	}
	return !(pos && neg);
}

// pretpostavka je da nema trojki kolinearnih tacaka
vector<point> makeSimple(vector<point> pts) {
	vector<point> p = pts;
	swap(p[0], *min_element(begin(p), end(p)));
	sort(begin(p) + 1, end(p),
			[&](point a, point b) {
				return orient(p[0], a, b) > 0;
			});
	return p;
}

// pretpostavka je da nema trojki kolinearnih tacaka
vector<int> jarvisHull(vector<point>& p) {
	vector<int> hull;

	int t = min_element(begin(p), end(p)) - begin(p);
	do {
		hull.push_back(t);
		int nt = (t + 1) % p.size(); // treba uzeti bilo koju tacku razlicitu od t
		for(int i = 0; i < p.size(); i++)
			if(orient(p[t], p[i], p[nt]) > 0)
				nt = i;
		t = nt;
	} while(t != hull[0]);

	return hull;
}

// pretpostavka je da nema trojki kolinearnih tacaka
vector<int> grahamHull(vector<point>& p) {
	swap(p[0], *min_element(begin(p), end(p)));
	sort(begin(p) + 1, end(p),
			[&](point a, point b) {
				return orient(p[0], a, b) > 0;
			});

	vector<int> hull = {0};
	for(int i = 1; i < p.size(); i++) {
		while(hull.size() > 1 &&
					orient(p[hull[hull.size() - 2]],
					       p[hull[hull.size() - 1]],
								 p[i]) < 0)
			hull.pop_back();

		hull.push_back(i);
	}

	return hull;
}

// pretpostavka je da su tacke konveksnog mnogougla p
// orijentisane u pozitivnom matematickom smeru
bool inConvex(point t, vector<point>& p) {
	auto it = lower_bound(begin(p) + 1, end(p), t,
	                      [&](point a, point b) {
													return orient(p[0], a, b) > 0;
												});
	if(it == end(p))
		return false;
	int i = it - begin(p);
	return inTriangle(p[0], p[i - 1], p[i], t);
}

float orientedArea(point a, point b, point c) {
	return orient(a, b, c) * 0.5f;
}

// radi za bilo koji prost mnogougao
float orientedArea(vector<point>& p) {
	float a = 0;
	for(int i = 2; i < p.size(); i++)
		a += orientedArea(p[0], p[i - 1], p[i]);
	return a;
}

int main() {
	return 0;
}
