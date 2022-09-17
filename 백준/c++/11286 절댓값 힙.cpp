#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using int64 = int64_t;

priority_queue<int64, vector<int64>, greater<int64>> _plus;
priority_queue<int64> _minus;
vector<int64> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 T,t;
	cin >> T;
	for (int64 i = 0; i < T;) {
		cin >> t;
		if (t > 0) {
			_plus.push(t);
		}
		else if (t < 0) {
			_minus.push(t);
		}
		else {
			if (_minus.empty() && _plus.empty()) v.push_back(0);
			else if (_minus.empty()) {
				v.push_back(_plus.top());
				_plus.pop();
			}
			else if (_plus.empty()) {
				v.push_back(_minus.top());
				_minus.pop();
			}
			else if (-_minus.top() == _plus.top()) {
				v.push_back(_minus.top());
				_minus.pop();
			}
			else if ((_minus.top() + _plus.top()) < 0) {
				v.push_back(_plus.top());
				_plus.pop();
			}
			else {
				v.push_back(_minus.top());
				_minus.pop();
			}
		}
		++i;
	}
	for (auto _iter : v) {
		cout << _iter << "\n";
	}
	
	return EXIT_SUCCESS;
}