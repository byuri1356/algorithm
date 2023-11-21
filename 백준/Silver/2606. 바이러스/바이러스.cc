#include <bits/stdc++.h>
using namespace std;
using int64 = int64_t;

#define MAX 101
#define INF 99999999

int64 arr[MAX][MAX];

inline void Solve(int64 V) {
	for (int64 i = 1;  i <= V;) {
		for (int64 j = 1; j <= V;) {
			for (int64 k = 1; k <= V;) {
				if (arr[j][i] + arr[i][k] < arr[j][k]) {
					arr[j][k] = arr[j][i] + arr[i][k];
				}
				++k;
			}
			++j;
		}
		++i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	fill(&arr[0][0], &arr[MAX - 1][MAX], INF);

	int64 V, E;
	cin >> V >> E;
	int64 from, to;
	for (int64 i = 0; i < E;) {
		cin >> from >> to;
		arr[from][to] = 1;
		arr[to][from] = 1;
		++i;
	}
	
	Solve(V);
	int64 ans = 0;
	for (int64 i = 2; i <= V;) {
		if (arr[1][i] != INF)
			ans++;
		++i;
	}
	cout << ans;
	return EXIT_SUCCESS;
}