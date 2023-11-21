#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

queue<int64> q;

int main() {
	fastio;
	int64 T, t;
	string s;
	cin >> T;
	for (int64 i = 0; i < T; ++i) {
		cin >> s;
		if (s == "push") {
			cin >> t;
			q.push(t);
		}
		else if (s == "pop") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			if (q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "front") {
			if (q.empty()) cout << -1 << "\n";
			else cout << q.front() << "\n";
		}
		else {
			if (q.empty()) cout << -1 << "\n";
			else cout << q.back() << "\n";
		}
	}

	return EXIT_SUCCESS;
}