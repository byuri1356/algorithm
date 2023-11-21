#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

bool isLoop = false;
int64 d[501];
vector<pair<int64, int64>> vec[501];

int main() {
	fastio;

	int64 N, M;
	cin >> N >> M;

	for (int64 i = 2; i <= N; ++i) {
		d[i] = INF;
	}

	for (int64 i = 0; i < M; ++i) {
		int64 a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b, c });
	}

	for (int64 i = 1; i < N; ++i) {
		for (int64 j = 1; j <= N; ++j) {
			for (int64 k = 0; k < vec[j].size(); ++k) {
				int64 next_pos = vec[j][k].first;
				int64 next_dis = vec[j][k].second;

				if (d[j] == INF) continue;
				else if (d[next_pos] > d[j] + next_dis) d[next_pos] = d[j] + next_dis;
			}
		}
	}

	for (int64 j = 1; j <= N; ++j) {
		for (int64 k = 0; k < vec[j].size(); ++k) {
			int64 next_pos = vec[j][k].first;
			int64 next_dis = vec[j][k].second;

			if (d[j] == INF) continue;
			else if (d[next_pos] > d[j] + next_dis) isLoop = true;
		}
	}

	if (isLoop) cout << -1;
	else {
		for (int64 i = 2; i <= N; ++i) {
			if (d[i] == INF) cout << -1 << "\n";
			else cout << d[i] << "\n";
		}
	}

	return EXIT_SUCCESS;
}