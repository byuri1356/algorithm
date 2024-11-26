#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
using ll = long long;

int T, idx, iidx;
vector<vector<int>> adj;
vector<int> vst, sccNum, sccDeg;
stack<int> sk;

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
			if (tn == cn) break;
		}
	}

	return mn;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while(T--) {
		int n, m; cin >> n >> m;
		adj.resize(n);
		vst.resize(n);
		sccNum.resize(n);
		for (int i = 0; i < m; ++i) {
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
		}

		for (int i = 0; i < n; ++i) {
			if (!vst[i]) scc(i);
		}

		sccDeg.resize(iidx + 1);

		for (int i = 0; i < n; ++i) {
			for (auto& j : adj[i]) {
				if (sccNum[i] != sccNum[j]) sccDeg[sccNum[j]]++;
			}
		}

		int pv = -1;
		for (int i = 1; i < sccDeg.size(); ++i) {
			if (!sccDeg[i]) {
				if (pv == -1) pv = i;
				else {
					pv = -100;
					break;
				}
			}
		}

		vector<int> ans;

		if (pv == -100) cout << "Confused" << "\n";
		else {
			for (int i = 0; i < n; ++i) {
				if (sccNum[i] == pv) ans.push_back(i);
			}

			sort(ans.begin(), ans.end());
		}
		
		for (auto& i : ans) {
			cout << i << "\n";
		}

		cout << "\n";

		idx = 0;
		iidx = 0;
		adj.clear();
		vst.clear();
		sccNum.clear();
		sccDeg.clear();
	}

	return 0;
}