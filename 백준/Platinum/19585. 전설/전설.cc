#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

//트라이 클래스
class Trie {
	bool isEnd = false;
	map<char, Trie*> children;

public:
	void insertColors(string& s, int idx) {
		if (s.size() == idx) {
			isEnd = true;
			return;
		}

		if (children.find(s[idx]) == children.end()) {
			children[s[idx]] = new Trie();
		}

		children[s[idx]]->insertColors(s, idx + 1);
	}

	void insertNames(string& s, int idx) {
		if (idx == -1) {
			isEnd = true;
			return;
		}

		if (children.find(s[idx]) == children.end()) {
			children[s[idx]] = new Trie();
		}

		children[s[idx]]->insertNames(s, idx - 1);
	}

	void findColors(vector<int>& checkColor, string& s, int idx) {

		if (isEnd) checkColor.push_back(idx);

		if (s.size() == idx) return;

		if (children.find(s[idx]) != children.end()) {
			children[s[idx]]->findColors(checkColor, s, idx + 1);
		}
	}

	void findNames(vector<int>& checkName, string& s, int idx) {

		if (isEnd) checkName.push_back(idx);

		if (idx ==  - 1) return;

		if (children.find(s[idx]) != children.end()) {
			children[s[idx]]->findNames(checkName, s, idx - 1);
		}
	}

};

int main() {
	fastio;

	Trie* color = new Trie();
	Trie* name = new Trie();

	int C, N, Q;
	cin >> C >> N;

	for (int i = 0; i < C; ++i) {
		string s;
		cin >> s;

		color->insertColors(s, 0);
	}

	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;

		name->insertNames(s, s.size() - 1);
	}

	cin >> Q;

	for (int i = 0; i < Q; ++i) {
		string s;
		cin >> s;

		vector<int> checkColor, checkName;
		color->findColors(checkColor, s, 0);
		name->findNames(checkName, s, s.size() - 1);
		
		bool tk = false;
		int start = 0, end = 0;

		for (auto& iter : checkColor) {
			if (tk) break;
			for (auto& _iter : checkName) {
				if (tk) break;
				if (iter - _iter == 1) {
					tk = true;
					break;
				}
			}
		}

		/*
		while (start < checkColor.size() && end < checkName.size()) {
			if (checkColor[start] - checkName[end] == 1) {
				tk = true;
				break;
			}
			else if (checkColor[start] - checkName[end] < 1) {
				end++;
			}
			else start++;
		}
		*/
		if (tk)	cout << "Yes" << "\n";
		else cout << "No" << "\n";

	}

	return EXIT_SUCCESS;
}