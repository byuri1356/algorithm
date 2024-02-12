#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

ll n, k, modNum[16], modDigit[51] = { 1, }, dp[1 << 15][101], bunmo = 1, bunza;
string s[16];

ll sol(int bt, int pv) {

	ll& ref = dp[bt][pv];
	if (ref != -1) return ref;

	if ((1 << n) - 1 == bt) return ref = pv ? 0 : 1;

	ref = 0;

	for (int i = 0; i < n; ++i) {
		if ((bt & 1 << i) == 0) ref += sol(bt | 1 << i, (pv * modDigit[s[i].size()] + modNum[i]) % k);
	}

	return ref;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int getMod(string& s) {
	int tmp = 0;
	for (int i = 0; i < s.size(); ++i) {
		tmp *= 10;
		tmp += s[i] - '0';
		tmp %= k;
	}
	return tmp;
}

int main() {

	fastio;

	memset(dp, -1, sizeof dp);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> s[i], bunmo *= (i + 1);
	cin >> k;

	for (int i = 1; i < 51; ++i) modDigit[i] = modDigit[i - 1] * 10 % k;
	for (int i = 0; i < n; ++i) modNum[i] = getMod(s[i]);

	bunza =  sol(0, 0);

	ll divNum = gcd(bunmo, bunza);

	if (bunza == 0) cout << "0/1";
	else cout << bunza / divNum << "/" << bunmo / divNum;

	//cout << "!";
}