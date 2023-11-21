#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;

int N, M, H;
int dep[100001];
int dp[17][100001];
vector<int> edge[100001];

inline int LCA(int a, int b) {

	if (dep[a] > dep[b]) {
		return LCA(dp[(int)log2(dep[a] - dep[b])][a], b);
	}
	else if (dep[a] < dep[b]) {
		return LCA(a, dp[(int)log2(dep[b] - dep[a])][b]);
	}
	else if (a != b) {
		for (int i = 1; i < H; ++i) {
			if (dp[i][a] == dp[i][b])
				return LCA(dp[i - 1][a], dp[i - 1][b]);
		}
	}

	return a;
}

inline void setTree(int p, int c) {
	dp[0][c] = p;
	dep[c] = dep[p] + 1;

	for (int i = 1; i < H; ++i) {
		dp[i][c] = dp[i - 1][dp[i - 1][c]];
	}

	for (auto& iter : edge[c]) {
		if (iter == p) continue;
		setTree(c, iter);
	}
}

int main() {

	fastio;

	cin >> N;

	H = (int)ceil(log2(N));

	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;

		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	setTree(1, 1);

	cin >> M;


	for (int i = 0; i < M; ++i) {

		int a, b, c, A, B;
		cin >> a >> b >> c;

		A = LCA(a, b);
		B = LCA(a, c);

		if (A == a && B == a) {
			cout << LCA(b, c) << "\n";
		}
		else if (A != a && B != a) {
			if (A == B) cout << LCA(b, c) << "\n";
			else if (A != 1 && B != 1) {
				if (dep[A] > dep[B]) cout << A << "\n";
				else cout << B << "\n";
			}
			else if (A != 1) cout << A << "\n";
			else if (B != 1) cout << B << "\n";
		}
		else {
			cout << a << "\n";
		}

	}

	return EXIT_SUCCESS;
}