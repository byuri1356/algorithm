#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool isSquare, token, isEnd, makeSquare[6];
int64 arr[6][6], dx[4] = { -1, 0, 1, 0 }, dy[4] = {0, 1, 0, -1};

inline void checkSquare(int64 x, int64 y, int64 bottom, int64 nor, int64 east, int64 sou, int64 west, int64 top) {
	if (isEnd) return;

	for (int64 i = 0; i < 4; ++i) {
		int64 next_x = x + dx[i];
		int64 next_y = y + dy[i];

		if ((next_x >= 0) && (next_x < 6) && (next_y >= 0) && (next_y < 6)) {
			if (arr[next_x][next_y]) {
				arr[next_x][next_y] = 0;
				if (i == 0) {
					if (makeSquare[nor]) {
						isEnd = true;
						return;
					}
					else {
						makeSquare[nor] = true;
						checkSquare(next_x, next_y, nor, top, east, bottom, west, sou);
					}
				}
				else if (i == 1) {
					if (makeSquare[east]) {
						isEnd = true;
						return;
					}
					else {
						makeSquare[east] = true;
						checkSquare(next_x, next_y, east, nor, top, sou, bottom, west);
					}
				}
				else if (i == 2) {
					if (makeSquare[sou]) {
						isEnd = true;
						return;
					}
					else {
						makeSquare[sou] = true;
						checkSquare(next_x, next_y, sou, bottom, east, top, west, nor);
					}
				}
				else {
					if (makeSquare[west]) {
						isEnd = true;
						return;
					}
					else {
						makeSquare[west] = true;
						checkSquare(next_x, next_y, west, nor, bottom, sou, top, east);
					}
				}
			}
		}
	}
}

int main() {
	fastio;

	for (int64 i = 0; i < 3; ++i) {
		token = true, isSquare = true, isEnd = false;
		for (int64 j = 0; j < 6; ++j) {
			makeSquare[j] = false;
		}

		int64 x, y;
		for (int64 j = 0; j < 6; ++j) {
			for (int64 k = 0; k < 6; ++k) {
				cin >> arr[j][k];
				if ((token == true) && (arr[j][k] == 1)) {
					x = j;
					y = k;
					token = false;
				}
			}
		}

		checkSquare(x, y, 0, 1, 2, 3, 4, 5);

		for (int64 j = 0; j < 6; ++j) {
			if (!makeSquare[j]) {
				isSquare = false;
				break;
			}
		}

		if (isSquare) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}

	return EXIT_SUCCESS;
}