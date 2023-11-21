#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

inline int find(vector<int>& parent, int a) {
	if (parent[a] == a) return a;
	return find(parent, parent[a]);
}

inline void mg(vector<int>& parent, int a, int b) {
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {

	fastio;

	while (1) {
		int N, M, K, blue = 0, red = 0;
		cin >> N >> M >> K;

		if (!(N || M || K)) break;

		vector<int> bParent(N + 1), rParent(N + 1);
		vector<tuple<int, int, int>> bAdj, rAdj;

		for (int i = 1; i <= N; ++i) {
			bParent[i] = rParent[i] = i;
		}

		while (M--) {
			char a;
			int b, c;
			cin >> a >> b >> c;

			if (a == 'B') {
				bAdj.push_back({ 0, b, c });
				rAdj.push_back({ 1, b, c });
			}
			else {
				bAdj.push_back({ 1, b, c });
				rAdj.push_back({ 0, b, c });
			}
		}

		sort(bAdj.begin(), bAdj.end());
		sort(rAdj.begin(), rAdj.end());

		for (auto& it : bAdj) {
			int st = find(bParent, get<1>(it));
			int ed = find(bParent, get<2>(it));

			if (st != ed) {
				if (get<0>(it) == 0) blue++;
				mg(bParent, st, ed);
			}
		}

		for (auto& it : rAdj) {
			int st = find(rParent, get<1>(it));
			int ed = find(rParent, get<2>(it));

			if (st != ed) {
				red += get<0>(it);
				mg(rParent, st, ed);
			}
		}

		if (red <= K && K <= blue) {
			cout << "1" << "\n";
		}
		else cout << "0" << "\n";
	}

	return EXIT_SUCCESS;
}