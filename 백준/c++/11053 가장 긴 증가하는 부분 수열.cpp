#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[1001], _count[1001] = {}, Ans;

int main() {
	fastio;

	int64 N;
	cin >> N;
	for (int64 i = 1; i <= N;) {
		cin >> arr[i];
		++i;
	}
	for (int64 i = 1; i < N;) {
		for (int64 j = i+1; j <= N;) {
			if (arr[i] < arr[j]) _count[j] = max(_count[j], _count[i] + 1);
			++j;
		}
		++i;
	}

	for (int64 i = 1; i <= N;) {
		Ans = max(_count[i], Ans);
		++i;
	}
	cout << Ans + 1;

	return EXIT_SUCCESS;
}