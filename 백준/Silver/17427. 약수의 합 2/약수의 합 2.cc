#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 N, ans = 0;
	cin >> N;
	for (int64 i = N; i >= 1;) {
		ans += (N / i) * i;
		--i;
	}
	cout << ans;
	return EXIT_SUCCESS;
}