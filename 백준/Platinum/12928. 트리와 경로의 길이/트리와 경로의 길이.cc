#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;



int main() {

	fastio;

	int N, S;
	cin >> N >> S;

	bool dp[51][1200] = { false, };

	for (int i = 1; i <= 48; ++i) {
		dp[2 + i][i * (i + 1) / 2] = true;
	}

	for (int i = 3; i < N; ++i) {
		for (int j = 0; j < S; ++j) {
			if (dp[i][j]) {
				for (int k = 1; N - i - k >= 0; ++k) {
					dp[i + k][j + k * (k + 1) / 2] = true;
				}
			}
		}
	}

	if (dp[N][S]) cout << 1;
	else cout << 0;

	return EXIT_SUCCESS;
}