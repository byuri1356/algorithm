#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int64 arr[101][100'001];

int main() {
	fastio;

	int64 N, K, W, V;
	cin >> N >> K;
	for (int64 i = 1; i <= N;) {
		cin >> W >> V;
		for (int64 j = 1; j < W;) {
			arr[i][j] = arr[i - 1][j];
			++j;
		}
		for (int64 j = W; j <= K;) {
			arr[i][j] = max(arr[i - 1][j], V + arr[i - 1][j-W]);
			++j;
		}
		++i;
	}
	cout << arr[N][K];

	return EXIT_SUCCESS;
}