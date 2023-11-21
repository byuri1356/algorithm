#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

int64 N, M, pre_num[32'001];
vector<int64> post_vec[32'001];
priority_queue<int64, vector<int64>, greater<int64>> pq;

int main() {
	fastio;

	cin >> N >> M;
	for (int64 i = 0; i < M; ++i) {
		int64 a, b;
		cin >> a >> b;

		pre_num[b]++;
		post_vec[a].push_back(b);
	}

	for (int64 i = 1; i <= N; ++i) {
		if (!pre_num[i]) pq.push(i);
	}

	while (!pq.empty()) {
		int64 cur = pq.top();
		
		pq.pop();
		cout << cur << ' ';

		for (auto iter : post_vec[cur]) {
			pre_num[iter]--;
			if (!pre_num[iter]) pq.push(iter);
		}
	}


	return EXIT_SUCCESS;
}