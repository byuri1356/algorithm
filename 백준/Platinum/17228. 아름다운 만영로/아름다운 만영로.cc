#include<iostream>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;
using vvp = vector<vector<pair<int, char>>>;

string s;
int64 key, ans;

const int64 PV = 5831;
const int64 MOD[2] = { (int64)1e9 + 7, (int64)1e9 + 9 };

vvp adj;
vector<char> st;
vector<int64> down(2, 1);

void dfs(int cur, int dep, int64 up0, int64 up1) {


	if (dep >= s.length()) {
		if ((up0 << 32 | up1) == key) ans++;

		for (auto& it : adj[cur]) {
			int64 up[2] = { up0, up1 };
			for (int i = 0; i < 2; ++i) {
				up[i] = (up[i] - st[dep - s.length()] * down[i] % MOD[i] + MOD[i]) % MOD[i];
				up[i] = (up[i] * PV + it.second) % MOD[i];
			}

			st.push_back(it.second);
			dfs(it.first, dep + 1, up[0], up[1]);
			st.pop_back();
		}
	}
	else {
		for (auto& it : adj[cur]) {
			int64 up[2] = { up0, up1 };
			for (int i = 0; i < 2; ++i) {
				up[i] = (up[i] * PV + it.second) % MOD[i];
			}

			st.push_back(it.second);
			dfs(it.first, dep + 1, up[0], up[1]);
			st.pop_back();
		}
	}
}

void makeKey() {
	int64 up[2] = { s[0], s[0] };

	for (int i = 1; i < s.length(); ++i) {
		for (int j = 0; j < 2; ++j) {
			up[j] = (up[j] * PV + s[i]) % MOD[j];
			down[j] = down[j] * PV % MOD[j];
		}
	}

	key = up[0] << 32 | up[1];
}

int main() {

	fastio;

	int N;
	cin >> N;

	adj.resize(N + 1);

	N--;
	while (N--) {
		int a, b;
		char c;
		cin >> a >> b >> c;

		adj[a].push_back({ b, c });
	}

	cin >> s;
	makeKey();

	for (auto& it : adj[1]) {
		st.push_back(it.second);
		dfs(it.first, 1, it.second, it.second);
		st.pop_back();
	}
	 
	cout << ans;

	return EXIT_SUCCESS;
}