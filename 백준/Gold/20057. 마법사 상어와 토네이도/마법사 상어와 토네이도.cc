#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

bool tk;
int64 N, cur_x, cur_y, cur_dir, cnt = 1, ans;
int64 arr[499][499];
int64 dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
int64 mapping[12][6] = {
		{ 2, 0, 2, 5, -2, 0 },
		{ 10, 1, 1, 10, -1, -1 },
		{ 7, 0, 7, -1, -1, 0 },
		{ 1, 1, 10, 10, -1, 1 },
		{ 5, 2, 0, 2, 0, -2 },
		{ -1, 7, 0, 7, 0, -1 },
		{ 0, 7, -1, 7, 0, 1 },
		{ 0, 2, 5, 2, 0, 2 },
		{ 10, 10, 1, 1, 1, -1 },
		{ 7, -1, 7, 0, 1, 0 },
		{ 1, 10, 10, 1, 1, 1 },
		{ 2, 5, 2, 0, 2, 0 }
};

inline bool isValid(int64 x, int64 y) {
	return (x >= 0 && x < N&& y >= 0 && y < N);
}

inline void check(int64 x, int64 y, int64 dir, int64 cur_mnt) {
	int64 next_x, next_y, a_x, a_y, sum = 0;

	for (int64 i = 0; i < 12; ++i) {
		next_x = x + mapping[i][4];
		next_y = y + mapping[i][5];

		if (!mapping[i][dir]) continue;
		else if (mapping[i][dir] == -1) {
			a_x = next_x;
			a_y = next_y;
		}
		else {
			if (isValid(next_x, next_y)) {
				arr[next_x][next_y] += cur_mnt * mapping[i][dir] / 100;
				arr[x][y] -= cur_mnt * mapping[i][dir] / 100;
			}
			else {
				ans += cur_mnt * mapping[i][dir] / 100;
				arr[x][y] -= cur_mnt * mapping[i][dir] / 100;
			}
		}
	}

	if (isValid(a_x, a_y)) {
		arr[a_x][a_y] += arr[x][y];
		arr[x][y] = 0;
	}
	else {
		ans += arr[x][y];
		arr[x][y] = 0;
	}

}

int main() {
	fastio;

	cin >> N;
	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	cur_x = N / 2;
	cur_y = N / 2;

	while (!tk) {
		for (int64 i = 0; i < 2; ++i) {
			if (tk) break;
			for (int64 j = 0; j < cnt; ++j) {
				cur_x += dx[cur_dir];
				cur_y += dy[cur_dir];

				check(cur_x, cur_y, cur_dir, arr[cur_x][cur_y]);

				if (!(cur_x || cur_y)) {
					tk = true;
					break;
				}
				//cout << cur_x << ' ' << cur_y << "\n";
			}
			cur_dir = (cur_dir + 1) % 4;
		}
		cnt++;
	}

	cout << ans;

	return EXIT_SUCCESS;
}