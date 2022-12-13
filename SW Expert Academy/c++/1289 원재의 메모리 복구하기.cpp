#include<iostream>
#include<string>
using namespace std;
using int64 = int64_t;

int cnt = 0;

int main() {
	int64 T;
	cin >> T;

	for (int64 t = 1; t <= T; ++t) {
		string s;
		cin >> s;

		cnt = 0;
		for (int64 i = 0; i < s.length(); ++i) {
			if (s[i] != '0') {
				for (int64 j = i; j < s.length(); ++j) {
					if (s[j] == '0') s[j] = '1';
					else s[j] = '0';
				}
				cnt++;
			}
		}

		cout << '#' << t << ' ' << cnt << "\n";
	}


	return EXIT_SUCCESS;
}