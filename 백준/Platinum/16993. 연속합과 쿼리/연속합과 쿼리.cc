#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

struct tree {
	int l = 0, r = 0, t = 0;
};

tree seg[400004];

int N, M, num, nu[100001];

tree fd(int s, int e, int n, int l, int r) {
	if (r < s || e < l) return { -1000000000, -1000000000, -1000000000 };
	if (l <= s && e <= r) return seg[n];

	int h = (s + e) >> 1;

	tree lt = fd(s, h, n * 2, l, r);
	tree rt = fd(h + 1, e, n * 2 + 1, l, r);

	tree tmp;

	tmp.l = max(lt.l, rt.l + nu[h] - nu[s - 1]);
	tmp.r = max(rt.r, lt.r + nu[e] - nu[h]);
	tmp.t = max(lt.t, max(rt.t, lt.r + rt.l));

	return tmp;
}

tree ud(int s, int e, int n, int p) {
	if (p < s || e < p) return seg[n];
	if (p <= s && e <= p) return seg[n] = { num, num, num };

	int h = (s + e) >> 1;

	tree lt = ud(s, h, n * 2, p);
	tree rt = ud(h + 1, e, n * 2 + 1, p);

	seg[n].l = max(lt.l, rt.l + nu[h] - nu[s - 1]);
	seg[n].r = max(rt.r, lt.r + nu[e] - nu[h]);
	seg[n].t = max(lt.t, max(rt.t, lt.r + rt.l));

	return seg[n];
}

int main() {

	fastio;

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> num;
	
		nu[i] = nu[i - 1] + num;
		ud(1, N, 1, i);
	}

	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;

		cout << fd(1, N, 1, a, b).t << "\n";
	}

	return EXIT_SUCCESS;
}