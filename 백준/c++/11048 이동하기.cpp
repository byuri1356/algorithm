#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

int64 arr[1001][1001];
int64 candy[1001][1001];

inline void Solve(int64 N, int64 M) {
	candy[0][0] = arr[0][0];
	for (int i = 1; i < N;) {
		candy[i][0] = arr[i][0] + candy[i - 1][0];
		++i;
	}
	for (int i = 1; i < M;) {
		candy[0][i] = arr[0][i] + candy[0][i-1];
		++i;
	}
	for (int i = 1; i < N;) {
		for (int j = 1; j < M;) {
			candy[i][j] = arr[i][j] + max(candy[i - 1][j], candy[i][j - 1]);
			++j;
		}
		++i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int64 N, M;
	cin >> N >> M;
	
	for(int64 i=0 ; i<N;){
		for (int64 j = 0; j < M;) {
			cin >> arr[i][j];
			++j;
		}
		++i;
	}
	Solve(N,M);
	
	cout << candy[N-1][M-1];

	return EXIT_SUCCESS;
}
