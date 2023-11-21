#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

inline int hashing(char c) {
	if (c == 'A') return 0;
	else if (c == 'G') return 1;
	else if (c == 'T') return 2;
	else return 3;
}

class Trie {
public:
	Trie* ch[4];
	Trie* fail;
	bool isEnd;

	Trie() {
		isEnd = false;
		for (int i = 0; i < 4; ++i) {
			ch[i] = nullptr;
		}
		fail = nullptr;
	}

	~Trie() {
		for (int i = 0; i < 4; ++i) {
			if (ch[i]) delete ch[i];
		}
	}

	void insert(const char* s) {
		if (!*s) {
			isEnd = true;
			return;
		}

		int idx = hashing(*s);

		if (!ch[idx]) ch[idx] = new Trie();

		ch[idx]->insert(s + 1);
	}



};

inline void Bfs(Trie* root) {
	queue<Trie*> q;
	root->fail = root;
	q.push(root);

	while (!q.empty()) {
		Trie* cur = q.front();

		q.pop();

		for (int i = 0; i < 4; ++i) {
			Trie* nextN = cur->ch[i];

			if (!nextN) continue;

			if (cur == root) nextN->fail = root;
			else {
				Trie* dest = cur->fail;

				while (dest != root && !dest->ch[i]) {
					dest = dest->fail;
				}

				if (dest->ch[i]) dest = dest->ch[i];

				nextN->fail = dest;
			}

			if (nextN->fail->isEnd) nextN->isEnd = true;

			q.push(nextN);
		}

	}

}

int main() {

	fastio;

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		int n, m, ans = 0;
		cin >> n >> m;

		string dna, marker;
		cin >> dna >> marker;

		Trie* root = new Trie();

		root->insert(marker.c_str());
		for (int i = 0; i < marker.length(); ++i) {
			for (int j = i + 1; j < marker.length(); ++j) {
				string res = marker;
				reverse(res.begin() + i, res.begin() + j + 1);
				root->insert(res.c_str());
			}
		}

		Bfs(root);

		Trie* cur = root;
		for (int i = 0; i < dna.length(); ++i) {
			int idx = hashing(dna[i]);
			
			while (cur != root && !cur->ch[idx]) {
				cur = cur->fail;
			}
			
			if (cur->ch[idx]) {
				cur = cur->ch[idx];
			}

			if (cur->isEnd) ans++;
		}

		delete root;

		cout << ans << "\n";
	}

	return EXIT_SUCCESS;
}