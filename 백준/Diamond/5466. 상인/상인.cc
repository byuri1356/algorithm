#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;
using vi = vector<int>;
using vp = vector<pair<int, int>>;
const int MAXN = 500001;

int N, U, D, S;
vector<int> upSeg(MAXN * 4, INT32_MIN / 2), dnSeg(MAXN * 4, INT32_MIN / 2);
vp vec[MAXN + 1];

int fd(vi& seg, int s, int e, int n, int l, int r) {
	if (r < s || e < l) return INT32_MIN;
	if (l <= s && e <= r) return seg[n];

	int h = (s + e) >> 1;

	return max(fd(seg, s, h, n * 2, l, r), fd(seg, h + 1, e, n * 2 + 1, l, r));
}

int ud(vi& seg, int s, int e, int n, int p, int sum) {
	if (p < s || e < p) return seg[n];
	if (p <= s && e <= p) return seg[n] = sum;

	int h = (s + e) >> 1;

	return seg[n] = max(ud(seg, s, h, n * 2, p, sum), ud(seg, h + 1, e, n * 2 + 1, p, sum));
}

void udSet(int pv, int sum) {
	ud(upSeg, 1, MAXN, 1, pv, sum - U * pv);
	ud(dnSeg, 1, MAXN, 1, pv, sum + D * pv);
}

int fdDP(int m) {
	return max(fd(upSeg, 1, MAXN, 1, m, MAXN) + U * m, fd(dnSeg, 1, MAXN, 1, 1, m) - D * m);
}

void dp(vp& p) {
	sort(p.begin(), p.end());

	vector<int> up(p.size()), dn(p.size());

	for (int i = 0; i < p.size(); ++i) {
		int mx = fdDP(p[i].first);
		up[i] = mx;
		dn[i] = mx;
	}

	for (int i = 0; i < p.size(); ++i) {
		if (i) dn[i] = max(dn[i], dn[i - 1] - (p[i].first - p[i - 1].first) * D);
		dn[i] += p[i].second;
	}

	for (int i = p.size() - 1; i >= 0; --i) {
		if (i != p.size() - 1) up[i] = max(up[i], up[i + 1] - (p[i + 1].first - p[i].first) * U);
		up[i] += p[i].second;
	}

	for (int i = 0; i < p.size(); ++i) {
		udSet(p[i].first, max(up[i], dn[i]));
	}
}

int main() {

	fastio;

	cin >> N >> U >> D >> S;

	for (int i = 0; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c; // 날짜 위치 이익

		vec[a].push_back({ b,c });
	}

	udSet(S, 0);

	for (int i = 1; i <= MAXN; ++i) dp(vec[i]);

	cout << fdDP(S);

	return EXIT_SUCCESS;
}