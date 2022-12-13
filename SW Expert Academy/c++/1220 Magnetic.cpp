#include<iostream>
#include<utility>
#include<queue>

using namespace std;
using int64 = int64_t;

int64 cnt = 0;
int64 arr[100][100];
queue<pair<int64, int64>> q;

void checkNS() {
	while (!q.empty()) {
		int64 x = q.front().first;
		int64 y = q.front().second;
		q.pop();

		for (int64 i = x - 1; i >= -1; --i) {
			if (i == -1) {
				arr[x][y] = 0;
				break;
			}
			else if (arr[i][y] == 1) {
				arr[x][y] = 0;
				arr[i + 1][y] = 2;
				cnt++;
				break;
			}
			else if (arr[i][y] == 2) {
				arr[x][y] = 0;
				arr[i + 1][y] = 2;
				break;
			}
		}

	}

}

int main() {
	for (int64 t = 1; t <= 10; ++t) {
		int64 N;
		cin >> N;

		for (int64 i = 0; i < 100; ++i) {
			for (int64 j = 0; j < 100; ++j) {
				cin >> arr[i][j];
				if (arr[i][j] == 2) {
					q.push({ i,j });
				}
			}
		}

		cnt = 0;
		checkNS();
		cout << '#' << t << ' ' << cnt << "\n";
	}


	return EXIT_SUCCESS;
}