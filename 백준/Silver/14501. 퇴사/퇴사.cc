#include <iostream>
#include<vector>
using namespace std;
using int64 = int64_t;

int64 tmp = -1;
vector<int64> v;

typedef struct _Consulting {
	int64 date;
	int64 pay;
	bool possibility;
}Consulting;

inline void solve(Consulting arr1[], int64 T, int64 pre) {
	int sum = 0;
	if (pre == T) {
		for (int64 i = 0; i < v.size();) {
			sum += arr1[v[i]].pay;
			++i;
		}
		if (sum >= tmp) {
			tmp = sum;
		}
	}

	
	for (int64 test_case =pre; test_case < T;) {
		if (arr1[test_case].possibility) {
			v.push_back(test_case);
			solve(arr1, T, test_case + arr1[test_case].date);
			v.pop_back();
		}
		else {
			solve(arr1, T, pre + 1);
		}

		++test_case;
	}

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T;
	cin >> T;

	Consulting arr1[21];
	for (int64 test_case = 0; test_case < T; ) {
		cin >> arr1[test_case].date >> arr1[test_case].pay;
		if (arr1[test_case].date + test_case > T) {
			arr1[test_case].possibility = false;
		}
		else {
			arr1[test_case].possibility = true;
		}
		++test_case;
	}

	solve(arr1, T, 0);
	cout << tmp;

	return EXIT_SUCCESS;
}