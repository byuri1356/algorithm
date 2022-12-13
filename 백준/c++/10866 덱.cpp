#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

deque<int64> d;

int main() {
	fastio;

	int64 T, t;
	string s;
	cin >> T;
	for (int64 i = 0; i < T; ++i) {
		cin >> s;
		if (s == "push_front") {
			cin >> t;
			d.push_front(t);
		}
		else if (s == "push_back") {
			cin >> t;
			d.push_back(t);
		}
		else if (s == "pop_front") {
			if (d.empty()) cout << -1 << "\n";
			else {
				cout << d.front() << "\n";
				d.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (d.empty()) cout << -1 << "\n";
			else {
				cout << d.back() << "\n";
				d.pop_back();
			}
		}
		else if (s == "size") {
			cout << d.size() << "\n";
		}
		else if (s == "empty") {
			if (d.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "front") {
			if (d.empty()) cout << -1 << "\n";
			else cout << d.front() << "\n";
		}
		else {
			if (d.empty()) cout << -1 << "\n";
			else cout << d.back() << "\n";
		}
	}

	return EXIT_SUCCESS;
}