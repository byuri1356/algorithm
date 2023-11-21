#include<bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int parent[51];
bool flag[51];

void mg(int a, int b) {
	if (a < b) {
		parent[b] = a;
		flag[a] |= flag[b];
	}
	else {
		parent[a] = b;
		flag[b] |= flag[a];
	}
}

int fd(int n) {
	if (n == parent[n]) return n;
	return fd(parent[n]);
}

int main() {

	fastio;

	int N, M, a, b, ans = 0; cin >> N >> M;

	iota(parent, parent + N + 1, 0);

	cin >> a;
	while (a--) cin >> b, flag[b] = true;
	
	vector<int> tt(M);

	while (M--) {
		cin >> a >> tt[M]; a--;
		while (a--) {
			cin >> b;

			int pa = fd(tt[M]);
			int pb = fd(b);

			mg(pa, pb);
		}
	}
	
	for (auto& it : tt) if (!flag[fd(it)]) ans++;

	cout << ans;
}