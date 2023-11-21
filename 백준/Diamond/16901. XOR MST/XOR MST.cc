#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

struct Trie {
	int lt = -1, rt = -1;
};

int arr[200000];
int64 ans;
vector<Trie> v;

void insert(int p, int n = 1, int d = 30) {
	if (d == -1) return;
	if (p & (1 << d)) {
		if (v[n].rt == -1) {
			v[n].rt = v.size();
			v.push_back({});
		}
		insert(p, v[n].rt, d - 1);
	}
	else {
		if (v[n].lt == -1) {
			v[n].lt = v.size();
			v.push_back({});
		}
		insert(p, v[n].lt, d - 1);
	}
}

int64 fd(int p, int n = 1, int d = 30) {
	if (d == -1) return 0;

	if (p & (1 << d)) {
		if (v[n].rt != -1) return fd(p, v[n].rt, d - 1);
		return (1 << d) + fd(p, v[n].lt, d - 1);
	}
	else {
		if (v[n].lt != -1) return fd(p, v[n].lt, d - 1);
		return (1 << d) + fd(p, v[n].rt, d - 1);
	}
}

void sol(int l, int r, int d = 30) {
	if (d == -1 || r <= l) return;

	int m = l;
	for (; m <= r; ++m) {
		if ((arr[m] & (1 << d))) break;
	}

	sol(l, m - 1, d - 1); sol(m, r, d - 1);

	if (m == l || m == r + 1) return;

	v.clear();
	v.resize(2);

	for (int i = l; i < m; ++i) {
		insert(arr[i]);
	}
	
	int64 mi = INT64_MAX;
	for (int i = m; i <= r; ++i) {
		mi = min(mi, fd(arr[i]));
	}

	ans += mi;
}

int main() {

	fastio;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	sol(0, N - 1);

	cout << ans;

	return EXIT_SUCCESS;
}