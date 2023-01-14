#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

deque<int64> dq;
priority_queue<int64, vector<int64>, greater<int64>> in_pq, out_pq;

int main() {
	fastio;

	int64 N, L;
	cin >> N >> L;

	for (int64 i = 0; i < N; ++i) {
		int64 a;
		cin >> a;
		dq.push_back(a);
	}

	for (int64 i = 0; i < N; ++i) {
		in_pq.push(dq[i]);
		int64 a = i - L + 1;
		if (a > 0) {
			out_pq.push(dq[a - 1]);
			int64 j = out_pq.size();
			for (; j > 0; --j) {
				if (in_pq.top() == out_pq.top()) {
					in_pq.pop();
					out_pq.pop();
				}
				else break;
			}
		}

		cout << in_pq.top() << ' ';

	}

	return EXIT_SUCCESS;
}