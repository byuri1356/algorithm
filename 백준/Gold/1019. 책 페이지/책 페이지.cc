#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;



int main() {
	fastio;

	int64 n = 0;
	string s;
	cin >> s;

	int64 arr[12], ans[10] = {};

	//19 -> 19
	for (int64 i = 1; i <= s.length(); ++i) {
		arr[i] = s[i - 1] - '0';
	}

	for (int64 i = s.length(); i > 0; --i) {
		n += arr[i] * pow(10, s.length() - i);
	}

	ans[0] -= pow(10, s.length() - 1);

	for (int64 i = s.length(); i > 0; --i) {
		int64 mod = pow(10, s.length() - i);
		for (int64 j = 0; j < 10; ++j) {
			if (arr[i] == j) {
				ans[j] += n % mod + 1;
				break;
			}
			else {
				ans[j] += mod;
			}
		}
	}

	for (int64 i = s.length(); i > 1; --i) {
		int64 div = pow(10, s.length() + 1 - i);
		for (int64 j = 0; j < 10; ++j) {
			ans[j] += n / div * (div / 10);
		}
		ans[0] -= div / 10;
	}

	for (int64 i = 0; i < 10; ++i) {
		cout << ans[i] << ' ';
	}

	return EXIT_SUCCESS;
}