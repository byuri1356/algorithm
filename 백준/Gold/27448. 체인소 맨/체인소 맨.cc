#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

int N, M, F, Ans;
char mp[80][80];

int main() {
	fastio;

	cin >> N >> M >> F;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> mp[i][j];
		}
	}

	for (int i = 0; i < M - 1; ++i) {
		bool left = false, right = false, cutting = false;
		int sum = 0;
		for (int j = 0; j < N ; ++j) {
			if (mp[j][i] == '#' && mp[j][i + 1] == '#') {
				if (cutting) {
					right = true;
					cutting = false;
					if (left) Ans += sum;
					else Ans = min(Ans + sum, Ans + F);
					sum = 0;
					right = false;
					left = true;
					cutting = false;
				}
				else {
					left = true;

				}
			}
			if ((mp[j][i] == '#' && mp[j][i + 1] == '.') || (mp[j][i] == '.' && mp[j][i + 1] == '#')) {
				cutting = true;
				sum++;
			}
			if (cutting && j == N - 1) {
				Ans = min(Ans + sum, Ans + F);
			}
		}
	}

	for (int i = 0; i < N - 1; ++i) {
		bool left = false, right = false, cutting = false;
		int sum = 0;
		for (int j = 0; j < M; ++j) {
			if (mp[i][j] == '#' && mp[i + 1][j] == '#') {
				if (cutting) {
					right = true;
					cutting = false;
					if (left) Ans += sum;
					else Ans = min(Ans + sum, Ans + F);
					sum = 0;
					right = false;
					left = true;
					cutting = false;
				}
				else {
					left = true;

				}
			}
			if ((mp[i][j] == '#' && mp[i + 1][j] == '.') || (mp[i][j] == '.' && mp[i+ 1][j] == '#')) {
				cutting = true;
				sum++;
			}
			if (cutting && j == M - 1) {
				Ans = min(Ans + sum, Ans + F);
			}
		}
	}

	cout << Ans;

	return EXIT_SUCCESS;
}