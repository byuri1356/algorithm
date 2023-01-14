#include<iostream>
#include<string>

using namespace std;
using int64 = int64_t;

bool fnd;
int64 ans;
string chk, s;

int main() {
	int64 T;
	for (int64 t = 1; t <= 10; ++t) {
		cin >> T;
		cin >> chk >> s;

		
		for (int64 i = 0; i < s.length(); ++i) {
			fnd = true;
			for (int64 j = 0; j < chk.length(); ++j) {
				if (s[i + j] != chk[j]) {
					fnd = false;
					break;
				}
			}
			if (fnd) ans++;
		}

		cout << '#' << t << ' ' << ans << "\n";
		ans = 0;

	}


	return EXIT_SUCCESS;
}