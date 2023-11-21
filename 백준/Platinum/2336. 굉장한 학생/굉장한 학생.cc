#include<iostream>
#include<vector>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using vv = vector<vector<int>>;

int find(vector<int>& sT, int st, int ed, int nd, int lt, int rt) {
	if (rt < st || ed < lt) return INT32_MAX;

	if (lt <= st && ed <= rt) return sT[nd];

	int hf = (st + ed) / 2;

	return min(find(sT, st, hf, nd * 2, lt, rt), find(sT, hf + 1, ed, nd * 2 + 1, lt, rt));
}

int update(vector<int>& sT, int st, int ed, int nd, int pv, int sum) {
	if (pv < st || ed < pv) return sT[nd];

	if (st != ed) {
		int hf = (st + ed) / 2;
		return sT[nd] = min(update(sT, st, hf, nd * 2, pv, sum), update(sT, hf + 1, ed, nd * 2 + 1, pv, sum));
	}

	return sT[nd] = sum;
}

int main() {

	fastio;

	int N, H, tS, ans = 0;
	cin >> N;

	H = (int)ceil(log2(N));
	tS = 1 << H + 1;

	vector<int> arr(N), sT(tS, INT32_MAX);
	vv std(N + 1, vector<int>(2));

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < N; ++j) {
			int a;
			cin >> a;
			std[a][i] = j;
		}
	}

	for (int j = 0; j < N; ++j) {
		int two = std[arr[j]][0], three = std[arr[j]][1];
		update(sT, 0, N - 1, 1, two, three);
		if (find(sT, 0, N - 1, 1, 0, two) == three) ans++;
	}

	cout << ans;

	return EXIT_SUCCESS;
}