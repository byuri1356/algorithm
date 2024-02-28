#include<iostream>
#include<cstring>
#include<queue>
#include<set>
using namespace std;
using pii = pair<int, int>;

int n, l, r, ans, cnt, sum, arr[51][51], vst[51][51], dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
queue<pii> q;
set<pii> s;

bool isVal(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void sol() {
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nextX = x + dx[i], nextY = y + dy[i];
			if (isVal(nextX, nextY) && !vst[nextX][nextY] && l <= abs(arr[x][y] - arr[nextX][nextY]) && abs(arr[x][y] - arr[nextX][nextY]) <= r) {
				vst[nextX][nextY] = cnt;
				s.insert({ nextX, nextY });
				sum += arr[nextX][nextY];
				q.push({ nextX, nextY });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> arr[i][j];

	while (true) {
		memset(vst, 0, sizeof vst);
		cnt = 0;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			if (!vst[i][j]) {
				sum = arr[i][j];
				++cnt;
				s.clear();
				s.insert({ i, j });
				q.push({ i, j });
				vst[i][j] = cnt;
				sol();
				int div = sum / s.size();
				for (auto &[x, y] : s) arr[x][y] = div;
			}

		}
		if (cnt == n * n) break;
		ans++;
	}

	cout << ans;

	return 0;
}