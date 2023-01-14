#include<iostream>
#include<algorithm>
using namespace std;
using int64 = int64_t;

char arr[100][100];
int64 cnt = 1;

int main() {
	int64 T;
	for (int64 t = 1; t <= 10; ++t) {
		cin >> T;

		for (int64 i = 0; i < 100; ++i) {
			for (int64 j = 0; j < 100; ++j) {
				cin >> arr[i][j];
			}
		}

		int64 token = 0;
		for (int64 i = 0; i < 100; ++i) {
			for (int64 j = 0; j < 100; ++j) {
				for (int64 k = 99; k > j; --k ) {
					token = k - j + 1;

					for (int64 l = 0; l <= (k - j) / 2 + 1; ++l) {
						if (arr[i][j + l] != arr[i][k - l]) {
							token = -1;
							break;
						}
					}
					if (token != -1) {
						cnt = max(cnt, token);
						break;
					}

					token = k - j + 1;

					for (int64 l = 0; l <= (k - j) / 2 + 1; ++l) {
						if (arr[j + l][i] != arr[k - l][i]) {
							token = -1;
							break;
						}
					}
					if (token != -1) {
						cnt = max(cnt, token);
						break;
					}
				}
			}
		}

		cout << '#' << t << ' ' << cnt << "\n";
		cnt = 1;
	}


	return EXIT_SUCCESS;
}