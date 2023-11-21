#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;

int N, M;
int isVisit[50][50][4];
char arr[50][50];
bool findness;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
queue<tuple<int, int, int, int, int>> q; // x,y,시간,방향,남은개수

inline bool isValid(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}

inline bool check(int x, int y, int d, int g) {
	if (isVisit[x][y][d] == -1) {
		isVisit[x][y][d] = g;
		return true;
	}

	if (isVisit[x][y][d] != g && (isVisit[x][y][d] & g) != g) {
		isVisit[x][y][d] = g;
		return true;
	}

	return false;
}


inline void BFS() {
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int t = get<2>(q.front());
		int d = get<3>(q.front());
		int g = get<4>(q.front());

		q.pop();

		if (g == 3) {
			cout << t;
			findness = true;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			if (d == i) continue;
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (isValid(nextX, nextY) && check(nextX, nextY, i, g) && arr[nextX][nextY] != '#') {
				if (arr[nextX][nextY] == 'B') {
					q.push({ nextX, nextY, t + 1, i, g | 1 << 0 });
				}
				else if (arr[nextX][nextY] == 'C') {
					q.push({ nextX, nextY, t + 1, i, g | 1 << 1 });
				}

				q.push({ nextX, nextY, t + 1, i, g });
			}
		}
	}
}

int main() {

	bool flag = true;

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];

			for (int k = 0; k < 4; ++k) {
				isVisit[i][j][k] = -1;
			}

			if (arr[i][j] == 'S') {
				q.push({ i, j, 0, -1, 0 });
				for (int k = 0; k < 4; ++k) {
					isVisit[i][j][k] = 0;
				}
			}
			else if (flag && arr[i][j] == 'C') {
				arr[i][j] = 'B';
				flag = false;
			}
		}
	}

	BFS();

	if (!findness) cout << "-1";

	return EXIT_SUCCESS;
}