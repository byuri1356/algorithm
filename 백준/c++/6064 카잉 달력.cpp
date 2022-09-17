#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

vector<int64> v;

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

	int64 T, p1, p2, x1, x2, g, l;
	cin >> T;
	for (int64 j = 0; j < T;++j) {
		cin >> p1 >> p2 >> x1 >> x2;
		g = gdc(p2, p1);
		l = p2 * p1 / g;
		if (!((x2 - x1) % g)) {
			for (int64 i = x1; i <= l;) {
				if (((i - x1) % p1) == 0 && ((i - x2) % p2) == 0) {
					v.push_back(i);
					break;
				}
				i += p1;
			}
		}
		else {
			v.push_back(-1);
		}
	}
	for (auto _iter : v) {
		cout << _iter << "\n";
	}

	return EXIT_SUCCESS;
}