#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

inline int64 gdc(int64 p1, int64 p2) {
	int64 p3;
	while (p1 % p2) {
		p3 = p1 % p2;
		p1 = p2;
		p2 = p3;
	}
	return p2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 p1, p2, p3, x1, x2, x3;
	cin >> p1 >> p2 >> p3 >> x1 >> x2 >> x3;
	if (!((x2 - x1) % gdc(p2, p1)) && !((x3 - x2) % gdc(p3, p2)) && !((x1 - x3) % gdc(p1, p3))) {
		for (int64 i = 1; i <= 1'000'000'000;) {
			if (((i - x1) % p1) == 0 && ((i - x2) % p2) == 0 && ((i - x3) % p3) == 0) {
				cout << i;
				break;
			}
			++i;
		}
	}
	else {
		cout << -1;
	}
	

	return EXIT_SUCCESS;
}