#include<iostream>
#include<deque>
using namespace std;
using int64 = int64_t;

int main() {
	int64 T;

	while (cin >> T) {
		int64 n;
		deque<int64> dq;

		for (int64 i = 0; i < 8; ++i) {
			cin >> n;
			dq.push_back(n);
		}

		bool token = true;

		while (token) {
			for (int64 i = 1; i <= 5; ++i) {
				int64 m = dq[0] - i;
				if (m <= 0) {
					m = 0;
					dq.pop_front();
					dq.push_back(m);
					token = false;
					break;
				}
				dq.pop_front();
				dq.push_back(m);
			}
		}

		cout << '#' << T << ' ';
		for (auto iter : dq) {
			cout << iter << ' ';
		}
		cout << "\n";
	}


	return EXIT_SUCCESS;
}