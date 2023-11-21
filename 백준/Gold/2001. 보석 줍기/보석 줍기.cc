#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;

const int INF = 10000000;

int N, M, K, ans = 0;
vector < pair<int, int>> vp[101];
priority_queue<pair<int, int>> pq;

inline void Dijkstra(vector<int>& dist) {
	dist[1] = INF;
	pq.push({ INF, 1});
	while (!pq.empty()) {
		int curDis = pq.top().first;
		int curPos = pq.top().second;

		pq.pop();

		if (curDis < dist[curPos]) continue;

		for (int i = 0; i < vp[curPos].size(); ++i) {
			int nextPos = vp[curPos][i].first;
			int nextDis = min(vp[curPos][i].second, dist[curPos]);
			if (dist[nextPos] < nextDis) {
				dist[nextPos] = nextDis;
				pq.push({ nextDis, nextPos });
			}

		}
	}
}

int main() {

	fastio;

	cin >> N >> M >> K;

	vector<int> jewel(K);
	vector<int> dist(N + 1), getting(K);

	for (int i = 0; i < K; ++i) {
		cin >> jewel[i];
	}

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		vp[a].push_back({ b, c });
		vp[b].push_back({ a, c });
	}

	Dijkstra(dist);

	for (int i = 0; i < K; ++i) {
		getting[i] = dist[jewel[i]];
	}

	sort(getting.begin(), getting.end());

	for (auto& iter : getting) {
		if (iter > ans) ans++;
	}

	cout << ans;

	return EXIT_SUCCESS;
}