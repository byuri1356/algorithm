#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[1'000'001];

int main() {
	fastio;

	for (int64 j = 1; j <= 1'000'000; ++j) {
		for (int64 k = 1; k * j <= 1'000'000; ++k) {
			arr[k * j] += j;
		}
	}
	for (int64 j = 2; j <= 1'000'000; ++j) {
		arr[j] += arr[j - 1];
	}

	int64 T, N;
	cin >> T;
	for (int64 i = 0; i < T; ++i) {
		cin >> N;
		cout << arr[N]<<"\n";
	}
	

	return EXIT_SUCCESS;
}