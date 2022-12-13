#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool _visit[4][4];
char arr[4][4];
int64 N, M, Ans;

inline bool R4(int64 x_pos, int64 y_pos) {
	return (y_pos + 3 < M && !_visit[x_pos][y_pos] && !_visit[x_pos][y_pos + 1] && !_visit[x_pos][y_pos + 2] && !_visit[x_pos][y_pos + 3]);
}

inline bool R3(int64 x_pos, int64 y_pos) {
	return (y_pos + 2 < M && !_visit[x_pos][y_pos] && !_visit[x_pos][y_pos + 1] && !_visit[x_pos][y_pos + 2]);
}

inline bool R2(int64 x_pos, int64 y_pos) {
	return (y_pos + 1 < M && !_visit[x_pos][y_pos] && !_visit[x_pos][y_pos + 1]);
}

inline bool C4(int64 x_pos, int64 y_pos) {
	return (x_pos + 3 < N && !_visit[x_pos][y_pos] && !_visit[x_pos + 1][y_pos] && !_visit[x_pos + 2][y_pos] && !_visit[x_pos + 3][y_pos]);
}

inline bool C3(int64 x_pos, int64 y_pos) {
	return (x_pos + 2 < N && !_visit[x_pos][y_pos] && !_visit[x_pos + 1][y_pos] && !_visit[x_pos + 2][y_pos]);
}

inline bool C2(int64 x_pos, int64 y_pos) {
	return (x_pos + 1 < N && !_visit[x_pos][y_pos] && !_visit[x_pos + 1][y_pos]);
}

inline void BF(int64 x_pos, int64 y_pos, int64 score) {
	if (Ans < score) Ans = score;

	for (int64 i = x_pos; i < N; ++i) {
		int64 j;
		if (i == x_pos) j = y_pos;
		else j = 0;
		for (; j < M; ++j) {
			if (R4(i,j)) {
				_visit[i][j] = true; _visit[i][j + 1] = true; _visit[i][j + 2] = true; _visit[i][j + 3] = true;
				BF(i, j + 4, score + 1000 * ((int64)arr[i][j] - 48) + 100 * ((int64)arr[i][j + 1] - 48) + 10 * ((int64)arr[i][j + 2] - 48) + (int64)arr[i][j + 3] - 48);
				_visit[i][j] = false; _visit[i][j + 1] = false; _visit[i][j + 2] = false; _visit[i][j + 3] = false;
			}
			if (R3(i, j)) {
				_visit[i][j] = true; _visit[i][j + 1] = true; _visit[i][j + 2] = true;
				BF(i, j + 3, score + 100 * ((int64)arr[i][j] - 48) + 10 * ((int64)arr[i][j + 1] - 48) + (int64)arr[i][j + 2] - 48);
				_visit[i][j] = false; _visit[i][j + 1] = false; _visit[i][j + 2] = false;
			}
			if (R2(i, j)) {
				_visit[i][j] = true; _visit[i][j + 1] = true;
				BF(i, j + 2, score + 10 * ((int64)arr[i][j] - 48) + (int64)arr[i][j + 1] - 48);
				_visit[i][j] = false; _visit[i][j + 1] = false;
			}
			if (C4(i, j)) {
				_visit[i][j] = true; _visit[i + 1][j] = true; _visit[i + 2][j] = true; _visit[i + 3][j] = true;
				BF(i, j + 1, score + 1000 * ((int64)arr[i][j] - 48) + 100 * ((int64)arr[i + 1][j] - 48) + 10 * ((int64)arr[i + 2][j] - 48) + (int64)arr[i + 3][j] - 48);
				_visit[i][j] = false; _visit[i + 1][j] = false; _visit[i + 2][j] = false; _visit[i + 3][j] = false;
			}
			if (C3(i, j)) {
				_visit[i][j] = true; _visit[i + 1][j] = true; _visit[i + 2][j] = true;
				BF(i, j + 1, score + 100 * ((int64)arr[i][j] - 48) + 10 * ((int64)arr[i + 1][j] - 48) + (int64)arr[i + 2][j] - 48);
				_visit[i][j] = false; _visit[i + 1][j] = false; _visit[i + 2][j] = false;
			}
			if (C2(i, j)) {
				_visit[i][j] = true; _visit[i + 1][j] = true;
				BF(i, j + 1, score + 10 * ((int64)arr[i][j] - 48) + (int64)arr[i + 1][j] - 48);
				_visit[i][j] = false; _visit[i + 1][j] = false;
			}
			if (!_visit[i][j]) {
				_visit[i][j] = true;
				BF(i, j + 1, score + (int64)arr[i][j] - 48);
				_visit[i][j] = false;
			}
		}
	}
}

int main() {
	fastio;

	
	cin >> N >> M;
	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}

	BF(0, 0, 0);
	cout << Ans;

	return EXIT_SUCCESS;
}