#include<iostream>
#include<string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	bool tk = false;
	for (int i = 0; i < 8; i++) {
		int a; cin >> a;

		if (a == 9) tk = true;
	}

	if (tk) cout << "F\n";
	else cout << "S\n";
	
}