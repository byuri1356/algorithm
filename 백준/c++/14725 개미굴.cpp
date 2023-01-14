#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

int64 N;
deque<string> dq;
priority_queue < deque<string>, vector<deque<string>>, greater<deque<string>>> pq;

class Tree {
public:
	int64 cnt;
	map<string, int64> mp;
	map<int64, string> pm;
	Tree* tr[1'000];
	Tree() {
		cnt = 0;
		for (int64 i = 0; i < N; ++i) tr[i] = NULL;

	}

	void insertNode(deque<string> pdq, int64 dep) {
		if (dep == pdq.size()) return;

		if (mp.find(pdq[dep]) == mp.end()) {
			mp.insert({pdq[dep], cnt});
			pm.insert({ cnt, pdq[dep] });
			tr[cnt] = new Tree();
			cnt++;
		}

		tr[mp[pdq[dep]]]->insertNode(pdq, dep + 1);
	}

	void searchNode(int64 dep) {
		if (cnt == 0) return;
		
		for (int64 i = 0; i < cnt; ++i) {
			for (int64 j = 0; j < dep; ++j) {
				cout << "--";
			}
			cout << pm[i] << "\n";
			tr[i]->searchNode(dep + 1);
		}


	}

};

int main() {
	fastio;

	Tree* root = new Tree();
	cin >> N;

	for (int64 i = 0; i < N; ++i) {
		int64 K;
		cin >> K;

		for (int64 j = 0; j < K; ++j) {
			string s;
			cin >> s;
			dq.push_back(s);
		}
		pq.push(dq);
		dq.clear();
	}

	while (!pq.empty()) {
		root->insertNode(pq.top(), 0);
		pq.pop();
	}

	root->searchNode(0);


	return EXIT_SUCCESS;
}