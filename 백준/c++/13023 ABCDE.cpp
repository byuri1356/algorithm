#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool token;
int64 _visit[2000], st;
vector<int64> v[2000];

inline void DFS(int64 vertex, int64 dep) {
	if (dep == 4) {
		token = true;
		return;
	}
	if (token) return;
	for (auto iter : v[vertex]) {
		if (_visit[iter] != st) {
			_visit[iter] = st;
			DFS(iter, dep + 1);
			_visit[iter] = -1;
			if (token) return;
		}
	}
}

int main() {
	fastio;

	fill_n(_visit, 2000, -1);
	int64 N, T;
	cin >> N >> T;
	for (int64 i = 0; i < T; ++i) {
		int64 a, b;
		cin >> a >> b;
		v[a].push_back(b); 
		v[b].push_back(a);
	}

	token = false;
	for (int64 i = 0; i < T; ++i) {
		if (token) break;
		st = i;
		_visit[i] = st;
		DFS(i, 0);
	}
	
	if (token) cout << 1;
	else cout << 0;

	return EXIT_SUCCESS;
}