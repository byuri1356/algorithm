#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int n, m, idx, iidx;
vector<vector<int>> adj;
vector<int> sccNum;
vector<int> vst;
stack<int> sk;

int scc(int cn) {
	int mn = vst[cn] = ++idx;
	sk.push(cn);
	for (auto& nn : adj[cn]) {
		if (!vst[nn]) mn = min(mn, scc(nn));
		else if (!sccNum[nn]) mn = min(mn, vst[nn]);
	}
	if (mn == vst[cn]) {
		++iidx;
		while (1) {
			int tn = sk.top();
			sk.pop();
			sccNum[tn] = iidx;
			if (tn == cn) break;
		}
	}

	return mn;
}

inline int ff(int a) {
	if (a < 0) return -a + n;
	return a;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	while (cin >> n >> m) {
		adj.resize(2 * n + 1);
		sccNum.resize(2 * n + 1);
		vst.resize(2 * n + 1);
		adj[1 + n].push_back(1);
		while (m--) {
			int a, b; cin >> a >> b;
			adj[ff(-a)].push_back(ff(b));
			adj[ff(-b)].push_back(ff(a));
		}

		for (int i = 1; i <= n; ++i) if (!vst[i]) scc(i);

		string ans = "yes";
		for (int i = 1; i <= n; ++i) {
			if (sccNum[i] == sccNum[i + n]) {
				ans = "no";
				break;
			}
		}
		
		cout << ans << "\n";

		adj.clear();
		sccNum.clear();
		vst.clear();
		idx = 0;
		iidx = 0;
	}

	return 0;
}