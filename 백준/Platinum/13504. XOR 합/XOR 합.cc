#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;

class Trie {
public:
	Trie* trie[2];

	Trie() {
		fill(trie, trie + 2, nullptr);
	}

	~Trie() {
		for (int i = 0; i < 2; ++i) {
			if (trie[i]) delete trie[i];
		}
	}

	void insertNode(int sum, int idx) {
		if (idx == -1) return;

		int iidx = (sum & 1 << idx) == 0 ? 0 : 1;

		if (!trie[iidx]) trie[iidx] = new Trie();

		trie[iidx]->insertNode(sum, idx - 1);
		
	}

	int findNode(int sum, int idx, int ans) {
		if (idx == -1) return ans;

		int iidx = (sum & 1 << idx) == 0 ? 1 : 0;

		if (!trie[iidx]) {
			iidx = (iidx + 1) % 2;
			return trie[iidx]->findNode(sum, idx - 1, ans);
		}

		return trie[iidx]->findNode(sum, idx - 1, ans + (1 << idx));
	}
};

int main() {

	fastio;

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		Trie* root = new Trie();

		int N, num = 0, sum = 0, ans = 0;
		cin >> N;

		root->insertNode(0, 30);

		for (int i = 0; i < N; ++i) {
			cin >> num;
			sum ^= num;

			ans = max(ans, root->findNode(sum, 30, 0));
			root->insertNode(sum, 30);
		}

		cout << ans << "\n";

		delete root;
	}

	return EXIT_SUCCESS;
}