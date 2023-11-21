#include<iostream>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

const int MOD = 1e9 + 7;
int64 n = 1, k = 1;

inline int64 split(int64 pivot, int power) {
	if (power == 1) return pivot;

	if (power % 2) return pivot * split((pivot * pivot) % MOD , power / 2) % MOD;
	
	else return split((pivot * pivot) % MOD, power / 2) % MOD;
}

int main() {

	fastio;

	int N, K;
	cin >> N >> K;

	for (int i = N; i >= N - K + 1; --i) {
		n = (n * i) % MOD;
	}

	for (int i = K; i >= 1; --i) {
		k = (k * i) % MOD;
	}

	cout << (n * split(k, MOD - 2)) % MOD;

	return EXIT_SUCCESS;
}
