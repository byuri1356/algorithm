#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

vector<int64> sT, arr, lazy;

void updateLazy(int st, int ed, int nd) {
	if (lazy[nd] != 0) {
		sT[nd] += lazy[nd] * (ed - st + 1);

		if (st != ed) {
			lazy[nd * 2] += lazy[nd];
			lazy[nd * 2 + 1] += lazy[nd];
		}

		lazy[nd] = 0;
	}
}

int64 find(int st, int ed, int nd, int lt, int rt) {
	updateLazy(st, ed, nd);

	if (rt < st || ed < lt) return 0;

	if (lt <= st && ed <= rt) return sT[nd];

	int hf = (st + ed) / 2;

	return find(st, hf, nd * 2, lt, rt) + find(hf + 1, ed, nd * 2 + 1, lt, rt);
}

int64 update(int st, int ed, int nd, int lt, int rt, int sum) {
	updateLazy(st, ed, nd);

	if (rt < st || ed < lt) return sT[nd];

	if (lt <= st && ed <= rt) {
		if (st != ed) {
			lazy[nd * 2] += sum;
			lazy[nd * 2 + 1] += sum;
		}

		return sT[nd] += sum * (ed - st + 1);
	}

	int hf = (st + ed) / 2;

	return sT[nd] = update(st, hf, nd * 2, lt, rt, sum) + update(hf + 1, ed, nd * 2 + 1, lt, rt, sum);
}

int main() {

	fastio;

	int N, M;
	cin >> N;

	int h = (int)ceil(log2(N));
	int tS = 1 << h + 2;

	sT.resize(tS), arr.resize(N+1), lazy.resize(tS);

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; ++i) {
		
		update(1, N, 1, i, i, arr[i] - arr[i - 1]);
	}

	cin >> M;
	while (M--) {
		int op, a, b;
		cin >> op >> a;

		switch (op) {
		case 1:
			cin >> b;
			update(1, N, 1, a, b, 1);
			update(1, N, 1, b + 1, b + 1, -(b - a + 1));
			break;
		case 2:
			cout << find(1, N, 1, 1, a) << "\n";
			break;
		}
	}

	return EXIT_SUCCESS;
}