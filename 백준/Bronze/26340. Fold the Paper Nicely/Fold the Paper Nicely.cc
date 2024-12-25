#include <iostream>
#include <utility>
using namespace std;

int T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		int x, y, n; cin >> x >> y >> n;
		cout << "Data set: " << x << ' ' << y << ' ' << n << '\n';
		if (x < y) swap(x, y);
		while (n--) {
			x >>= 1;
			if (x < y) swap(x, y);
		}

		cout << x << ' ' << y << '\n' << '\n';
	}
}