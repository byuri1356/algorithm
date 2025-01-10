#include <iostream>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		if (i % 77 == 0) cout << "Wiwat!\n";
		else if (i % 7 == 0) cout << "Hurra!\n";
		else if (i % 11 == 0) cout << "Super!\n";
		else cout << i << '\n';
	}
}