#include<iostream>
#include<vector>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;

vector<int> arr, sT, lazy;



inline void updateLazy(int st, int ed, int nd) {
	if (lazy[nd] != 0) {

		if (st != ed) {
			lazy[nd * 2] ^= lazy[nd];
			lazy[nd * 2 + 1] ^= lazy[nd];
		}

		sT[nd] = (ed - st + 1) % 2 == 0 ? sT[nd] : sT[nd] ^ lazy[nd];
		lazy[nd] = 0;
	}
}

inline int find(int st, int ed, int nd, int lt, int rt) {
	updateLazy(st, ed, nd);

	if (rt < st || ed < lt) return 0;


	if (lt <= st && ed <= rt) {
		return sT[nd];
	}

	int hf = (st + ed) / 2;

	return find(st, hf, nd * 2, lt, rt) ^ find(hf + 1, ed, nd * 2 + 1, lt, rt);
}

inline int update(int st, int ed, int nd, int lt, int rt, int sum) {
	updateLazy(st, ed, nd);

	if (rt < st || ed < lt) return sT[nd];

	if (lt <= st && ed <= rt) {

		if (st != ed) {
			lazy[nd * 2] ^= sum;
			lazy[nd * 2 + 1] ^= sum;
		}

		return sT[nd] = (ed - st + 1) % 2 == 0 ? sT[nd] : sT[nd] ^ sum;
	}

	int hf = (st + ed) / 2;

	return sT[nd] = update(st, hf, nd * 2, lt, rt, sum) ^ update(hf + 1, ed, nd * 2 + 1, lt, rt, sum);

}

inline int init(int st, int ed, int nd) {
	if (st == ed) return sT[nd] = arr[st];

	int hf = (st + ed) / 2;

	return sT[nd] = init(st, hf, nd * 2) ^ init(hf + 1, ed, nd * 2 + 1);
}

int main() {

	fastio;

	int N, M, h, tS;
	cin >> N;

	h = (int)ceil(log2(N));
	tS = 1 << h + 1;

	arr.resize(N), sT.resize(tS), lazy.resize(tS);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	init(0, N-1, 1);

	cin >> M;
	while(M--){
		int a, b, c, d;
		cin >> a >> b >> c;

		if (a == 1) {
			cin >> d;
			update(0, N - 1, 1, b, c, d);
		}
		else {
			cout << find(0, N - 1, 1, b, c) << "\n";
		}
	}

	return EXIT_SUCCESS;
}