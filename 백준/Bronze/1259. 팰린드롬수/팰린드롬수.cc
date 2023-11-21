#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;



int main() {

	fastio;

	while (true) {
		string a;
		cin >> a;

		if (a == "0") break;

		bool tk = true;
		for (int i = 0; i < a.size() / 2; ++i) {
			if (a[i] != a[a.size() - 1 - i]) {
				tk = false;
				break;
			}
		}

		if (tk) cout << "yes" << "\n";
		else cout << "no" << "\n";

	}

	return EXIT_SUCCESS;
}