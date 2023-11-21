#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

double Ans;

class Trie {
	bool isEnd = false;
	map<char, Trie*> children;

public:
	void insertWords(string& s, int idx) {
		if (s.size() == idx) {
			isEnd = true;
			return;
		}

		if (children.find(s[idx]) == children.end()) {
			children[s[idx]] = new Trie();
		}

		children[s[idx]]->insertWords(s, idx + 1);
	}

	void checkFirst() {
		if (isEnd) Ans++;

		for (auto& iter : children) {
			iter.second->findWords(1);
		}
	}

	void findWords(double sum) {
		if (isEnd) {
			Ans += sum;
			sum++;
		}
		else if (children.size() > 1) sum++;

		for (auto& iter : children) {
			iter.second->findWords(sum); iter.first;
		}

	}

};

int main() {
	fastio;

	int N;
	while (cin >> N) {

		Trie* root = new Trie();

		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			
			root->insertWords(s, 0);
		}

		Ans = 0;

		root->checkFirst();

		printf("%.2f \n", Ans / N);

	}

	return EXIT_SUCCESS;
}