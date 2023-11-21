#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using int64 = int64_t;

int64 denum = 1, num = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T, t;
	int64 ans;
	cin >> T >> t;
	if ((T - t) >= t) {
		for (int64 i = T; i > (T - t);) {
			denum = ((denum % 1'000'000'007) * (i % 1'000'000'007)) % 1'000'000'007;
			--i;
		}
		for (int64 i = 1; i <= t;) {
			num = ((num % 1'000'000'007) * (i % 1'000'000'007)) % 1'000'000'007;
			++i;
		}
	}
	else {
		for (int64 i = T; i > t;) {
			denum = ((denum % 1'000'000'007) * (i % 1'000'000'007)) % 1'000'000'007;
			--i;
		}
		for (int64 i = 1; i <= (T - t);) {
			num = ((num % 1'000'000'007) * (i % 1'000'000'007)) % 1'000'000'007;
			++i;
		}
	}
	//cout << denum<<"\n";
	//cout << num << "\n";
	cout << (denum / num) % 1'000'000'007;
	return EXIT_SUCCESS;
}