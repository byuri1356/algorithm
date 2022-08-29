#include <iostream>
#include<vector>
using namespace std;
using int64 = int64_t;

int64 arr[51][51] = {};
int64 ans;

inline void solve(int64 r, int64 c, int64 d ) {

		if (arr[r][c] == 0) {
			arr[r][c] = 2;
			ans++;
		}
	
		if (arr[r + 1][c] > 0 && arr[r - 1][c] > 0 && arr[r][c + 1] > 0 && arr[r][c - 1] > 0) {
			if (d == 0) {
				if (arr[r+1][c] == 1) {
					return;
				}
				else {
					solve(r + 1, c, d);
				}
			}
			else if (d == 1) {
				if (arr[r][c-1] == 1) {
					return;
				}
				else {
					solve(r, c-1, d);
				}
			}
			else if (d == 2) {
				if (arr[r - 1][c] == 1) {
					return;
				}
				else {
					solve(r - 1, c, d);
				}
			}
			else if (d == 3) {
				if (arr[r][c+1] == 1) {
					return;
				}
				else {
					solve(r , c+1, d);
				}
			}
		}
		else {
			if (d == 0) {
				if (arr[r][c - 1] == 0) {
					c = c - 1;
					d = 3;
					solve(r, c, d);
				}
				else {
					solve(r, c, 3);
				}
			}
			else if (d == 1) {
				if (arr[r - 1][c] == 0) {
					r = r - 1;
					d = 0;
					solve(r, c, d);
				}
				else {
					solve(r, c, 0);
				}
			}
			else if (d == 2) {
				if (arr[r][c + 1] == 0) {
					c = c + 1;
					d = 1;
					solve(r, c, d);
				}
				else {
					solve(r, c, 1);
				}
			}
			else if (d == 3) {
				if (arr[r + 1][c] == 0) {
					r = r + 1;
					d = 2;
					solve(r, c, d);
				}
				else {
					solve(r, c, 2);
				}
			}
		}
}

int main(void){
	ios::sync_with_stdio;
	cin.tie(nullptr); cout.tie(nullptr);

	int64 row, column;
	cin >> row >> column;

	int64 r, c, d;
	cin >> r >> c >> d;

	for (int64 i = 0; i < row;) {
		for (int64 j = 0; j < column;) {
			cin >> arr[i][j];
			++j;
		}
		++i;
	}

	solve(r, c, d);

	cout << ans;

	return EXIT_SUCCESS;
}
