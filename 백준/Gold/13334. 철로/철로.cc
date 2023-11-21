#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

priority_queue<pair< int64, int64>, vector<pair<int64, int64>>, greater<pair<int64, int64>>> bpq;
priority_queue<int64, vector<int64>, greater<int64>> apq;
int main() {
	fastio;

	int64 N, a, b, d, ans = 0;

	cin >> N;

	for (int64 i = 0; i < N; ++i) {
		cin >> a >> b;

		if (a < b) 	bpq.push({ b, a });
		else bpq.push({ a, b });

	}

	cin >> d;

	int64 i = bpq.size();
	for (; i>0; --i) {
		int64 B = bpq.top().first;
		int64 A = bpq.top().second;

		if (B - A <= d) {
			apq.push(A);

			int64 start = B - d;
			while (!apq.empty()) {
				if (apq.top() < start) apq.pop();
				else break;
			}

			int64 res = apq.size();
			ans = max(ans, res);
		}

		bpq.pop();
	}
		
	cout << ans;

	return EXIT_SUCCESS;
}