#include<iostream>

using namespace std;

int T;

int main() {

	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int a, b; cin >> a >> b;
		cout << "Case " << t << ": " << a + b << "\n";
;	}

	return 0;
}