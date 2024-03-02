#include<iostream>
#include<cstring>
using namespace std;

int r, c, t, cx, cy, ans, arr[50][50], tmp[50][50], dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

void sol(int x, int y, int d, int p) {
	int a = x, b = y;
	arr[a][b] = 0;
	while (true) {
		int nx = x + dx[d], ny = y + dy[d];
		if ((nx < 0 || r - 1 < nx || ny < 0 || c - 1 < ny) || nx == a + p) d = (d + 1) % 4;
		nx = x + dx[d], ny = y + dy[d];

		arr[x][y] = arr[nx][ny];
		if (nx == a && ny == b) {
			arr[x][y] = 0;
			break;
		}
		x = nx, y = ny;
	}

	arr[a][b] = -1;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> r >> c >> t;
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
		cin >> arr[i][j];
		if (arr[i][j] == -1) cx = i, cy = j;
	}

	while (t--) {
		memset(tmp, 0, sizeof tmp);
		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
			int cnt = 0;
			for (int k = 0; k < 4; ++k) {;
				int x = i + dx[k], y = j + dy[k];
				if (0 <= x && x < r && 0 <= y && y < c && arr[x][y] != -1) {
					tmp[x][y] += arr[i][j] / 5;
					cnt++;
				}
			}
			arr[i][j] -= arr[i][j] / 5 * cnt;
		}

		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) arr[i][j] += tmp[i][j];
		
		sol(cx - 1, cy, 3, 1);
		swap(dx[0], dx[2]), swap(dy[0], dy[2]);
		sol(cx, cy, 3, -1);
		swap(dx[0], dx[2]), swap(dy[0], dy[2]);
	}

	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) ans += arr[i][j];

	cout << ans + 2;

	return 0;
}