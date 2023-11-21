#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool arr[101][101];
int64 N, x, y, d, g, cnt;
vector<tuple<int64, int64, int64>> v[21];

inline void dragonCur(int64 num) {
	
	for (int64 i = 0; i < g; ++i) {
		int64 size = v[num].size();
		for (int64 j = size - 1; j >= 0; --j) {
			int64 x_pos = get<1>(v[num].back()), y_pos = get<0>(v[num].back()), dir = get<2>(v[num].back());
			if (dir == 0) x_pos++;
			else if (dir == 1) y_pos--;
			else if (dir == 2) x_pos--;
			else if (dir == 3) y_pos++;

			v[num].push_back({ y_pos, x_pos, (get<2>(v[num][j]) + 1) % 4 });
		}
	}

	for (int64 i = 0; i < v[num].size(); ++i) {
		arr[get<0>(v[num][i])][get<1>(v[num][i])] = true;
	}

	if (get<2>(v[num][v[num].size() - 1]) == 0) arr[get<0>(v[num][v[num].size() - 1])][get<1>(v[num][v[num].size() - 1]) + 1] = true;
	else if (get<2>(v[num][v[num].size() - 1]) == 1) arr[get<0>(v[num][v[num].size() - 1]) - 1][get<1>(v[num][v[num].size() - 1])] = true;
	else if (get<2>(v[num][v[num].size() - 1]) == 2) arr[get<0>(v[num][v[num].size() - 1])][get<1>(v[num][v[num].size() - 1]) - 1] = true;
	else if (get<2>(v[num][v[num].size() - 1]) == 3) arr[get<0>(v[num][v[num].size() - 1]) + 1][get<1>(v[num][v[num].size() - 1])] = true;

}

int main() {
	fastio;

	cin >> N;
	for (int64 i = 0; i < N; ++i) {
		cin >> x >> y >> d >> g;

		v[i].push_back({ y,x,d });
		dragonCur(i);

		/*
		for (auto iter : v[i]) {
			cout << "y_pos: " << get<0>(iter) << ' ' << "x_pos: " << get<1>(iter) << ' ' << "dir: " << get<2>(iter) << "\n";
		}
		*/
		
	}

	for (int64 i = 0; i < 100; ++i) {
		for (int64 j = 0; j < 100; ++j) {
			if (arr[i][j] && arr[i][j+1] && arr[i + 1][j] && arr[i + 1][j + 1]) cnt++;
		}
	}

	cout << cnt;

	return EXIT_SUCCESS;
}