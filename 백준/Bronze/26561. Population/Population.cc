#include <iostream>
using namespace std;
typedef long long ll;

int T;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--) {
		ll p, t; cin >> p >> t;
		cout << p + (t / 4) - (t / 7) << '\n';
	}
}