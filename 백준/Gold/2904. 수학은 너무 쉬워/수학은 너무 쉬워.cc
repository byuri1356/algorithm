#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

int arr[100], ans = 1, cnt;
vector<pair<int, int>> fact[100], total;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
deque<pair<int, int>> fin;

int main() {
	fastio;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		for (int j = 2; j * j <= arr[i]; ++j) {
			int cnt = 0;
			while (arr[i] % j == 0) {
				arr[i] /= j;
				cnt++;
			}

			if (cnt) {
				fact[i].push_back({ j, cnt });
				pq.push({ j, cnt });
			}
		}

		if (arr[i] > 1) {
			fact[i].push_back({ arr[i], 1 });
			pq.push({ arr[i], 1 });
		}
	}

	int pivot = 0, square = 0;
	while (!pq.empty()) {
		if (pq.top().first == pivot) {
			square += pq.top().second;
			pq.pop();
		}
		else {
			if(square / N) fin.push_back({ pivot, square / N });
			pivot = pq.top().first;
			square = pq.top().second;
			pq.pop();
		}
	}

	if (square / N) fin.push_back({ pivot, square / N });
	
	for (auto iter : fin) {
		ans *= pow(iter.first, iter.second);
	}

	for (auto iter : fin) {
		for (int i = 0; i < N; ++i) {
			bool tk = false;
			for (auto _iter : fact[i]) {
				if (iter.first == _iter.first) {
					tk = true;
					if (_iter.second < iter.second) {
						cnt = cnt + iter.second - _iter.second;
					}
					break;
				}
				else if (iter.first < _iter.first) break;
			}
			if (!tk) cnt += iter.second;
		}
	}

	cout << ans << " " << cnt;

	return EXIT_SUCCESS;
}