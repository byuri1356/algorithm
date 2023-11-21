#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int ans;

class Trie {
	Trie* trie[2];

public:
	Trie() {
		trie[0] = NULL;
		trie[1] = NULL;
	}

	void insertNode(vector<int>& bm, int idx) {
		if (idx == -1) return;

		int tf = bm[idx] == 0 ? 0 : 1;

		if (!trie[tf]) {
			trie[tf] = new Trie();
		}

		trie[tf]->insertNode(bm, idx - 1);
	}

	int findNode(vector<int>& bm, int idx, int sum) {
		if (idx == -1) return sum;

		int tf = bm[idx] == 0 ? 1 : 0;

		if (!trie[tf]) {
			tf = (tf + 1) % 2;
			return trie[tf]->findNode(bm, idx - 1, sum);
		}

		return trie[tf]->findNode(bm, idx - 1, sum + (1 << idx));
	}

};

int main() {

	fastio;

	int N;
	cin >> N;

	Trie* root = new Trie();
	vector<int> arr(N);
	vector<vector<int>> rs(N);

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int sz = log2(arr.back()) + 1;

	vector<int> bm(sz);

	for (int i = 0; i < N; ++i) {

		rs[i].resize(sz);
		for (int j = 0; j < sz; ++j) {
			bm[j] = arr[i] & 1 << j;
		}

		rs[i] = bm;
		root->insertNode(bm, sz - 1);
	}

	for (int i = 0; i < N; ++i) {
		int sum = root->findNode(rs[i], sz - 1, 0);
		ans = max(ans, sum);
	}

	cout << ans;
}