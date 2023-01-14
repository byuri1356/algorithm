#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 N, L, cnt, arr[100][100];

inline void checkColumn(int64 c) {
	int64 len = 1;
	vector<tuple<int64, int64, int64>> v;
	for (int64 i = 1; i < N; ++i) {
		if (i == N - 1) {
			if (arr[i - 1][c] == arr[i][c]) {
				len++;
				v.push_back({ arr[i - 1][c], len, 0 });
			}
			else {
				v.push_back({ arr[i - 1][c], len, 0 });
				v.push_back({ arr[i][c], 1, 0 });
			}
		}
		else {
			if (arr[i - 1][c] == arr[i][c]) len++;
			else {
				v.push_back({ arr[i - 1][c], len, 0 });
				len = 1;
			}
		}
	}

	if (v.size() == 1) {
		cnt++; return;
	}
	else if (v.size() == 2) {
		if (get<0>(v[0]) == get<0>(v[1]) - 1) get<2>(v[0]) = 1;
		else if (get<0>(v[0]) < get<0>(v[v.size() - 1]) - 1) return;
		if (get<0>(v[v.size() - 1]) == get<0>(v[v.size() - 2]) - 1) get<2>(v[v.size() - 1]) = 1;
		else if (get<0>(v[v.size() - 1]) < get<0>(v[v.size() - 2]) - 1) return;
	}
	else {
		if (get<0>(v[0]) == get<0>(v[1]) - 1) get<2>(v[0]) = 1;
		else if (get<0>(v[0]) < get<0>(v[v.size() - 1]) - 1) return;
		if (get<0>(v[v.size() - 1]) == get<0>(v[v.size() - 2]) - 1) get<2>(v[v.size() - 1]) = 1;
		else if (get<0>(v[v.size() - 1]) < get<0>(v[v.size() - 2]) - 1) return;

		for (int64 i = 1; i < v.size() - 1; ++i) {
			if (get<0>(v[i]) == get<0>(v[i - 1]) - 1) get<2>(v[i])++;
			else if (get<0>(v[i]) < get<0>(v[i - 1]) - 1) return;
			if (get<0>(v[i]) == get<0>(v[i + 1]) - 1) get<2>(v[i])++;
			else if (get<0>(v[i]) < get<0>(v[i + 1]) - 1) return;
		}
	}

	for (auto iter : v) {
		if (get<2>(iter) * L > get<1>(iter)) return;
	}

	cnt++;

	/*
	for (auto iter : v) {
		cout << "num: " << get<0>(iter) << ' ' << "len: " << get<1>(iter)<<' '<<"cnt: " << get<2>(iter)<<' ';
	}

	cout << "\n";
	*/

}

inline void checkRow(int64 r) {
	int64 len = 1;
	vector<tuple<int64, int64, int64>> v;
	for (int64 i = 1; i < N; ++i) {
		if (i == N - 1) {
			if (arr[r][i - 1] == arr[r][i]) {
				len++;
				v.push_back({ arr[r][i - 1], len, 0 });
			}
			else {
				v.push_back({ arr[r][i - 1], len, 0 });
				v.push_back({ arr[r][i], 1, 0 });
			}
		}
		else {
			if (arr[r][i - 1] == arr[r][i]) len++;
			else {
				v.push_back({ arr[r][i - 1], len, 0 });
				len = 1;
			}
		}
	}

	
	if (v.size() == 1) {
		cnt++; return;
	}
	else if (v.size() == 2) {
		if (get<0>(v[0]) == get<0>(v[1]) - 1) get<2>(v[0]) = 1;
		else if (get<0>(v[0]) < get<0>(v[v.size() - 1]) - 1) return;
		if (get<0>(v[v.size() - 1]) == get<0>(v[v.size() - 2]) - 1) get<2>(v[v.size() - 1]) = 1;
		else if (get<0>(v[v.size() - 1]) < get<0>(v[v.size() - 2]) - 1) return;
	}
	else {
		if (get<0>(v[0]) == get<0>(v[1]) - 1) get<2>(v[0]) = 1;
		else if (get<0>(v[0]) < get<0>(v[v.size() - 1]) - 1) return;
		if (get<0>(v[v.size() - 1]) == get<0>(v[v.size() - 2]) - 1) get<2>(v[v.size() - 1]) = 1;
		else if (get<0>(v[v.size() - 1]) < get<0>(v[v.size() - 2]) - 1) return;

		for (int64 i = 1; i < v.size() - 1; ++i) {
			if (get<0>(v[i]) == get<0>(v[i - 1]) - 1) get<2>(v[i])++;
			else if (get<0>(v[i]) < get<0>(v[i - 1]) - 1) return;
			if (get<0>(v[i]) == get<0>(v[i + 1]) - 1) get<2>(v[i])++;
			else if (get<0>(v[i]) < get<0>(v[i + 1]) - 1) return;
		}
	}
	
	for (auto iter : v) {
		if (get<2>(iter) * L > get<1>(iter)) return;
	}

	r;
	cnt++;

	/*
	for (auto iter : v) {
		cout << "num: " << get<0>(iter) << ' ' << "len: " << get<1>(iter)<<' '<<"cnt: " << get<2>(iter)<<' ';
	}

	cout << "\n";
	*/
	
}

int main() {
	fastio;

	cin >> N >> L;

	for (int64 i = 0; i < N; ++i) {
		for (int64 j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int64 i = 0; i < N; ++i) {
		checkRow(i);
		checkColumn(i);
	}

	cout << cnt;

	return EXIT_SUCCESS;
}