#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

struct tree {
	int64 l = 0, r = 0, t = 0, sum = 0;

	bool operator<(const tree& o) {
		if (l != o.l) return l < o.l;
		return r < o.r;
	}
};

tree seg[12001];

int64 ans;
vector<tree> arr;

tree ud(int s, int e, int n, int p, int64 pv) {
	if (p < s || e < p) return seg[n];
	if (p <= s && e <= p) {
		seg[n].l += pv;
		seg[n].r += pv;
		seg[n].t += pv;
		seg[n].sum += pv;
		return seg[n];
	}

	int h = (s + e) >> 1;

	tree lt = ud(s, h, n * 2, p, pv);
	tree rt = ud(h + 1, e, n * 2 + 1, p, pv);

	seg[n].sum = lt.sum + rt.sum;
	seg[n].l = max(lt.l, rt.l + lt.sum);
	seg[n].r = max(rt.r, lt.r + rt.sum);
	seg[n].t = max({ lt.t, rt.t, lt.r + rt.l });

	return seg[n];
}

int main() {

	fastio;

	int N, cnt = 0;
	cin >> N;

	arr.resize(N);

	for (int i = 0; i < N; ++i) {
		cin >> arr[i].l >> arr[i].r >> arr[i].t;
	}

	sort(arr.begin(), arr.end());

	int ret = 0;
	for (int i = 0; i < N; ++i) {
		if (i && arr[i].l != ret) cnt++;
		ret = arr[i].l;
		arr[i].l = cnt;
		swap(arr[i].l, arr[i].r);
	}

	cnt = 0;

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; ++i) {
		if (i && arr[i].l !=ret) cnt++;
		ret = arr[i].l;
		arr[i].l = cnt;
	}

	for (int i = 0; i < N; ++i) {

		if (i && arr[i].l == arr[i - 1].l) continue;

		for (int i = 0; i < 12001; ++i) {
			seg[i] = { 0, 0, 0, 0 };
		}

		for (int j = i; j < N; ++j) {
			ud(0, N - 1, 1, arr[j].r, arr[j].t);

			if (j == N - 1 || arr[j].l != arr[j + 1].l) {
				ans = max(ans, seg[1].t);
			}
		}
	}

	cout << ans;

	return EXIT_SUCCESS;
}