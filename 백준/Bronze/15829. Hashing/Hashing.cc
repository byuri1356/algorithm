#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;
constexpr ll MOD = 1234567891;



int main() {

	fastio;

	ll L, cnt = 1, ans = 0;
	cin >> L;

	while (L--) {
		char c;
		cin >> c;

		ans += cnt * (c - 'a' + 1);
		ans %= MOD;
		cnt *= 31;
		cnt %= MOD;
	}

	cout << ans;
}