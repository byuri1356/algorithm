#include<iostream>
#include<string>
#include<memory.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int N, M, name[1001], dp[1001];

int sol(int idx, int size) {

	int& ref = dp[idx];

	if (ref != -1) return ref;

	ref = INT32_MAX;

	for (int i = idx; i < N; ++i) {
		size = size == M ? size - name[i] : size - name[i] - 1;
		if (size < 0) break;
		if (i == N - 1) return ref = 0;
		ref = min(ref, size * size + sol(i + 1, M));
	}

	return ref;
}

int main() {

	fastio;

	memset(dp, -1, sizeof dp);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) cin >> name[i];

	cout<<sol(0, M);

	//cout << "!";

}