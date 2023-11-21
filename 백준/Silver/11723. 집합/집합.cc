#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool arr[21];

int main() {
	fastio;
	
	int64 T, t;
	string command;
	cin >> T;
	for (int64 i = 0; i < T;) {
		cin >> command;
		if (command == "add") {
			cin >> t;
			arr[t] = true;
		}
		else if (command == "remove") {
			cin >> t;
			arr[t] = false;
		}
		else if (command == "check") {
			cin >> t;
			if (arr[t]) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (command == "toggle") {
			cin >> t;
			if (arr[t]) arr[t] = false;
			else arr[t] = true;
		}
		else if (command == "all") {
			for (int64 j = 1; j <= 20;) {
				arr[j] = true;
				++j;
			}
		}
		else if (command == "empty") {
			for (int64 j = 1; j <= 20;) {
				arr[j] = false;
				++j;
			}
		}
		++i;
	}

	return EXIT_SUCCESS;
}