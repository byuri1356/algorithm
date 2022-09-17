#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

double arr[21][41];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	double W, L, D, bronze=0, silver=0, gold=0, platinum=0, diamond=0;
	cin >> W >> L >> D;
	arr[0][21] = W; arr[0][20] = D; arr[0][19] = L;
	for (int64 i = 0; i < 19;) {
		for (int64 j = 0; j < 41;) {
			if (arr[i][j] != 0) {
				arr[i + 1][j] += arr[i][j] * D;
				arr[i + 1][j + 1] += arr[i][j] * W;
				arr[i + 1][j - 1] += arr[i][j] * L;
			}
			++j;
		}
		++i;
	}

	for (int64 j = 0; j < 41;) {
		if (j < 10) {
			bronze += arr[19][j];
		}
		else if (j < 20) {
			silver += arr[19][j];
		}
		else if (j < 30) {
			gold += arr[19][j];
		}
		else if (j < 40) {
			platinum += arr[19][j];
		}
		else {
			diamond += arr[19][j];
		}
		++j;
	}
	cout.setf(ios::fixed);
	cout.precision(8);
	cout << bronze << "\n";
	cout << silver << "\n";
	cout << gold << "\n";
	cout << platinum << "\n";
	cout << diamond << "\n";
	
	return EXIT_SUCCESS;
}