#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
#include<queue>
using namespace std;
using pii = pair<int, int>;

int r, c;
int visit[1502][1502];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool check[1502][1502];
char bd[1502][1502];

vector<pii> s;
queue<pii> q;

bool isValid(int x, int y) {
	return 0 <= x && x < r && 0 <= y && y < c;
}

bool search(int pv) {
	memset(check, false, sizeof check);
	q.push(s[0]);
	check[s[0].first][s[0].second] = true;

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (isValid(nextX, nextY) && !check[nextX][nextY] && visit[nextX][nextY] <= pv) {
				check[nextX][nextY] = true;
				q.push({ nextX, nextY });
			}
		}
	}

	return check[s[1].first][s[1].second];
}

int sol() {
	int start = 0, end = 1502, ans = end;

	while (start <= end) {
		int mid = (start + end) >> 1;

		if (search(mid)) {
			ans = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}

	return ans;
}

void bfs() {
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (isValid(nextX, nextY) && visit[nextX][nextY] == -1) {
				visit[nextX][nextY] = visit[x][y] + 1;
				q.push({ nextX, nextY });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	memset(visit, -1, sizeof visit);

	cin >> r >> c;

	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
		cin >> bd[i][j];

		if (bd[i][j] == '.' || bd[i][j] == 'L') q.push({ i, j }), visit[i][j] = 0;
		if (bd[i][j] == 'L') s.push_back({ i, j });
	}

	bfs();

	cout << sol();

	return 0;
}