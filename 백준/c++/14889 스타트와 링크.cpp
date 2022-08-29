#include <iostream>
#include <vector>
using namespace std;
using int64 = int64_t;


int64 smallest = 1000000;
inline void combine(int64 arr[][21], vector<int64>& v, int64 psl) {
	vector<int64> v2;
	int64 team1 = 0, team2 = 0, compare = 0;
	int64 arr2[21] = {};

	for (int64 i = 0; i < v.size();) {
		for (int64 j = 0; j < v.size();) {
			team1 += arr[v[i]][v[j]];
			++j;
		}

		++i;
	}

	for (int64 i = 0; i < v.size();) {
		arr2[v[i]] = 1;
		++i;
	}

	for (int64 i = 0; i < psl; ) {
		if (arr2[i] == 0) {
			v2.push_back(i);
		}
		++i;
	}

	for (int64 i = 0; i < v2.size();) {
		for (int64 j = 0; j < v2.size();) {
			team2 += arr[v2[i]][v2[j]];
			++j;
		}

		++i;
	}

	if (team2 >= team1) {
		compare = team2 - team1;
	}
	else {
		compare = team1 - team2;
	}

	if (compare <= smallest) {
		smallest = compare;
	}
}

inline void selector(int64 arr1[][21], int64 psl, int64 select, vector<int64>& v) {

	int64 smallest = v.empty() ? 0 : v.back() + 1;

	if (select == 0) {
		combine(arr1, v, psl);
	}


	for (int i = smallest; i < psl;) {
		v.push_back(i);
		selector(arr1, psl, select - 1, v);
		v.pop_back();

		++i;
	}
}

inline void solve(int64 arr1[][21], int64 psl) {
	int64 select = psl / 2;
	vector<int64> v;

	selector(arr1, psl, select, v);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T;
	cin >> T;

	int64 arr1[21][21], arr2[21][21];
	for (int64 row = 0; row < T;) {
		for (int64 column = 0; column < T;) {
			cin >> arr1[row][column];

			++column;
		}

		++row;
	}


	solve(arr1, T);

	cout << smallest;

	return EXIT_SUCCESS;
}