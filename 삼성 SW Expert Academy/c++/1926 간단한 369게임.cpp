#include<iostream>
#include<vector>
using namespace std;
using int64 = int64_t;

int main() {
	ios::sync_with_stdio;
	cin.tie(nullptr); cout.tie(nullptr);

	int64 N;
	cin >> N;
	for (int64 i = 1; i <= N; ++i) {
		if (i < 10) {
			if (!(i % 3) || !(i % 6) || !(i % 9)) cout << '-' << ' ';
			else cout << i << ' ';
		}
		else if (i < 100) {
			int64 a, b, count = 0;
			a = i / 10;
			b = i % 10;
			if ((!(a % 3) || !(a % 6) || !(a % 9)) && a) count++;
			if ((!(b % 3) || !(b % 6) || !(b % 9)) && b) count++;
			if (count == 0) cout << i << ' ';
			else if (count == 1) cout << '-' << ' ';
			else cout << "--" << ' ';

		}
		else if (i < 1000) {
			int64 a, b, c, count = 0;
			a = i / 100;
			b = (i - a * 100) / 10;
			c = (i - a * 100 - b * 10);
			if (!(a % 3) || !(a % 6) || !(a % 9)) count++;
			if ((!(b % 3) || !(b % 6) || !(b % 9)) && b) count++;
			if ((!(c % 3) || !(c % 6) || !(c % 9)) && c) count++;
			if (count == 0) cout << i << ' ';
			else if (count == 1) cout << '-' << ' ';
			else if (count == 2) cout << '--' << ' ';
			else cout << "---" << ' ';
		}
		else {
			cout << 1000;
		}
	}

	return EXIT_SUCCESS;
}