#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

class A {
public:
	int64 Count, pre_num;
	A() {
		Count = 0; pre_num = 0;
	}
};
int64 arr[1001], Ans, Pre;
vector<int64> v;

int main() {
	fastio;

	A a[1001];
	int64 N;
	cin >> N;
	for (int64 i = 1; i <= N;) {
		cin >> arr[i];
		++i;
	}
	for (int64 i = 1; i < N;) {
		for (int64 j = i+1; j <= N;) {
			if (arr[i] < arr[j]) {
				if (a[j].Count < a[i].Count + 1) {
					a[j].Count = max(a[j].Count, a[i].Count + 1);
					a[j].pre_num = i;
				}
			}
			++j;
		}
		++i;
	}
	int64 j = arr[1];
	for (int64 i = 1; i <= N;) {
		if (a[i].Count > Ans) {
			Ans = a[i].Count;
			Pre = a[i].pre_num;
			j = arr[i];
		}
		++i;
	}
	cout << Ans + 1<<"\n";
	v.push_back(j);
	for (int64 i = 0; i < Ans;) {
		v.push_back(arr[Pre]);
		Pre = a[Pre].pre_num;
		++i;
	}
	sort(v.begin(), v.end());
	for (auto _iter : v) {
		cout << _iter << ' ';
	}
	return EXIT_SUCCESS;
}