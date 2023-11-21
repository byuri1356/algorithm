#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;
using pi = pair<int, int>;

vector<int> T;
vector<pi> LP;
priority_queue<int> pq;

int main() {

	fastio;

	int64 N, M, ans = 0;
	cin >> N >> M;

	LP.resize(N), T.resize(M);

	for (int i = 0; i < N; ++i) cin >> LP[i].first, cin >> LP[i].second;
	for (int i = 0; i < M; ++i) cin >> T[i];

	sort(LP.begin(), LP.end(), greater<pi>());
	sort(T.begin(), T.end(), greater<int>());

	ans += LP[0].second;

	for (int i = 0, cnt = 1; i < M - 1; ++i) {
		for (int j = 0; j < T[i]; ++j, ++cnt) {
			pq.push(LP[cnt].second);
		}

		ans += pq.top();
		pq.pop();
	}

	cout << ans;

	return EXIT_SUCCESS;
}