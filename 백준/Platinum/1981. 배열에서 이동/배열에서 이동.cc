#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, mi, mx, st, ed, ans, arr[100][100], dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

bool valid(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; }
bool check(int a, int b, int c) { return a <= c && c <= b; }

bool sol(int a, int b) {
	bool visit[100][100] = {};
	if (check(a, b, arr[0][0])) {
		q.push({ 0, 0 });
		visit[0][0] = 1;
	}

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		for (int i = 0; i < 4; ++i) {
			int nextX = x + dx[i], nextY = y + dy[i];
			if (valid(nextX, nextY) && check(a, b, arr[nextX][nextY]) && !visit[nextX][nextY]) {
				q.push({ nextX, nextY });
				visit[nextX][nextY] = 1;
			}
		}
	}

	return visit[n - 1][n - 1];
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> arr[i][j];

	auto [pf, ps] = minmax_element(&arr[0][0], &arr[n - 1][n]);
	mi = *pf, mx = *ps;
	st = 0, ed = mx - mi;

	while (st <= ed) {
		int mid = (st + ed) >> 1;
		bool tk = false;

		for (int i = mi; i + mid <= mx; ++i) {
			if (tk = sol(i, i + mid)) break;
		}

		if (tk) ed = mid - 1, ans = mid;
		else st = mid + 1;
	}

	cout << ans;

	return 0;
}