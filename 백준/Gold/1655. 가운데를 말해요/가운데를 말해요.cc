#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using int64 = int64_t;

priority_queue<int, vector<int>, greater<int>> le;
priority_queue<int> gr;
queue<int> mi;
int64 Count=1, res;
vector<int> v;
inline void Solve(int64 t) {
	if (Count == 1) {
		mi.push(t);
		//cout << mi.front();
		v.push_back(mi.front());
	}
	else if (Count % 2 == 0) {
		if (t > mi.front()) {
			le.push(t);
			//cout << mi.front();
			v.push_back(mi.front());
		}
		else {
			res = mi.front();
			mi.pop();
			le.push(res);
			gr.push(t);
			res = gr.top();
			gr.pop();
			mi.push(res);
			//cout << mi.front();
			v.push_back(mi.front());
		}
	}
	else {
		if (t < mi.front()) {
			gr.push(t);
			//cout << mi.front();
			v.push_back(mi.front());
		}
		else {
			res = mi.front();
			mi.pop();
			gr.push(res);
			le.push(t);
			res = le.top();
			le.pop();
			mi.push(res);
			//cout << mi.front();
			v.push_back(mi.front());
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);


	int64 T, t;
	cin >> T;
	for (int64 i = 0; i < T;) {
		cin >> t;
		Solve(t);
		Count++;
		++i;
	}
	
	for (auto _iter : v) {
		cout << _iter << "\n";
	}

	return EXIT_SUCCESS;
}