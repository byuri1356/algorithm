#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool isTeam1[20];
int64 T, Team1, Team2, Ans = INF, arr[20][20];
vector<int64> v1, v2;

inline void team_partition(int64 remain, int64 cur_num) {
	if (!remain) {
		v1.clear(); v2.clear(); Team1 = 0; Team2 = 0;
		for (int64 i = 0; i < T; ++i) {
			if (isTeam1[i]) v1.push_back(i);
			else v2.push_back(i);
		}
		for (auto iter : v1) {
			for (auto _iter : v1) {
				if (iter != _iter) {
					Team1 += arr[iter][_iter];
				}
			}
		}
		for (auto iter : v2) {
			for (auto _iter : v2) {
				if (iter != _iter) {
					Team2 += arr[iter][_iter];
				}
			}
		}
		Ans = min(abs(Team1 - Team2), Ans);
		return;
	}

	for (int64 i = cur_num; i < T; ++i) {
		isTeam1[i] = true;
		team_partition(remain - 1, i + 1);
		isTeam1[i] = false;
	}
}

int main() {
	fastio;

	cin >> T;
	for (int64 i = 0; i < T; ++i) {
		for (int64 j = 0; j < T; ++j) {
			cin >> arr[i][j];
		}
	}

	int64 half = T / 2;
	for (int64 i = 1; i <= half; ++i) {
		team_partition(i, 0);
	}

	cout << Ans;

	return EXIT_SUCCESS;
}