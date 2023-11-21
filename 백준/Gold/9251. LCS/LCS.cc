#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 109876543210
using namespace std;
using int64 = int64_t;

int arr[1001][1001];
string a, b;

int main() {
	fastio;
	
	cin >> a >> b;
	for (int64 i = 1; i <= b.length(); ++i) {
		for (int64 j = 1; j <= a.length(); ++j) {
			arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			if (b[i - 1] == a[j - 1]) arr[i][j] = max(arr[i][j], arr[i - 1][j - 1] + 1);
		}
	}

	cout << arr[b.length()][a.length()];

	return EXIT_SUCCESS;
}