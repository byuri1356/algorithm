#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
using ll = long long;

int idx, iidx = 1;
int sccNum[20004];
int vcnt[20004];
stack<int> st;
vector<int> vec[20004];

int scc(int cv) {
	int minN = vcnt[cv] = ++idx;

	st.push(cv);

	for (int i = 0; i < vec[cv].size(); ++i) {
		int nv = vec[cv][i];

		if (!vcnt[nv]) minN = min(minN, scc(nv));
		else if (!sccNum[nv])minN = min(minN, vcnt[nv]);
	}

	if (minN == vcnt[cv]) {
		while(1) {
			int tp = st.top();
			st.pop();
			sccNum[tp] = iidx;
			if (tp == cv) break;
		}
		iidx++;
	}

	return minN;
}

inline int conv(int val, int pv) {
	if (val < 0) return -val + pv;
	return val;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		vec[conv(a, n)].push_back(conv(-b, n));
		vec[conv(b, n)].push_back(conv(-a, n));
	}

	for (int i = 1; i <= 2 * n; ++i) {
		if (!vcnt[i]) scc(i);
	}

	int flag = true;
	for (int i = 1; i <= n; ++i) {
		if (sccNum[i] == sccNum[i + n]) flag = false;
	}

	cout << flag;

	return 0;
}