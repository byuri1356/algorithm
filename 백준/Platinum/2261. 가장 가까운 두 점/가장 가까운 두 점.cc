#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int dist(pair<int, int> o1, pair<int, int> o2) {
	int y = o1.first - o2.first;
	int x = o1.second - o2.second;

	return (y * y) + (x * x);
}

int main() {

	fastio;

	int N;
	int minn = 0;
	cin >> N;

	set<pair<int, int>> s;
	vector<pair<int, int>> pos(N);

	for (int i = 0; i < N; ++i) {
		cin >> pos[i].first >> pos[i].second;
	}

	sort(pos.begin(), pos.end());

	minn = dist(pos[0], pos[1]);

	s.insert({ pos[0].second, pos[0].first });
	s.insert({ pos[1].second, pos[1].first });


	int idx = 0;
	for (int i = 2; i < N; ++i) {
		int x = pos[i].first;
		int y = pos[i].second;

		while (idx < i) {
			int ix = pos[idx].first;
			int iy = pos[idx].second;
			if ((ix - x) * (ix - x) > minn) {
				s.erase({ iy, ix });
				idx++;
			}
			else {
				break;
			}
		}

		auto st = s.lower_bound({ y - sqrt(minn), INT32_MIN });
		auto ed = s.lower_bound({ y + sqrt(minn), INT32_MAX });

		for (auto& it = st; it != ed; ++it) {
			minn = min(minn, dist({ it->second, it->first }, pos[i]));
		}

		s.insert({ y, x });
	}

	cout << minn;

	return EXIT_SUCCESS;
}