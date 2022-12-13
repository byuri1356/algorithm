#include<iostream>

using namespace std;
using int64 = int64_t;

typedef struct {
	int x;
	int y;
}dot;

dot d[90'000];
int64 arr[300][300];

void init() {
	for (int64 i = 1, cnt = 1; i < 300; ++i) {
		for (int64 j = 0; j < i; ++j) {
			d[cnt].x = i - j;
			d[cnt].y = 1 + j;
			arr[i - j][1 + j] = cnt;
			cnt++;
		}
	}
}

int main() {
	int64 T;
	cin >> T;

	init();

	for (int64 t = 1; t <= T; ++t) {
		int64 a, b, x, y;
		cin >> a >> b;
		x = d[a].x + d[b].x;
		y = d[a].y + d[b].y;

		cout << '#' << t << ' ' << arr[x][y] << "\n";

	}


	return EXIT_SUCCESS;
}