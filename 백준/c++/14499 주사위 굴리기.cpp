#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

typedef struct {
	int64 dice_bottom;
	int64 dice_top;
	int64 dice_east;
	int64 dice_west;
	int64 dice_south;
	int64 dice_north;
} p;

p dice;

int64 x, y, N, M, arr[20][20];

inline void changePos(int64 com) {
	int64 tmp_bottom = dice.dice_bottom;
	int64 tmp_top = dice.dice_top;
	int64 tmp_east = dice.dice_east;
	int64 tmp_west = dice.dice_west;
	int64 tmp_south = dice.dice_south;
	int64 tmp_north = dice.dice_north;

	if (com == 1) {
		y++;
		tmp_bottom = dice.dice_east;
		tmp_top = dice.dice_west;
		tmp_east = dice.dice_top;
		tmp_west = dice.dice_bottom;
	}
	else if (com == 2) {
		y--;
		tmp_bottom = dice.dice_west;
		tmp_top = dice.dice_east;
		tmp_east = dice.dice_bottom;
		tmp_west = dice.dice_top;
	}
	else if (com == 3) {
		x--;
		tmp_bottom = dice.dice_north;
		tmp_top = dice.dice_south;
		tmp_south = dice.dice_bottom;
		tmp_north = dice.dice_top;
	}
	else {
		x++;
		tmp_bottom = dice.dice_south;
		tmp_top = dice.dice_north;
		tmp_south = dice.dice_top;
		tmp_north = dice.dice_bottom;
	}

	dice.dice_bottom = tmp_bottom;
	dice.dice_top = tmp_top;
	dice.dice_east = tmp_east;
	dice.dice_west = tmp_west;
	dice.dice_south = tmp_south;
	dice.dice_north = tmp_north;
}

inline bool isvalid(int64 com) {
	if (com == 1) return ((x >= 0) && (x < N) && (y + 1 < M));
	else if (com == 2) return ((x >= 0) && (x < N) && (y - 1 >= 0));
	else if (com == 3) return ((x - 1 >= 0) && (y >= 0) && (y < M));
	else return ((x + 1 < N) && (y >= 0) && (y < M));
}

int main() {
	fastio;

	int64 K;
	cin >> N >> M >> x >> y >> K;
	
	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int64 i = 0; i < K; ++i) {
		int64 com;
		cin >> com;

		if (isvalid(com)) {
			changePos(com);
			if (!arr[x][y]) arr[x][y] = dice.dice_bottom;
			else {
				dice.dice_bottom = arr[x][y];
				arr[x][y] = 0;
			}
			cout << dice.dice_top << "\n";
		}
	}

	return EXIT_SUCCESS;
}