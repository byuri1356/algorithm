#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

priority_queue<int> q;
vector<pair<int, int>> v;
int64 arr[200'001];
bool _visit[200'001];

inline void Solve(int T) {
	int t = T;
	for (int i = 1; i <= T;) {
		if (arr[i] < 2) {
			q.push(i);
			_visit[i] = true;
		}
		++i;
	}

	while (!q.empty()) {
		--t;
		int x = q.top();
		q.pop();
		if (--arr[v[x].first] < 2) {
			if (!_visit[v[x].first]) {
				q.push(v[x].first);
				_visit[v[x].first] = true;
			}
		}
		if (--arr[v[x].second] < 2) {
			if (!_visit[v[x].second]) {
				q.push(v[x].second);
				_visit[v[x].second] = true;
			}
		}
	}
	cout << t << "\n";
	for (int i = 1; i <= T;) {
		if (arr[i] == 2)
			cout << i << ' ';
		++i;
	}
}

int main() {
	fastio;
	v.push_back({ 0,0 });
	int T, a, b;
	cin >> T;
	for (int i = 1; i <= T;) {
		cin >> a >> b;
		arr[a]++; arr[b]++;
		v.push_back({ a,b });
		++i;
	}
	Solve(T);

	return EXIT_SUCCESS;
}