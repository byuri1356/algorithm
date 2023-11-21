#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int N, M;
int total, ttotal, ttm, ans = INF;
int arr[50][50], _map[50][50];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> vp;
deque<tuple<int, int, int>> dq, ddq;

inline bool isValid(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < N);
}


//활성 바이러스 3으로 바꾸고 ,if문 수정해야함 백트래킹 추가해야함
inline void BFS() {
	while (!ddq.empty()) {
		if (!ttotal || ans<= ttm) {
			ddq.clear();
			break;
		}

		int cur_x = get<0>(ddq.front());
		int cur_y = get<1>(ddq.front());
		int dis = get<2>(ddq.front());

		ddq.pop_front();

		for (int i = 0; i < 4; ++i) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (isValid(next_x, next_y)) {
				if (_map[next_x][next_y] == 0) {
					_map[next_x][next_y] = 3;
					ddq.push_back({ next_x, next_y, dis + 1 });
					ttm = max(ttm, dis + 1);
					ttotal--;
				}
				else if (_map[next_x][next_y] == 2) {
					_map[next_x][next_y] = 3;
					ddq.push_back({ next_x, next_y, dis + 1 });
				}
			}
		}
	}
	if(!ttotal) ans = min(ans, ttm);
}

inline void init() {
	ttm = 0;
	ttotal = total;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			_map[i][j] = arr[i][j];
		}
	}
	
	for (auto iter : dq) {
		ddq.push_back({get<0>(iter), get<1>(iter), get<2>(iter)});
		_map[get<0>(iter)][get<1>(iter)] = 3;
	}
}

inline void conbi(int dep, int cur) {
	if (dep == M) {
		init();
		BFS();
		return;
	}

	for (int i = cur; i < vp.size(); ++i) {
		dq.push_back({vp[i].first, vp[i].second, 0});
		conbi(dep +1, i + 1);
		dq.pop_back();
	}
}

int main() {
	fastio;

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
			if (!arr[i][j]) {
				total++;
			}
			if (arr[i][j] == 2) {
				vp.push_back({ i, j });
			}
		}
	}

	conbi(0, 0);

	if (ans == INF) cout << -1;
	else cout << ans;

	return EXIT_SUCCESS;
}