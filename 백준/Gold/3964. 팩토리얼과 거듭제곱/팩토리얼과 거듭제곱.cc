#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT64_MAX
using namespace std;
using int64 = int64_t;

int64 getMultiplier(int64 number, int64 divisor) {
	int64 cnt = 0;
	while (number % divisor == 0) {
		cnt++;
		number /= divisor;
	}
	return cnt;
}

int64 getFactMul(int64 factorial, int64 divisor) {
	int64 weight = 0;
	while (factorial >= divisor) {
		weight += factorial / divisor;
		factorial /= divisor;
	}
	return weight;
}

int main() {
	fastio;

	int64 T;
	cin >> T;

	for (int64 t = 0; t < T; ++t) {
		int64 n, k, n_mul, k_mul;
		int64 min_num = INF;

		cin >> n >> k;

		for (int64 i = 2; i * i <= k; ++i) {
			if (k % i == 0) {
				k_mul = getMultiplier(k, i);
				n_mul = getFactMul(n, i);
				min_num = min(n_mul / k_mul, min_num);
				while (k % i == 0)
					k /= i;
			} 
		}

		if (k != 1) {
			k_mul = 1;
			n_mul = getFactMul(n, k);
			min_num = min(n_mul / k_mul, min_num);
		}

		cout << min_num << "\n";
	}

	return EXIT_SUCCESS;
}