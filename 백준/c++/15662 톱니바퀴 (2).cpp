#include <iostream>
#include<vector>
#include<string>
using namespace std;
using int64 = int64_t;

int64 ans, T;
vector<int64> arr[1001];

inline void rotate(int64 num, int64 vec) {
	if (vec == 1) {
		int64 save = arr[num].back();
		arr[num].insert(arr[num].begin(), save);
		arr[num].pop_back();
	}
	else if (vec == -1) {
		int64 save = arr[num].front();
		arr[num].push_back(save);
		arr[num].erase(arr[num].begin());
	}
}

inline void solve(int64 num, int64 vec, bool right, bool root) {
	if ((num == T) && right) {
		rotate(num, vec);
		return;
	}
	else if ((num == 1) && !right) {
		rotate(num, vec);
		return;
	}
	else if (right) {
		if (arr[num][2] != arr[num + 1][6]) {
			right = true;
			solve(num + 1, -vec, right, false);
		}
	}
	else if (!right) {
		if (arr[num][6] != arr[num - 1][2]) {
			right = false;
			solve(num - 1, -vec, right, false);
		}
	}

	if (!root) {
		rotate(num, vec);
	}
}

int main(void) {
	ios::sync_with_stdio;
	cin.tie(nullptr); cout.tie(nullptr);


	cin >> T;

	char c[1001][8];
	for (int64 i = 1; i <= T;) {
		for (int64 j = 0; j < 8;) {
			cin >> c[i][j];
			arr[i].push_back((int64)c[i][j] - 48);
			++j;
		}
		++i;
	}

	int64 K;
	cin >> K;

	int64 num, vec;
	for (int64 i = 0; i < K;) {
		cin >> num >> vec;
		if (num == 1) {
			solve(num, vec, true, true);
		}
		else if (num == T) {
			solve(num, vec, false, true);
		}
		else {
			solve(num, vec, true, true);
			solve(num, vec, false, true);
		}
		rotate(num, vec);

		++i;
	}

	for (int64 i = 1; i <= T; ++i) {
		if (arr[i][0]) {
			ans++;
		}
	}

	cout << ans;

	return EXIT_SUCCESS;
}