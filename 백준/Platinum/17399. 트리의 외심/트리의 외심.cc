//https://www.acmicpc.net/problem/17399
//분야: LCA

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;

int dep[100001]; // 노드의 깊이
int anc[100001][18]; // 어떤 노드의 2^N 조상 노드 
vector<int> adj[100001]; // 간선 정보

// 중앙 노드 찾아가기
inline int moveTree(int c, int diff) {
	if (!diff) return c; // 이동해야할 거리가 0이면 리턴

	//조상노드 찾아가면서 거리 줄이기
	for (int i = 1; i < 18; ++i) {
		if (1 << i > diff) return moveTree(anc[c][i - 1], diff - (1 << (i - 1)));
	}
}

//단순 LCA
inline int LCA(int a, int b) {
	if (dep[a] > dep[b]) {
		return LCA(anc[a][(int)log2(dep[a] - dep[b])], b);
	}
	else if (dep[b] > dep[a]) {
		return LCA(a, anc[b][(int)log2(dep[b] - dep[a])]);
	}
	else if (a != b) {
		for (int i = 1; i < 18; ++i) {
			if (anc[a][i] == anc[b][i]) {
				return LCA(anc[a][i - 1], anc[b][i - 1]);
			}
		}
	}

	return a;
}

// LCA를 찾기 위한 초기화 중...
inline void initTree(int p, int c) {
	dep[c] = dep[p] + 1;
	anc[c][0] = p;

	for (int i = 1; i < 18; ++i) {
		anc[c][i] = anc[anc[c][i - 1]][i - 1];
	}

	for (auto& iter : adj[c]) {
		if (iter != p) initTree(c, iter);
	}
}

int main() {

	fastio;

	int N, M;
	cin >> N;

	//간선 정보 입력받기
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//트리 초기화
	initTree(1, 1);

	//쿼리 입력받기
	cin >> M;
	while (M--) {
		pair<int, int> p[3]; //first -> 높이,second -> 노드 번호

		for (int i = 0; i < 3; ++i) {
			cin >> p[i].second;
			p[i].first = dep[p[i].second];
		}

		sort(p, p + 3);

		//LCA 찾고 외심을 찾기 위해 중앙값 찾아서 이동시키기
		int lca1 = LCA(p[0].second, p[1].second); //LCA 찾는부분
		int dif1 = (p[1].first + p[0].first - 2 * dep[lca1]); // 중앙값 찾아가는 부분

		int lca2 = LCA(p[0].second, p[2].second);
		int dif2 = (p[2].first + p[0].first - 2 * dep[lca2]);

		int lca3 = LCA(p[1].second, p[2].second);
		int dif3 = (p[2].first + p[1].first - 2 * dep[lca3]);

		// 외심이 나올수 있는 경우의 수 3가지 모두 찾아보기
		if (dif1 % 2 == 0) {
			dif1 /= 2;
			lca1 = moveTree(p[1].second, dif1);

			int lcaa = LCA(lca1, p[2].second);

			if (dep[lca1] + p[2].first - 2 * dep[lcaa] == p[1].first - dep[lca1]) {
				cout << lca1 << "\n";
				continue;
			}
		}

		if (dif2 % 2 == 0) {
			dif2 /= 2;
			lca2 = moveTree(p[2].second, dif2);

			int lcaa = LCA(lca2, p[1].second);

			if (dep[lca2] + p[1].first - 2 * dep[lcaa] == p[2].first - dep[lca2]) {
				cout << lca2 << "\n";
				continue;
			}
		}

		if (dif3 % 2 == 0) {
			dif3 /= 2;
			lca3 = moveTree(p[2].second, dif3);

			int lcaa = LCA(lca3, p[0].second);

			if (dep[lca3] + p[0].first - 2 * dep[lcaa] == p[2].first - dep[lca3]) {
				cout << lca3 << "\n";
				continue;
			}
		}

		//외심 못찾은경우 -1 출력
		cout << "-1" << "\n";

	}

	return EXIT_SUCCESS;
}
