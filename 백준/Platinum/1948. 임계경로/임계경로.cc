#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MIN
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

bool vit[10'001];
int64 ans;
int64 pr[10'001];
int64 dis[10'001];
vector<pair<int64, int64>> vto[10'001], vfrom[10'001];
queue<tuple<int64, int64, int64>> pq;

inline void cntRoad() {
	while (!pq.empty()) {
		int64 cur = get<0>(pq.front());
		int64 prev_cur = get<1>(pq.front());
		int64 prev_d = dis[prev_cur] + get<2>(pq.front());

		pq.pop();

		if (dis[cur] == prev_d) {
			ans++; //cur; prev_cur;
			if (!vit[prev_cur]) {
				for (auto iter : vfrom[prev_cur]) {
					pq.push({ prev_cur, iter.first, iter.second });
				}
			}
			vit[prev_cur] = true;
		}
	}
}

inline void search() {
	while (!pq.empty()) {
		int64 cur = get<0>(pq.front());
		int64 next_cur = get<1>(pq.front());
		int64 next_d = get<2>(pq.front()) + dis[cur];

		pq.pop();

		pr[next_cur]--;
		dis[next_cur] = max(dis[next_cur], next_d);

		if (!pr[next_cur]) {
			for (auto iter : vto[next_cur]) {
				pq.push({ next_cur, iter.first, iter.second });
			}
		}
	}

}

int main() {
	fastio;

	int64 N, M;
	cin >> N >> M;
	for (int64 i = 0; i < M; ++i) {
		int64 a, b, c;
		cin >> a >> b >> c;

		vto[a].push_back({ b,c });
		vfrom[b].push_back({ a,c });
		pr[b]++;
	}

	int64 st, des;
	cin >> st >> des;

	for (auto iter : vto[st]) {
		pq.push({st, iter.first, iter.second });
	}

	search();

	for (auto iter : vfrom[des]) {
		pq.push({des, iter.first, iter.second });
	}

	cntRoad(); dis[0];

	cout << dis[des] << "\n" << ans;

	return EXIT_SUCCESS;
}