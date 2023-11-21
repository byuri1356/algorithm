#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MIN
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

int arr[101][101][101];
string a, b, c;

int main() {
	fastio;
	
	cin >> a >> b >> c;

	for (int i = 1; i <= a.length(); ++i) {
		for (int j = 1; j <= b.length(); ++j) {
			for (int k = 1; k <= c.length(); ++k) {
				arr[i][j][k] = max(arr[i][j][k - 1], arr[i][j-1][k]);
				arr[i][j][k] = max(arr[i][j][k], arr[i - 1][j][k]);
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
					arr[i][j][k] = max(arr[i][j][k], arr[i - 1][j - 1][k - 1] + 1);
				}
			}
		}
	}

	cout << arr[a.length()][b.length()][c.length()];

	return EXIT_SUCCESS;
}