#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

char arr[16][16];
int64 c, dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

inline void checkMap(int64 start_x, int64 start_y) {
	queue<pair<int64, int64>> q;
	q.push({ start_x, start_y });

	while (!q.empty()) {
		int64 x = q.front().first;
		int64 y = q.front().second;
		q.pop();

		for (int64 i = 0; i < 4; ++i) {
			int64 next_x = x + dx[i];
			int64 next_y = y + dy[i];

			if (arr[next_x][next_y] == '0') {
				arr[next_x][next_y] = '1';
				q.push({ next_x, next_y });
			}
		}
	}
}

int main() {
	fastio;

	//int64 T;
	//cin >> T;

	for (int64 t = 1; t <= 10; ++t) {
		cin >> c;

		int64 start_x, start_y, end_x, end_y;

		for (int64 i = 0; i < 16; ++i) {
			for (int64 j = 0; j < 16; ++j) {
				cin >> arr[i][j];
				if (arr[i][j] == '2') {
					start_x = i; 
					start_y = j;
					arr[i][j] = '0';
				}
				else if (arr[i][j] == '3') {
					end_x = i;
					end_y = j;
					arr[i][j] = '0';
				}
			}
		}

		checkMap(start_x, start_y);

		if (arr[end_x][end_y] == '1') {
			cout << "#" << t << ' ' << "1" << "\n";
		}
		else {
			cout << "#" << t << ' ' << "0" << "\n";
		}
	
	}

	return EXIT_SUCCESS;
}