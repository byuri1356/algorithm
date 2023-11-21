#include<iostream>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;

int N, M, ret;
vector<int> fT, money, in, out;
vector<vector<int>> adj;

void dfs(int cur) {
	in[cur] = ++ret;
	for (int it : adj[cur]) {
		dfs(it);
	}
	out[cur] = ret;
}

int find(int i) {
	int sum = 0;
	while (i > 0) {
		sum += fT[i];
		i -= i & -i;
	}
	return sum;
}

void update(int i, int dif) {
	while (i <= N) {
		fT[i] += dif;
		i += i & -i;
	}
}

int main() {

	fastio;

	cin >> N >> M;

	fT.resize(N + 1), money.resize(N + 1), in.resize(N + 1), out.resize(N + 1), adj.resize(N + 1);
	cin >> money[1];

	for (int i = 2; i <= N; ++i) {
		int a;
		cin >> money[i] >> a;

		adj[a].push_back(i);
	}

	dfs(1);

	for (int i = 1; i <= N; ++i) {
		update(in[i], money[i]);
		update(in[i] + 1, -money[i]);
	}

	while (M--) {
		int a, b;
		char op;
		cin >> op >> a;

		switch (op) {
		case 'p':
			cin >> b;
			update(in[a] + 1, b);
			update(out[a] + 1, -b);
			break;
		case 'u':
			cout<<find(in[a])<<"\n";
		}
	}

	return EXIT_SUCCESS;
}