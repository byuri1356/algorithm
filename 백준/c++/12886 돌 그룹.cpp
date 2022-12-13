#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool x_visit[1501], y_visit[1501];
int64 arr[3], goal;
queue<tuple<int64, int64, int64>> q;

inline void Solve() {
	q.push(make_tuple(arr[0], arr[1], arr[2]));
	while (!q.empty()) {
		int64 x = get<0>(q.front());
		int64 y = get<1>(q.front());
		int64 z = get<2>(q.front());
		q.pop();

		if ((x == y) && (x == z)) {
			cout << 1;
			return;
		}
		else if (x != goal) {
			if (x > y) {
				if (!x_visit[x - y]) {
					x_visit[x - y] = true;
					q.push(make_tuple(x - y, y + y, z));
				}
			}
			else if (x < y) {
				if (!x_visit[x + x]) {
					x_visit[x + x] = true;
					q.push(make_tuple(x + x, y - x, z));
				}
			}
			if (x > z) {
				if (!x_visit[x - z]) {
					x_visit[x - z] = true;
					q.push(make_tuple(x - z, y, z + z));
				}
			}
			else if (x < z) {
				if (!x_visit[x + x]) {
					x_visit[x + x] = true;
					q.push(make_tuple(x + x, y, z - x));
				}
			}
		}
		else {
			if (y > z) {
				if (!y_visit[y - z]) {
					y_visit[y - z] = true;
					q.push(make_tuple(x, y - z, z + z));
				}
			}
			else if (y < z) {
				if (!y_visit[y + y]) {
					y_visit[y + y] = true;
					q.push(make_tuple(x, y + y, z - y));
				}
			}
		}
	}
	cout << 0;
}

int main() {
	fastio;

	cin >> arr[0] >> arr[1] >> arr[2];
	x_visit[arr[0]] = true; 
	goal = arr[0] + arr[1] + arr[2];

	if (goal % 3) cout << 0;
	else {
		goal /= 3;
		Solve();
	}

	return EXIT_SUCCESS;
}