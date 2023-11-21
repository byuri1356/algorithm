#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using int64 = int64_t;

typedef struct _pos {
	int64 x;
	int64 y;
} pos;

char arr_map[101][101];
bool arr_visit[101][101];
int64 arr_count[101][101];
queue<pos> q;

void inline Solve(int64 N, int64 M) {
	int64 x, y;
	q.push({ 1, 1 });
	arr_visit[1][1] = true;
	arr_count[1][1] = 1;
	
	while (!q.empty()) {
		x = q.front().x;
		y = q.front().y;
		q.pop();

		if (x + 1 <= N) {
			if (!arr_visit[x + 1][y]) {
				q.push({ x + 1,y });
				arr_visit[x + 1][y] = true;
				arr_count[x + 1][y] = arr_count[x][y] + 1;
			}
		}
		if (x - 1 > 0) {
			if (!arr_visit[x - 1][y]) {
				q.push({ x - 1,y });
				arr_visit[x - 1][y] = true;
				arr_count[x - 1][y] = arr_count[x][y] + 1;
			}
		}
		if (y + 1 <= M) {
			if (!arr_visit[x][y+1]) {
				q.push({ x,y+1 });
				arr_visit[x][y + 1] = true;
				arr_count[x][y + 1] = arr_count[x][y] + 1;
			}
		}
		if (y - 1 > 0) {
			if (!arr_visit[x][y - 1]) {
				q.push({ x,y - 1 });
				arr_visit[x][y - 1] = true;
				arr_count[x][y - 1] = arr_count[x][y] + 1;
			}
		}
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 N, M;
	cin >> N >> M;
	for (int64 n = 1; n <= N;) {
		for (int64 m = 1; m <= M;) {
			cin >> arr_map[n][m];
			if (arr_map[n][m] == '0') {
				arr_visit[n][m] = true;
			}
			++m;
		}
		++n;
	}

	Solve(N, M);

	cout << arr_count[N][M];

	return EXIT_SUCCESS;
}