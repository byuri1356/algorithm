#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

int64 arr[1'000'001] = { 1, 1,};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 ans = 0;

	for (int64 i = 2; i*i < 1000001;) {
		if (arr[i]) {
			++i;
			continue;
		}
		for (int64 j = 2; i*j < 1000001;) {
			arr[i * j] = 1;
			++j;
		}
		++i;
	}

	int64 T;
	for (;;) {
		cin >> T;
		if (T == 0) break;
		for (int64 i=T-1; i>=(T/2);) {
			ans = 0;
			if (!arr[i]) {
				if (!arr[T - i]) {
					ans = T - i;
					break;
				}
				else {
					--i;
					continue;
				}
			}
			--i;
		}
		if (ans) {
			cout << T << " = " << ans << " + " << T - ans << "\n";
		}
	}

	return EXIT_SUCCESS;
}