#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using pii = pair<int, int>;

int n, m, h, ans = 4;
bool visit[33][13];

bool game() {
	for (int i = 1; i <= n; ++i) {
		int cur = i;
		for (int j = 1; j <= h; ++j) {
			if (visit[j][cur]) cur += 1;
			else if (visit[j][cur - 1]) cur -= 1;
		}

		if (i != cur) return false;
	}

	return true;
}

void sol(int idx, int x, int y) {
	if (ans <= idx) return;

	if (game()) {
		ans = min(ans, idx);
		return;
	}

	for (int i = x; i <= h; ++i) {
		for (int j = i == x ? y : 1; j < n; ++j) {
			if (!visit[i][j - 1] && !visit[i][j] && !visit[i][j + 1]) {
				visit[i][j] = true;
				sol(idx + 1, i, j + 2);
				visit[i][j] = false;
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> h;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		visit[a][b] = true;
	}

	sol(0, 1, 1);

	ans = ans == 4 ? -1 : ans;
	cout << ans;

	return 0;
}