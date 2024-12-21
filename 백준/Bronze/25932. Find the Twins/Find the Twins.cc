#include <iostream>
using namespace std;

int arr[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		bool mack = 0, zack = 0;
		for (int i = 0; i < 10; i++) {
			int& x = arr[i]; cin >> x;
			if (x == 18) mack = 1;
			else if (x == 17) zack = 1;
		}

		for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
		cout << '\n';
		if (mack && zack) cout << "both\n\n";
		else if (mack) cout << "mack\n\n";
		else if (zack) cout << "zack\n\n";
		else cout << "none\n\n";
	}
}