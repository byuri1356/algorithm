#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, a, cs[501], tt[501], dg[501];
queue<int> que;
vector<int> adj[501];

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> cs[i], tt[i] = cs[i];
		while (cin >> a && a != -1) adj[a].push_back(i), dg[i]++;
	}

	for (int i = 1; i <= N; ++i) if (!dg[i]) que.push(i);

	while (!que.empty()) {
		int cn = que.front();
		que.pop();

		for (auto& nn : adj[cn]) {
			--dg[nn];
			tt[nn] = max(tt[nn], cs[nn] + tt[cn]);
			if (!dg[nn]) que.push(nn);
		}
	}

	for (int i = 1; i <= N; ++i) cout << tt[i] << "\n";

	return 0;
}