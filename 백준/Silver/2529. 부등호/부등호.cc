#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;

vector<int64> v;
vector<string>v1;
int64 res = 0;
int64 arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
char _arr[10];
bool _visit[10];

inline void Solve(int64 S, int64 cmp) {
	if (S == 0) {
		stringstream ssint;
		for (auto _iter : v) {
			ssint << _iter;
		}
		v1.push_back(ssint.str());
		return;
	}

	for (int64 i = 0; i < 10; ++i) {
		if (_visit[i]) continue;
		else if ((_arr[cmp] == '<') && v.back() < arr[i]) {
			v.push_back(arr[i]);
			_visit[i] = true;
			Solve(S - 1, cmp + 1);
			v.pop_back();
			_visit[i] = false;
		}
		else if ((_arr[cmp] == '>') && v.back() > arr[i]) {
			v.push_back(arr[i]);
			_visit[i] = true;
			Solve(S - 1, cmp + 1);
			v.pop_back();
			_visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T;
	cin >> T;
	for (int64 i = 0; i < T;) {
		cin >> _arr[i];
		++i;
	}

	for (int64 i = 0; i <= 9;) {
		v.push_back(i);
		_visit[i] = true;
		Solve(T, 0);
		v.pop_back();
		_visit[i] = false;
		++i;
	}
	
	cout << v1.back() << "\n" << v1.front();
	return EXIT_SUCCESS;
}