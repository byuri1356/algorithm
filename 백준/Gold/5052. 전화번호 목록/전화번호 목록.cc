#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

bool token = true;

class Node {
	Node* node[10];
	bool isEnd = false;
public:

	Node() {
		for (int64 i = 0; i < 10; ++i) node[i] = NULL;
	}

	void insertNode(string s, int64 idx) {
		if (!token) return;

		if (idx == s.size()) {
			isEnd = true;
			return;
		}
		if (node[s[idx] - '0'] == NULL) {
			if (!isEnd) node[s[idx] - '0'] = new Node();
			else {
				token = false;
				return;
			}
		}

		node[s[idx] - '0']->insertNode(s, idx + 1);
	}
};

int main() {
	fastio;

	int64 T;
	cin >> T;

	for (int64 t = 0; t < T; ++t) {
		token = true;
		int64 N;
		Node* root = new Node();
		vector<string> vs;
		cin >> N;

		for (int64 i = 0; i < N; ++i) {
			string s;
			cin >> s;

			vs.push_back(s);
		}

		sort(vs.begin(), vs.end());

		for (auto iter : vs) {
			if (!token) break;
			root->insertNode(iter, 0);
		}

		if (token) cout << "YES" << "\n";
		else cout << "NO" << "\n";

	}

	return EXIT_SUCCESS;
}