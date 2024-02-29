#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

int n, m, k, ans, nu[11][11], arr[11][11], cTree[11][11], dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
deque<int> dq[11][11];

bool isVal(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void sol() {

	memset(&cTree[0][0], 0, sizeof cTree);

	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
		deque<int> dq1;
		dq1.swap(dq[i][j]);
		int sum = 0;

		for(int old : dq1) {
			if (nu[i][j] - old < 0) sum += old / 2;
			else {
				dq[i][j].push_back(old + 1);
				nu[i][j] -= old;
				if (!((old + 1) % 5)) {
					for (int k = 0; k < 8; ++k) {
						int nextX = i + dx[k], nextY = j + dy[k];
						if (isVal(nextX, nextY)) {
							cTree[nextX][nextY]++;
						}
					}
				}
			}
		}

		nu[i][j] += sum;
	}

	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
		while (cTree[i][j]--) dq[i][j].push_front(1);
		nu[i][j] += arr[i][j];
	}
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	fill(&nu[0][0], &nu[10][11], 5);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> arr[i][j];
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		dq[a][b].push_front(c);
	}

	while (k--) sol();

	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) ans += dq[i][j].size();
	cout << ans;

	return 0;
}