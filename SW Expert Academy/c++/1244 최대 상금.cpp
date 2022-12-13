#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;
using int64 = int64_t;

int64 num, ch, ans = 0;
deque<int64> dq;

inline void Solve(int64 cur, int64 remain) {
	if (remain == 0) {
		int64 sum = 0;
		for (int64 k = 0; k < dq.size(); ++k) {
			sum *= 10;
			sum += dq[k];
		}

		ans = max(ans, sum);
		return;
	}

	for (int64 i = cur; i < dq.size() - 1; ++i) {
		for (int64 j = i + 1; j < dq.size(); ++j) {
			int64 tmp = dq[i];
			dq[i] = dq[j];
			dq[j] = tmp;

			Solve(i, remain - 1);

			tmp = dq[i];
			dq[i] = dq[j];
			dq[j] = tmp;

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 C;
	cin >> C;
	for (int64 i = 1; i <= C; ++i) {

		cin >> num >> ch;

		while (num > 0) {
			dq.push_front(num % 10);
			num /= 10;
		}

		if (ch > dq.size()) ch = dq.size();

		Solve(0, ch);

		cout << '#' << i << ' ' << ans << "\n";
		dq.clear();
		ans = 0;
	}

	return EXIT_SUCCESS;
}