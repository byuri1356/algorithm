#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

int n, idx, iidx;
int dist[100], vst[100], sccNum[100];
vector<int> adj[100];
stack<int> sk;
priority_queue<int> pq[100];

int scc(int cn) {
	int mn = vst[cn] = ++idx;
	sk.push(cn);
	for (auto& nn : adj[cn]) {
		if (!vst[nn]) mn = min(mn, scc(nn));
		else if (!sccNum[nn]) mn = min(mn, vst[nn]);
	}
	if (mn == vst[cn]) {
		iidx++;
		while (1) {
			int tn = sk.top();
			sk.pop();
			sccNum[tn] = iidx;
			pq[iidx].push(-dist[tn]);
			if (tn == cn) break;
		}
	}

	return mn;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> dist[i];

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		char a; cin >> a;
		if (a == '1') adj[i].push_back(j);
	}

	for (int i = 0; i < n; ++i) if (!vst[i]) scc(i);

	int ans = 0;
	for (int i = 1; i <= iidx; ++i) ans -= pq[i].top();

	cout << ans;
	return 0;
}