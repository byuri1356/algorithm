#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using int64 = int64_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T, t;
	while (cin >> T) {
		int64 _count = 1;
		for (int64 i = 1; ;) {
			if (i < T) {
				i = (i%T) * 10 + (1%T);
				_count++;
			}
			else if ((i % T) != 0) {
				i = (i % T) * 10 + (1 % T);
				_count++;
			}
			else {
				cout << _count << "\n";
				break;
			}
		}
	}

	return EXIT_SUCCESS;
}