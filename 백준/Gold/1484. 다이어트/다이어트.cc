#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;



int main() {
	fastio;

	int64 S = 1, E = 1, G = 0, Cnt = 0;
	cin >> G;

	while (S * S - (S - 1) * (S - 1) <= G) {
		int64 Tmp = S * S - E * E;

		if (Tmp == G) {
			Cnt++;
			cout << S << "\n";
		}
		if (Tmp <= G) S++;
		else E++;
	}

	if (!Cnt) cout << -1;

	return EXIT_SUCCESS;
}