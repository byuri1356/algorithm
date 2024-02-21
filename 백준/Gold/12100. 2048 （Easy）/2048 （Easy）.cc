#include<iostream>
#include<algorithm>
#include<math.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;

int n, mx, board[21][21];

bool push(int tmp[][21]) {
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		for (int j = 1, k; j < n; ++j) {
			if (tmp[i][j]) {
				k = j;
				while (k && !tmp[i][k - 1]) k--;
				if (k != j) flag = true, swap(tmp[i][j], tmp[i][k]);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0, k; j < n - 1; ++j) {
			if (tmp[i][j] && tmp[i][j + 1] && tmp[i][j] == tmp[i][j + 1]) {
				flag = true;
				tmp[i][j] *= 2;
				tmp[i][j + 1] = 0;
				k = j + 1;
				copy(&tmp[i][j + 2], &tmp[i][n], &tmp[i][j + 1]);
				tmp[i][n - 1] = 0;
			}
		}
	}

	return flag;
}

void rotate(int tmp[][21], int bd[][21]) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			tmp[i][j] = bd[n - 1 - j][i];
		}
	}
}

void sol(int cnt, int bd[][21]) {
	int curmx = 0;
	for (int i = 0; i < n; ++i) curmx = max(curmx, *max_element(bd[i], bd[i] + n));

	if (curmx * (int)pow(2, 5 - cnt) <= mx) return;

	if (cnt == 5) mx = curmx;

	int tmp[4][21][21] = {};
	rotate(tmp[0], bd);
	for (int i = 1; i < 4; ++i) rotate(tmp[i], tmp[i - 1]);
	for (int i = 0; i < 4; ++i) if (push(tmp[i])) sol(cnt + 1, tmp[i]);
}

int main() {

	fastio;

	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> board[i][j], mx = max(mx, board[i][j]);

	sol(0, board);

	cout << mx;

	return 0;
}