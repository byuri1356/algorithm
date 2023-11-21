#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

vector<pair<int64, int64>> v;
priority_queue<pair<int64, int64>, vector<pair<int64, int64>>, greater<pair<int64, int64>>> pq;

int main() {
	fastio;

	int64 N, a, b;

	cin >> N;

	for (int64 i = 0; i < N; ++i) {
		cin >> a >> b;
		pq.push({ a,b });
	}

	int64 A = pq.top().first;
	int64 B = pq.top().second;
	pq.pop();

	while (!pq.empty()) {

		if (B < pq.top().first) {
			v.push_back({ A, B });
			A = pq.top().first;
			B = pq.top().second;
			pq.pop();
		}
		else if (A<pq.top().first && B<= pq.top().second) {
			B = pq.top().second;
			pq.pop();
		}
		else if (A>= pq.top().first && B<= pq.top().second) {
			A = pq.top().first;
			B = pq.top().second;
			pq.pop();
		}
		else if (A>= pq.top().first && B>pq.top().second) {
			A = pq.top().first;
			pq.pop();
		}
		else {
			pq.pop();
		}

	}
	
	v.push_back({ A,B });

	int64 sum = 0;
	for (auto iter : v) {
		sum += iter.second - iter.first;
	}

	cout << sum;

	//checkLine();

	return EXIT_SUCCESS;
}