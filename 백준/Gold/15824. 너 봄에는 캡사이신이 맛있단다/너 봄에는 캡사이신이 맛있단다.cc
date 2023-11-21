#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

int64 div_n = 1'000'000'007;

inline int64 splitNsquare(int64 num, int64 po) {
	if (!po) return 1;
	else if (po == 1) return num % div_n;

	int64 half_po = po / 2;
	int64 double_num = (num % div_n) * (num % div_n) % div_n;

	if (po % 2 == 0) {
		return splitNsquare(double_num, half_po) % div_n;
	}
	else {
		return (splitNsquare(double_num, half_po) % div_n) * (num % div_n) % div_n;
	}
}

int main() {
	fastio;



	vector<int64> v;

	int64 N;
	cin >> N;
	int64 sum = 0, cnt = 0;

	for (int64 i = 0; i < N; ++i) {
		int64 a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int64 i = 0; i < N / 2; ++i) {
		sum += ((v[N - 1 - i] - v[i]) % div_n) * (((splitNsquare(2, N - 1 - 2 * i) - 1) % div_n) * (splitNsquare(2, i) % div_n) % div_n) % div_n;
		sum %= div_n;
	}


	cout << sum % div_n;

	return EXIT_SUCCESS;
}