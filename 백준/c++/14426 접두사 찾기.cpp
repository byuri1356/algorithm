#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

bool isjub[10'000], token;
string s[10'000], ch[10'000];

int main() {
	fastio;

	int64 N, M, ans = 0;
	cin >> N >> M;

	for (int64 i = 0; i < N; ++i) {
		cin >> s[i];
	}
	for (int64 i = 0; i < M; ++i) {
		cin >> ch[i];
	}

	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < M; ++j) {
			if (s[i].length() < ch[j].length() || isjub[j]) continue;
			token = true;
			for (int64 k = 0; k < ch[j].length(); ++k) {
				if (s[i][k] != ch[j][k]) {
					token = false;
					break;
				}
			}
			if (token) {
				isjub[j] = true;
				ans++;
			}
		}
	}

	cout << ans;

	return EXIT_SUCCESS;
}