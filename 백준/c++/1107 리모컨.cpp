#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool btn[10];
int64 Ans;

inline int64 split(int64 res, int64 M, int64 digit) {
	int64 arr[6], base, N = M;
	base = pow(10, digit-1);
	for (int64 i = base, _count = 0; i > 0; i /= 10) {
		arr[_count] = N / i;
		N %= i;
		_count++;
	}
	for (int64 i = 0; i < digit; ++i) {
		if (btn[arr[i]]) return INF;
	}
	
	if (res > M) return res - M + digit;
	else return M - res + digit;
}

int main() {
	fastio;

	int64 N, M, B;
	cin >> N >> M;
	for (int64 i = 0; i < M; ++i) {
		cin >> B;
		btn[B] = true;
	}

	Ans = 100 > N ? 100 - N : N - 100;
	for (int64 i = 0; i < 1'000'001; ++i) {
		if (i < 10) {
			Ans = min(split(N, i, 1), Ans);
		}
		else if (i < 100) {
			Ans = min(split(N, i, 2), Ans);
		}
		else if (i < 1'000) {
			Ans = min(split(N, i, 3), Ans);
		}
		else if (i < 10'000) {
			Ans = min(split(N, i, 4), Ans);
		}
		else if (i < 100'000) {
			Ans = min(split(N, i, 5), Ans);
		}
		else {
			Ans = min(split(N, i, 6), Ans);
		}
	}
	
	cout << Ans;

	return EXIT_SUCCESS;
}