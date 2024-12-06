#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int T, dg[501], ra[501];

int main() {

	cin >> T;
	while (T--) {
		int n, m, a, b; cin >> n;
		priority_queue<pair<int, int>> pq;
		vector<int> ans;
		for (int i = 1; i <= n; ++i) cin >> a, ra[a] = i, dg[a] = i - 1;
		cin >> m;
		while (m--) {
			cin >> a >> b;
			if (ra[a] < ra[b]) ++dg[a], --dg[b];
			else --dg[a], ++dg[b];
		}
		for (int i = 1; i <= n; ++i) pq.push({ -dg[i], i });
		for (int i = 1; i <= n; ++i) {
			auto [a, b] = pq.top(); pq.pop();
			if (-a + 1 == i) ans.push_back(b);
		}
		if (ans.size() == n) {
			for (auto& nn : ans) cout << nn << " ";
		}
		else {
			cout << "IMPOSSIBLE";
		}
		cout << "\n";
	}

	return 0;
}