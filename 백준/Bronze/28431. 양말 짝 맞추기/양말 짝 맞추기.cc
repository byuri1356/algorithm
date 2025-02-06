#include <iostream>
using namespace std;

int cnt[10];

int main() {

	for (int k = 0; k < 5; k++) {
		int x; cin >> x;
		cnt[x]++;
	}

	for (int i = 0; i < 10; i++) {
		if (cnt[i] & 1) cout << i;
	}
}