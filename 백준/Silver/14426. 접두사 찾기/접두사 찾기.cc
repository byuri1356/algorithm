#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

int N, M, Ans;

class Trie {
public:
	Trie* children[26];

public:
	/*
	Trie() {
		for (int i = 0; i < 26; ++i) {
			children[i] = NULL;
		}
	}
	*/

	void insertWords(string& s, int idx) {
		if (idx == s.length()) return;

		if (children[s[idx] - 'a'] == NULL)
			children[s[idx] - 'a'] = new Trie();

		children[s[idx] - 'a']->insertWords(s, idx + 1);

	}

	bool findWords(string& s, int idx) {
		if (idx == s.size()) return true;
		else if (children[s[idx] - 'a'] == NULL) return false;

		return children[s[idx] - 'a']->findWords(s, idx + 1);
	}

};

int main() {
	fastio;

	Trie* root = new Trie();

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;

		root->insertWords(s, 0);
	}

	for (int i = 0; i < M; ++i) {
		string s;
		cin >> s;

		if (root->findWords(s, 0)) Ans++;
	}

	cout << Ans;

	return EXIT_SUCCESS;
}