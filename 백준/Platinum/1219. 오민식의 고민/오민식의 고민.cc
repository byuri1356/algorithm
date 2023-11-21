#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

bool tk;
int64 N, A, B, M;
int64 dist[50];
int64 earn_Mny[50];
vector<pair<int64, int64>> vp[50];

int main() {
	fastio;

	cin >> N >> A >> B >> M;

	for (int64 i = 0; i < N; ++i) {
		dist[i] = -INF;
	}

	for (int64 i = 0; i < M; ++i) {
		int64 a, b, c;
		cin >> a >> b >> c;

		vp[a].push_back({ b, c });
	}

	for (int64 i = 0; i < N; ++i) {
		cin >> earn_Mny[i];
	}
	dist[A] = earn_Mny[A];

	for (int64 i = 0; i < N - 1; ++i) {
		for (int64 j = 0; j < N; ++j) {
			if (dist[j] == -INF) continue;
			for (int64 k = 0; k < vp[j].size(); ++k) {
				int64 next_c = vp[j][k].first;
				int64 next_d = dist[j] - vp[j][k].second + earn_Mny[next_c];

				if (next_d > dist[next_c]) {
					dist[next_c] = next_d;
				}
			}
		}
	}

	if (dist[B] == -INF) cout << "gg";
	else {
		int64 res = dist[B];
		for (int64 i = 0; i < N; ++i) {
			for (int64 j = 0; j < N; ++j) {
				if (dist[j] == -INF) continue;
				for (int64 k = 0; k < vp[j].size(); ++k) {
					int64 next_c = vp[j][k].first;
					int64 next_d = dist[j] - vp[j][k].second + earn_Mny[next_c];

					if (next_d > dist[next_c]) {
						dist[next_c] = INF;
					}
				}
			}
		}

		if (res == dist[B]) cout << res;
		else cout << "Gee";
	}

	return EXIT_SUCCESS;
}