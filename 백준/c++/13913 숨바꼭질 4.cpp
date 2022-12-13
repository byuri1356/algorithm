#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 pre_num[100'001], _visit[100'001];
vector<int64> v;
queue<int64> q;

inline bool _valid(int64 N) {
	return (N >= 0 && N <= 100'000);
}

inline void BFS(int64 N, int64 K) {
	q.push(N);
	while (!q.empty()) {
		int64 _pos = q.front();
		int64 _plus = q.front() + 1;
		int64 _minus = q.front() - 1;
		int64 teleport = q.front() * 2;
		q.pop();

		if (_pos == K) return; 
		if (_valid(_plus) && !_visit[_plus]) {
			_visit[_plus] = _visit[_pos] + 1;
			pre_num[_plus] = _pos;
			q.push(_plus);
		}
		if (_valid(_minus) && !_visit[_minus]) {
			_visit[_minus] = _visit[_pos] + 1;
			pre_num[_minus] = _pos;
			q.push(_minus);
		}
		if (_valid(teleport) && !_visit[teleport]) {
			_visit[teleport] = _visit[_pos] + 1;
			pre_num[teleport] = _pos;
			q.push(teleport);
		}
	}
}

int main() {
	fastio;

	int64 N, K;
	cin >> N >> K;

	if (N == K) cout << 0 << "\n" << N;
	else {
		BFS(N, K);
		cout << _visit[K] << "\n";

		int64 k = K;
		while (pre_num[k] != N) {
			v.push_back(pre_num[k]);
			k = pre_num[k];
		}

		cout << N << ' ';
		for (int64 i = v.size() - 1; i >= 0; --i) {
			cout << v[i] << ' ';
		}
		cout << K;
	}

	return EXIT_SUCCESS;
}