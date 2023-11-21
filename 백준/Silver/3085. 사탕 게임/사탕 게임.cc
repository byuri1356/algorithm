#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int64 Ans;
int64 dx[4] = { -1, 0, 1, 0 };
int64 dy[4] = { 0, 1, 0, -1 };
char _map[50][50];

inline bool _pos(int64 next_X, int64 next_Y, int64 N) {
	return (next_X >= 0) && (next_X < N) && (next_Y >= 0) && (next_Y < N);
}

inline void Solve(int64 N) {
	int64 res = 0;
	char _key[4] = {'C', 'P', 'Z', 'Y'};
	for (int64 i = 0; i < 4;) {
		for (int64 j = 0; j < N;) {
			for (int64 k = 0; k < N;) {
				if (_key[i] != _map[j][k]) {
					for (int64 l = 0; l < 4;) {
						int64 next_X = j + dx[l];
						int64 next_Y = k + dy[l];
						int64 cur, swap;
						if (_pos(next_X, next_Y, N)) {
							cur = _map[j][k];
							swap = _map[next_X][next_Y];
							_map[j][k] = swap;
							_map[next_X][next_Y] = cur;
							for (int64 m = 0; m < N;) {
								if (_key[i] == _map[j][m]) {
									res++;
								}
								else {
									Ans = max(res, Ans);
									res = 0;
								}
								++m;
							}
							Ans = max(res, Ans);
							res = 0;
							_map[j][k] = cur;
							_map[next_X][next_Y] = swap;
						}
						++l;
					}
				}
				++k;
			}
			for (int64 k = 0; k < N;) {
				if (_key[i] == _map[j][k]) {
					res++;
				}
				else {
					Ans = max(res, Ans);
					res = 0;
				}
				++k;
			}
			Ans = max(res, Ans);
			res = 0;
			++j;
		}
		for (int64 j = 0; j < N;) {
			for (int64 k = 0; k < N;) {
				if (_key[i] != _map[k][j]) {
					for (int64 l = 0; l < 4;) {
						int64 next_X = k + dx[l];
						int64 next_Y = j + dy[l];
						int64 cur, swap;
						if (_pos(next_X, next_Y, N)) {
							cur = _map[k][j];
							swap = _map[next_X][next_Y];
							_map[k][j] = swap;
							_map[next_X][next_Y] = cur;
							for (int64 m = 0; m < N;) {
								if (_key[i] == _map[m][j]) {
									res++;
								}
								else {
									Ans = max(res, Ans);
									res = 0;
								}
								++m;
							}
							Ans = max(res, Ans);
							res = 0;
							_map[k][j] = cur;
							_map[next_X][next_Y] = swap;
						}
						++l;
					}
				}
				++k;
			}
			for (int64 k = 0; k < N;) {
				if (_key[i] == _map[k][j]) {
					res++;
				}
				else {
					Ans = max(res, Ans);
					res = 0;
				}
				++k;
			}
			Ans = max(res, Ans);
			res = 0;
			++j;
		}
		++i;
	}
}

int main() {
	fastio;
	
	int64 N;
	cin >> N;
	for (int64 i = 0; i < N;) {
		for (int64 j = 0; j < N;) {
			cin >> _map[i][j];
			++j;
		}
		++i;
	}

	Solve(N);
	cout << Ans;

	return EXIT_SUCCESS;
}