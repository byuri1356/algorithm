#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

bool remain[402];
int N, M, K, cnt, ans = -1;
int _map[21][21][2];
int pos[402][3];
int priority[402][5][5];
int dx[5] = { 0, -1, 1, 0, 0 }, dy[5] = { 0, 0, 0, -1, 1 };

//냄새로 겹치는지 확인
inline void setSmell(int turn, int num) {
	int cur_x = pos[num][1];
	int cur_y = pos[num][2];
	int mx = _map[cur_x][cur_y][0];
	if (_map[cur_x][cur_y][0] == num || _map[cur_x][cur_y][0] == 0 || _map[cur_x][cur_y][1] + turn > 0) {
		_map[cur_x][cur_y][0] = num;
		_map[cur_x][cur_y][1] = -turn - K;
	}
	else {
		cnt--;
		remain[num] = false;
	}

	if (cnt == 1) ans = turn;
}

//위치 이동
inline void setPos(int turn, int num, int dir) {
	int cur_d = pos[num][0];
	int cur_x = pos[num][1];
	int cur_y = pos[num][2];
	int next_x = cur_x + dx[priority[num][cur_d][dir]];
	int next_y = cur_y + dy[priority[num][cur_d][dir]];

	pos[num][0] = priority[num][cur_d][dir];
	pos[num][1] = next_x;
	pos[num][2] = next_y;

	//cout << "num: " << num << " x: " << pos[num][1] << " , y: " << pos[num][2] << "\n";
}

inline bool isValid(int x, int y) {
	return (x >= 0 && x < N&& y >= 0 && y < N);
}

int main() {
	fastio;

	//입력받는 부분
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> _map[i][j][0];
			if (_map[i][j][0]) {
				_map[i][j][1] = -K;
				pos[_map[i][j][0]][1] = i;
				pos[_map[i][j][0]][2] = j;
			}
		}
	}

	cnt = M;
	for (int i = 1; i <= M; ++i) {
		cin >> pos[i][0];
		remain[i] = true;
	}

	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= 4; ++j) {
			for (int k = 1; k <= 4; ++k) {
				cin >> priority[i][j][k];
			}
		}
	}

	//상어 이동 부분
	for (int i = 1; i <= 1000; ++i) {
		if (ans != -1) break;

		//cout << "Turn : " << i << "\n";

		for (int j = 1; j <= M; ++j) {
			if (remain[j]) {

				int next_p = 0;
				for (int k = 1; k <= 4; ++k) {
					int cur_d = pos[j][0];
					int cur_x = pos[j][1];
					int cur_y = pos[j][2];
					int next_x = cur_x + dx[priority[j][cur_d][k]];
					int next_y = cur_y + dy[priority[j][cur_d][k]];

					if (isValid(next_x, next_y)) {
						if (_map[next_x][next_y][1] + i > 0) {
							next_p = k;
							break;
						}
						else if (_map[next_x][next_y][0] == j && !next_p) next_p = k;
					}
				}

				setPos(i, j, next_p);
			}

		}

		for (int j = 1; j <= M; ++j) {
			if (remain[j]) {
				setSmell(i, j);
				if (ans != -1) break;
			}
		}
	}

	cout << ans;

	return EXIT_SUCCESS;
}