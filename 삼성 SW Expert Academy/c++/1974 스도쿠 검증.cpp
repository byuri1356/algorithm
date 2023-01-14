#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[9][9];

inline bool checkColumn(int64 c) {
	bool cnt[10]{ false, };
	for (int64 i = 0; i < 9; ++i) {
		if (!cnt[arr[i][c]]) cnt[arr[i][c]] = true;
		else {
			return false;
		}
	}
	return true;
}

inline bool checkRow(int64 r) {
	bool cnt[10]{ false, };
	for (int64 i = 0; i < 9; ++i) {
		if (!cnt[arr[r][i]]) cnt[arr[r][i]] = true;
		else {
			return false;
		}
	}
	return true;
}

inline bool checkSquare(int64 r, int64 c) {
	bool cnt[10]{ false, };
	for (int64 i = 3 * r; i < (3 * r) + 3; ++i) {
		for (int64 j = 3 * c; j < (3 * c) + 3; ++j) {
			if (!cnt[arr[i][j]]) cnt[arr[i][j]] = true;
			else {
				return false;
			}
		}
	}
	return true;
}

inline bool checkSudoku() {
	for (int64 i = 0; i < 3; ++i) {
		for (int64 j = 0; j < 3; ++j) {
			if (!checkSquare(i, j)) return false;
		}
	}

	for (int64 i = 0; i < 9; ++i) {
		if (!checkRow(i)) return false;
		if (!checkColumn(i)) return false;
	}

	return true;
}

int main() {
	fastio;

	int64 T;
	cin >> T;

	for (int64 t = 1; t <= T; ++t) {
		for (int64 i = 0; i < 9; ++i) {
			for (int64 j = 0; j < 9; ++j) {
				cin >> arr[i][j];
			}
		}

		if (checkSudoku()) {
			cout << "#" << t << ' ' << "1" << "\n";
		}
		else cout << "#" << t << ' ' << "0" << "\n";
	}

	return EXIT_SUCCESS;
}