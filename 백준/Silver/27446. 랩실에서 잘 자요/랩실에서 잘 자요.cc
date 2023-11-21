#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

bool isTrue[101];
int N, M, Ans;

int main() {
	fastio;

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a;
		cin >> a;
		isTrue[a] = true;
	}


	int start = -1, end = -1;
	for (int i = 1; i <= N; ++i) {
		if (!isTrue[i]) {
			if (start == -1 && end == -1) {
				start = i, end = i;
			}
			else if (5 + 2 * (i - start + 1) > 5 + 2 * (end - start + 1) + 7) {
				Ans += 5 + 2 * (end - start + 1);
				start = end = i;
			}
			else {
				end = i;
			}
		}
	}

	if(!(start == -1 && end == -1)) Ans += 5 + 2 * (end - start + 1);

	cout << Ans;

	return EXIT_SUCCESS;
}