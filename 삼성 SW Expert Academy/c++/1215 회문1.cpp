#include<iostream>
#include<deque>
using namespace std;
using int64 = int64_t;

char arr[8][8];
int64 N, token = 0, ans = 0;
deque<char> dq;

void check_rotate(int64 row, int64 column) {
	int64 cnt;

	if (token == 0) {
		dq.clear();
		for (int64 i = 0; i < N; ++i) {
			dq.push_back(arr[row][column + i]);
		}

		cnt = 0;
		for (int64 i = 0; i < (N + 1) / 2; ++i) {
			if (dq[0 + i] != dq[dq.size() - 1 - i]) break;
			cnt++;
		}
		if (cnt == (N + 1) / 2) {
			ans++;
		}
		dq.clear();
	}
	else {
		dq.clear();
		for (int64 i = 0; i < N; ++i) {
			dq.push_back(arr[row + i][column]);
		}

		cnt = 0;
		for (int64 i = 0; i < (N + 1) / 2; ++i) {
			if (dq[0 + i] != dq[dq.size() - 1 - i]) break;
			cnt++;
		}
		if (cnt == (N + 1) / 2) {
			ans++;
		}
		dq.clear();
	}
	
}

int main() {
	for (int64 t = 1; t <= 10; ++t) {
		cin >> N;

		for (int64 i = 0; i < 8; ++i) {
			for (int64 j = 0; j < 8; ++j) {
				cin >> arr[i][j];
			}
		}

		for (int64 i = 0; i < 8; ++i) {
			for (int64 j = 0; j <= 8 - N; ++j) {
				token = 0;
				check_rotate(i, j);
			}
		}
		
		for (int64 i = 0; i <= 8 - N; ++i) {
			for (int64 j = 0; j < 8; ++j) {
				token = 1;
				check_rotate(i, j);
			}
		}

		cout << '#' << t << ' ' << ans << "\n";
		ans = 0;
	}


	return EXIT_SUCCESS;
}