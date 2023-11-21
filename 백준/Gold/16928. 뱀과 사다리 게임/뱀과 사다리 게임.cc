#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using int64 = int64_t;

int64 ans;
int64 arr_map[1000] = {};
int64 arr_count[1000] = {};
bool arr_visit[1000];
queue<int64> q;

inline void init_map() {
	for (int64 i = 0; i < 101;) {
		arr_map[i] = i;
		++i;
	}
}

void inline Solve() {
	int64 vertex;
	q.push(1);
	while (!q.empty()) {
		vertex = q.front();
		q.pop();

		for (int64 i = 1; i <= 6;) {
			if (!arr_visit[arr_map[arr_map[vertex] + i]]) {
				q.push(arr_map[arr_map[vertex] + i]);
				arr_visit[arr_map[arr_map[vertex] + i]] = true;
				arr_count[arr_map[arr_map[vertex] + i]] = arr_count[vertex] + 1;
			}
			else if (arr_visit[arr_map[arr_map[vertex] + i]] &&(arr_count[arr_map[arr_map[vertex] + i]] > arr_count[vertex])) {
				q.push(arr_map[arr_map[vertex] + i]);
				arr_visit[arr_map[arr_map[vertex] + i]] = true;
				arr_count[arr_map[arr_map[vertex] + i]] = arr_count[vertex] + 1;
			}
			++i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	init_map();

	int64 N, M;
	int64 a, b;
	cin >> N >> M;
	for (int64 i = 0; i < N+M;) {
		cin >> a >> b;
		arr_map[a] = b;
		++i;
	}

	Solve();

	cout << arr_count[100];

	return EXIT_SUCCESS;
}