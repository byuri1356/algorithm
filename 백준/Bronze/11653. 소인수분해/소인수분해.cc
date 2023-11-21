#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

bool _visit[10'000'000] = { true,true, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int64 i = 2; i * i <= 10'000'000; ++i) {
		if (_visit[i]) continue;
		for (int64 j = 2; i * j <= 10'000'000; ++j) {
			_visit[i * j] = true;
		}
	}
	int64 T,t;
	cin >> T;
	for (int64 i = 2; i <= T; ++i) {
		if (_visit[i]) continue;
		for (int64 j = 1; pow(i, j) <= T; ++j) {
			t = pow(i, j);
			if (T % t == 0) {
				cout << i << "\n";
			}
		}
	}
	
	return EXIT_SUCCESS;
}