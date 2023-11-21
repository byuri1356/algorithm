#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

vector<int> A, B;
vector<pair<int, int>> AB;
priority_queue<int> pq;

int main() {

	fastio;

	int64 N, ans = 0;
	cin >> N;

	A.resize(N), B.resize(N), AB.resize(N);

	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) cin >> B[i];
	for (int i = 0; i < N; ++i) AB[i] = { B[i], A[i] };

	sort(AB.begin(), AB.end());

	ans += AB[0].second;

	for (int i = 1; i < N - 1; i += 2) {
		pq.push(AB[i].second);
		pq.push(AB[i + 1].second);

		ans += pq.top();
		pq.pop();
	}

	cout << ans;

	return EXIT_SUCCESS;
}