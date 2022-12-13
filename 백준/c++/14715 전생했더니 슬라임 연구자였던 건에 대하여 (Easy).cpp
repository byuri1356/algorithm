#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int main() {
	fastio;

	int64 T, _count = 0, Ans = 0;
	cin >> T;
	for (int64 i = 2; i <= T;) {
		if (T % i) {
			++i;
			continue;
		}
		else {
			_count++;
			T /= i;
		}
	}
	while (_count != 1) {
		if (_count % 2)
			_count++;
		_count /= 2;
		Ans++;
	}
	cout << Ans;
	return EXIT_SUCCESS;
}