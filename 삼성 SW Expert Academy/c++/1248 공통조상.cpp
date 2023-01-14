#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

typedef struct tree{
	int64 level = 1, parent_node = 1, size = 1;
	vector<int64> v;
}tree;

int main() {
	fastio;

	int64 T;
	cin >> T;

	for (int64 t = 1; t <= T; ++t) {
		int64 V, E, a, b, X, Y;
		cin >> V >> E >> a >> b;

		tree tr[10001];
		for (int64 i = 0; i < E; ++i) {
			cin >> X >> Y;
			int64 x = X, y = Y;

			tr[x].v.push_back(y);
			tr[y].parent_node = x;
			tr[y].level = tr[x].level + 1;
		
			int64 c = tr[x].level;
			for (int64 j = 0; j < c; ++j) {
				tr[x].size += tr[y].size;
				x = tr[x].parent_node;
			}

			x = X; y = Y;
			queue<int64> q;
			
			for (auto iter : tr[y].v) {
				q.push(iter);
			}

			while (!q.empty()) {
				int64 cur = q.front();
				q.pop();
				tr[cur].level = tr[tr[cur].parent_node].level + 1;

				for (auto iter : tr[cur].v) {
					q.push(iter);
				}
			}
		}

		int64 uplevel = abs(tr[a].level - tr[b].level);
		for (int64 i = 0; i < uplevel; ++i) {
			if (tr[a].level > tr[b].level) {
				a = tr[a].parent_node;
			}
			else {
				b = tr[b].parent_node;
			}
		}

		while (a != b) {
			a = tr[a].parent_node;
			b = tr[b].parent_node;
		}

		cout << "#" << t << ' ' << a << ' ' << tr[a].size << "\n";
	}

	return EXIT_SUCCESS;
}