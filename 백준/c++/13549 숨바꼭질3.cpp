#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using int64 = int64_t;

bool arr_visit[100'002];
int64 arr_count[100'002];
queue<int64> q;

void inline Solve(int64 N, int64 M) {
	q.push(N);
	int64 pos;
	while (!q.empty()) {
		pos = q.front();
		q.pop();

		for (int64 i = 1; ;) {
			if (pos == 0) {
				break;
			}
			else if ((pos << i) <= 100'000) {
				if (!arr_visit[pos << i]) {
					arr_visit[pos << i] = true;
					q.push(pos << i);
					arr_count[pos << i] = arr_count[pos];
					if ((pos << i) == M) {
						return;
					}
				}
			}
			else {
				break;
			}
			++i;
		}
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