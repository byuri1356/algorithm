#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

int64 _max;
int64 arr[501][501];

inline void tet1(int64 i, int64 j, int64 row, int64 col) {
	if (j + 3 < col)
		_max = max(_max, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3]);
	if (j - 3 >= 0)
		_max = max(_max, arr[i][j] + arr[i][j - 1] + arr[i][j - 2] + arr[i][j - 3]);
	if (i + 3 < row)
		_max = max(_max, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j]);
	if (i - 3 >= 0)
		_max = max(_max, arr[i][j] + arr[i - 1][j] + arr[i - 2][j] + arr[i - 3][j]);
}

inline void tet2(int64 i, int64 j, int64 row, int64 col) {
	if ((j + 1 < col) && (i + 1 < row))
		_max = max(_max, arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
	if ((j - 1 >=0) && (i + 1 < row))
		_max = max(_max, arr[i][j] + arr[i][j - 1] + arr[i + 1][j] + arr[i + 1][j - 1]);
	if ((j - 1 >= 0) && (i - 1 >= 0))
		_max = max(_max, arr[i][j] + arr[i][j - 1] + arr[i - 1][j] + arr[i - 1][j - 1]);
	if ((j + 1 <col) && (i - 1 >= 0))
		_max = max(_max, arr[i][j] + arr[i][j + 1] + arr[i - 1][j] + arr[i - 1][j + 1]);
}

inline void tet3(int64 i, int64 j, int64 row, int64 col) {
	if ((j + 1 < col) && (i + 2 < row))
		_max = max(_max, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1]);
	if ((j - 2 >= 0) && (i + 1 < row))
		_max = max(_max, arr[i][j] + arr[i][j - 1] + arr[i][j - 2] + arr[i + 1][j - 2]);
	if ((j - 1 >= 0) && (i - 2 >= 0))
		_max = max(_max, arr[i][j] + arr[i - 1][j] + arr[i - 2][j] + arr[i - 2][j - 1]);
	if ((j + 2 < col) && (i - 1 >= 0))
		_max = max(_max, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2]);
	
	if ((j - 1 >= 0) && (i + 2 < row))
		_max = max(_max, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j - 1]);
	if ((j - 2 >= 0) && (i - 1 >=0))
		_max = max(_max, arr[i][j] + arr[i][j - 1] + arr[i][j - 2] + arr[i - 1][j - 2]);
	if ((j + 1 < col) && (i - 2 >= 0))
		_max = max(_max, arr[i][j] + arr[i - 1][j] + arr[i - 2][j] + arr[i - 2][j + 1]);
	if ((j + 2 < col) && (i + 1 < row))
		_max = max(_max, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2]);
}

inline void tet4(int64 i, int64 j, int64 row, int64 col) {
	if ((j + 1 < col) && (i + 2 < row))
		_max = max(_max, arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1]);
	if ((j - 2 >= 0) && (i + 1 < row))
		_max = max(_max, arr[i][j] + arr[i][j - 1] + arr[i + 1][j - 1] + arr[i + 1][j - 2]);
	if ((j - 1 >= 0) && (i - 2 >= 0))
		_max = max(_max, arr[i][j] + arr[i - 1][j] + arr[i - 1][j - 1] + arr[i - 2][j - 1]);
	if ((j + 2 < col) && (i - 1 >= 0))
		_max = max(_max, arr[i][j] + arr[i][j + 1] + arr[i - 1][j + 1] + arr[i - 1][j + 2]);

	if ((j - 1 >= 0) && (i + 2 < row))
		_max = max(_max, arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 2][j - 1]);
	if ((j - 2 >= 0) && (i - 1 >= 0))
		_max = max(_max, arr[i][j] + arr[i][j - 1] + arr[i - 1][j - 1] + arr[i - 1][j - 2]);
	if ((j + 1 < col) && (i - 2 >= 0))
		_max = max(_max, arr[i][j] + arr[i - 1][j] + arr[i - 1][j + 1] + arr[i - 2][j + 1]);
	if ((j + 2 < col) && (i + 1 < row))
		_max = max(_max, arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2]);
}

inline void tet5(int64 i, int64 j, int64 row, int64 col) {
	if ((j + 2 < col) && (i + 1 < row))
		_max = max(_max, arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i][j + 2]);
	if ((j - 1 >= 0) && (i + 2 < row))
		_max = max(_max, arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 2][j]);
	if ((j - 2 >= 0) && (i - 1 >= 0))
		_max = max(_max, arr[i][j] + arr[i][j - 1] + arr[i - 1][j - 1] + arr[i][j - 2]);
	if ((j + 1 < col) && (i - 2 >= 0))
		_max = max(_max, arr[i][j] + arr[i - 1][j] + arr[i - 1][j + 1] + arr[i - 2][j]);
}

inline void Solve(int64 row, int64 col) {
	for (int64 i = 0; i < row;) {
		for (int64 j = 0; j < col;) {
			tet1(i, j, row, col);
			tet2(i, j, row, col);
			tet3(i, j, row, col);
			tet4(i, j, row, col);
			tet5(i, j, row, col);
			++j;
		}
		++i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 row, col;
	cin >> row >> col;
	for (int64 i = 0; i < row;) {
		for (int64 j = 0; j < col;) {
			cin >> arr[i][j];
			++j;
		}
		++i;
	}
	Solve(row, col);
	cout << _max;
	return EXIT_SUCCESS;
}