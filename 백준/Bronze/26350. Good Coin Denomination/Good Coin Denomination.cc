#include <iostream>
using namespace std;

int T, N;
int arr[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> arr[i];
		bool chk = 1;
		for (int i = 1; i < N; i++) {
			if (arr[i] < arr[i-1] * 2) chk = 0;
		}

		cout << "Denominations: ";
		for (int i = 0; i < N; i++) cout << arr[i] << ' ';
		cout << '\n';
		if (chk) cout << "Good ";
		else cout << "Bad ";
		cout << "coin denominations!\n\n";
	}
}