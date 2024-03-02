#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int t, idx, n, m, ans, sccCnt, sccVst[100'001], scc[100'001];
vector<int> adj[100'001], st, sccd;

int sol(int cur) {
	int res = sccVst[cur] = ++idx;
	st.push_back(cur);

	for (int& next : adj[cur]) {
		if (!sccVst[next]) res = min(res, sol(next));
		else if (!scc[next]) res = min(res, sccVst[next]);
	}

	if (sccVst[cur] == res) {
		++sccCnt;
		int top;
		do {
			top = st.back();
			st.pop_back();
			scc[top] = sccCnt;
		} while (top != cur);
	}

	return res;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> t;
	while (t--) {
		ans = 0, idx = 0, sccCnt = 0;
		memset(sccVst, 0, sizeof sccVst);
		memset(scc, 0, sizeof scc);
		sccd.clear();
		st.clear();
		for (int i = 0; i < 100'001; ++i) adj[i].clear();

		cin >> n >> m;
		for (int i = 0; i < m; ++i) {
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
		}

		for (int i = 1; i <= n; ++i) if (!sccVst[i]) sol(i);

		sccd.resize(sccCnt + 1);
		for (int i = 1; i <= n; ++i) for (int& j : adj[i]) if (scc[i] != scc[j]) sccd[scc[j]]++;
		for (int i = 1; i <= sccCnt; ++i) if (!sccd[i]) ans++;

		cout << ans << "\n";
	}

	return 0;
}