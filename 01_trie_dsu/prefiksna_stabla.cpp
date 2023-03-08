#include <iostream>
#include <map>

using namespace std;

struct Cvor {
	bool kraj_reci;
	map<char, Cvor*> prelaz;
};

void dodaj(Cvor* koren, string& s) {
	for(char c : s) {
		if(koren->prelaz.find(c) == koren->prelaz.end())
			koren->prelaz[c] = new Cvor();
		koren = koren->prelaz[c];
	}
	koren->kraj_reci = true;
}

bool nadji(Cvor* koren, string& s) {
	for(char c : s) {
		if(koren->prelaz.find(c) == koren->prelaz.end())
			return false;
		koren = koren->prelaz[c];
	}
	return koren->kraj_reci;
}

void oslobodi(Cvor* koren) {
	// {'c', Cvor*}
	for(auto podstablo : koren->prelaz)
		oslobodi(podstablo.second);
	delete koren;
}

string nzp(Cvor* koren) {
	string prefiks = "";
	while(koren->prelaz.size() == 1 && !koren->kraj_reci) {
		auto it = koren->prelaz.begin();

		prefiks += it->first;
		koren = it->second;
	}
	return prefiks;
}

void ispisi(Cvor* koren, string& rec) {
	if(koren->kraj_reci)
		cout << rec << '\n';
	for(auto podstablo : koren->prelaz) {
		rec.push_back(podstablo.first);
		ispisi(podstablo.second, rec);
		rec.pop_back();
	}
}

int main() {
	Cvor* stablo = new Cvor();
	string komanda, argument;
	while(true) {
		cin >> komanda >> argument;
		if(komanda == "dodaj")
			dodaj(stablo, argument);
		else if(komanda == "nadji")
			cout << nadji(stablo, argument) << '\n';
		else if(komanda == "prefiks")
			cout << nzp(stablo) << '\n';
		else if(komanda == "ispis")
			ispisi(stablo, "");
		else
			break;
	}
	oslobodi(stablo);
	return 0;
}
