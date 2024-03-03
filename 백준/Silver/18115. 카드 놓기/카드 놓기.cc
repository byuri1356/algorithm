#include<iostream>
#include<deque>
#include<numeric>
#include<algorithm>
using namespace std;

int n, o, c;
deque<int> dq, dq1, op;

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	dq.resize(n);
	iota(dq.rbegin(), dq.rend(), 1);

	while (n--) {
		cin >> o;
		op.push_front(o);
	}

	for (int i : op) {
		c = dq.back(); dq.pop_back();
		switch (i) {
		case 1:
			dq1.push_back(c);
			break;
		case 2:
			dq1.push_back(c);
			swap(dq1[dq1.size() - 1], dq1[dq1.size() - 2]);
			break;
		case 3:
			dq1.push_front(c);
		}
	}
	for (auto i = dq1.rbegin(); i != dq1.rend(); ++i) cout << *i << " ";

	return 0;
}