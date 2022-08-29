#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using int64 = int64_t;

bool arr_visit[100'001];
int64 arr_count[100'001];
queue<int64> q;

void inline Solve(int64 N, int64 M) {
	q.push(N);
	int64 pos;
	while (!q.empty()) {
		pos = q.front();
		q.pop();

		if (pos + 1 <= 100'000) {
			if (!arr_visit[pos + 1]) {
				arr_visit[pos + 1] = true;
				q.push(pos + 1);
				arr_count[pos + 1] = arr_count[pos] + 1;
				if (pos + 1 == M) {
					return;
				}
			}
		}
		if (pos - 1 >= 0) {
			if (!arr_visit[pos - 1]) {
				arr_visit[pos - 1] = true;
				q.push(pos - 1);
				arr_count[pos - 1] = arr_count[pos] + 1;
				if (pos - 1 == M) {
					return;
				}
			}
		}
		if (pos * 2 <= 100'000) {
			if (!arr_visit[pos * 2]) {
				arr_visit[pos * 2] = true;
				q.push(pos * 2);
				arr_count[pos * 2] = arr_count[pos] + 1;
				if (pos * 2 == M) {
					return;
				}
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	arr_visit[N] = true;
	arr_count[N] = 0;

	Solve(N, M);

	cout << arr_count[M];

	return EXIT_SUCCESS;
}