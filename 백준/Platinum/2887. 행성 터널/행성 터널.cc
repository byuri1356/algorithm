#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<queue>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;
using t3 = tuple<int, int, int>;
using t4 = tuple<int, int, int, int>;

vector<int> parent;

struct cmp {
	bool operator()(const t3& o1, const t3&o2) {
		return get<0>(o2) < get<0>(o1);
	}
};

bool cmpX(const t4& o1, const t4& o2) {
	return get<0>(o1) < get<0>(o2);
}

bool cmpY(const t4& o1, const t4& o2) {
	return get<1>(o1) < get<1>(o2);
}

bool cmpZ(const t4& o1, const t4& o2) {
	return get<2>(o1) < get<2>(o2);
}

inline int find(int p) {
	if (p != parent[p]) return find(parent[p]);

	return p;
}

int main() {

	fastio;

	int N;
	cin >> N;

	int64 ans = 0;

	parent.resize(N);
	vector<t4> v;
	priority_queue<t3, vector<t3>, cmp> pq;

	for (int i = 0; i < N; ++i) {
		int x, y, z;
		cin >> x >> y >> z;

		v.push_back({ x,y,z,i });
		parent[i] = i;
	}

	sort(v.begin(), v.end(), cmpX);

	for (int i = 0; i < v.size() - 1; ++i) {
		pq.push({ get<0>(v[i + 1]) - get<0>(v[i]), get<3>(v[i + 1]), get<3>(v[i]) });
	}

	sort(v.begin(), v.end(), cmpY);

	for (int i = 0; i < v.size() - 1; ++i) {
		pq.push({ get<1>(v[i + 1]) - get<1>(v[i]), get<3>(v[i + 1]), get<3>(v[i]) });
	}

	sort(v.begin(), v.end(), cmpZ);

	for (int i = 0; i < v.size() - 1; ++i) {
		pq.push({ get<2>(v[i + 1]) - get<2>(v[i]), get<3>(v[i + 1]), get<3>(v[i]) });
	}

	while (!pq.empty()) {
		int d = get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());

		pq.pop();

		int a = find(x);
		int b = find(y);

		if (a != b) {
			ans += d;
			if (a < b) parent[b] = a;
			else parent[a] = b;
		}
	}

	cout << ans;

	return EXIT_SUCCESS;
}
