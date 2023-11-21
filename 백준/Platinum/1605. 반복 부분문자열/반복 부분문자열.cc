#include<iostream>
#include<string>
#include<unordered_set>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int N, ans;
string s;
unordered_set<int64> us;
const int MOD[2] = { (int)1e9 + 7, (int)1e9 + 9 };
const int PV = 5381;

inline bool solve(int len) {
	us.clear();

	int64 hash[2] = { s[0], s[0] }, lb[2] = { 1, 1 };

	for (int i = 1; i < len; ++i) {
		for (int j = 0; j < 2; ++j) {
			hash[j] = (hash[j] * PV + s[i]) % MOD[j];
			lb[j] = lb[j] * PV % MOD[j];
		}
	}

	us.insert(hash[0] << 32 | hash[1]);

	for (int i = len; i < N; ++i) {
		for (int j = 0; j < 2; ++j) {
			hash[j] = (hash[j] - lb[j] * s[i - len] % MOD[j] + MOD[j]) % MOD[j];
			hash[j] = (hash[j] * PV + s[i]) % MOD[j];
		}

		int64 key = hash[0] << 32 | hash[1];
		if (us.find(key) == us.end()) {
			us.insert(key);
		}
		else return true;
	}

	return false;

}

int main() {

	fastio;

	cin >> N;
	cin >> s;

	int start = 0, end = N;
	while (start <= end) {
		int mid = (start + end) >> 1;
		if (solve(mid)) {
			start = mid + 1;
			ans = mid;
		}
		else {
			end = mid - 1;
		}
	}

	cout << ans;

	return EXIT_SUCCESS;
}