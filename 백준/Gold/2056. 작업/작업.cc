#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, ans, cs[10001], tt[10001], dg[10001];
vector<int> adj[10001];
queue<int> q;

int main() {

	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		int a, b; cin >> cs[i] >> a, tt[i] = cs[i];
		while (a--) cin >> b, adj[b].push_back(i), ++dg[i];
	}

	for (int i = 1; i <= N; ++i) if (!dg[i]) q.push(i);

	while (!q.empty()) {
		int cn = q.front();
		q.pop();

		ans = max(ans, tt[cn]);
		for (auto& nn : adj[cn]) {
			--dg[nn];
			tt[nn] = max(tt[nn], cs[nn] + tt[cn]);
			if (!dg[nn]) q.push(nn);
		}
	}

	cout << ans;

	return 0;
}