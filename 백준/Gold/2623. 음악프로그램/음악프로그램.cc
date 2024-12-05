#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, dg[1001];
vector<int> adj[1001], ans;
queue<int> q;

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	while (M--) {
		int a, b; cin >> a;
		vector<int> tmp;
		while (a--) cin >> b, tmp.push_back(b);

		for (int i = 0; i < tmp.size() - 1; ++i) {
			int c = tmp[i], d = tmp[i + 1];
			adj[c].push_back(d);
			++dg[d];
		}
	}

	for (int i = 1; i <= N; ++i) if (!dg[i]) q.push(i);



	while (!q.empty()) {
		int cn = q.front();
		ans.push_back(cn);
		q.pop();

		for (auto& nn : adj[cn]) {
			--dg[nn];
			if (!dg[nn]) q.push(nn);
		}
	}

	if (ans.size() == N) for (auto& i : ans) cout << i << "\n";
	else cout << 0;

	return 0;
}