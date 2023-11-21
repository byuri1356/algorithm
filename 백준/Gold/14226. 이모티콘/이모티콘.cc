#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

bool _visit[1'001];
int64 _map[1'001], _clip[1'001];
vector<int64> v;
queue<tuple<int64, int64, int64>> q;

inline bool _valid(int64 N) {
	return (N >= 0 && N<=1000);
}

inline void BFS(int64 cur, int64 clip, int64 destination) {
	_visit[1] = true;
	q.push(make_tuple(cur, clip, 0));
	while (!q.empty()) {
		int64 x = get<0>(q.front());
		int64 board = get<1>(q.front());
		int64 _count = get<2>(q.front());
		int64 _minus = x - 1;
		int64 _paste = x + board;
		q.pop();

		if (x == destination) {
			cout << _map[x];
			break;
		}

		if (_valid(_minus)) {
			if (!_visit[_minus] || _clip[_minus] != board) {
				_visit[_minus] = true;
				_clip[_minus] = board;
				if (!_map[_minus]) _map[_minus] = _count + 1;
				else _map[_minus] = min(_map[_minus], _count + 1);
				q.push(make_tuple(_minus, board, _count + 1));
			}
		}
		if (_valid(_paste)) {
			if (!_visit[_paste] || _clip[_paste] != board) {
				_visit[_paste] = true;
				_clip[_paste] = board;
				if (!_map[_paste]) _map[_paste] = _count + 1;
				else _map[_paste] = min(_map[_paste], _count + 1);
				q.push(make_tuple(_paste, board, _count + 1));
			}
		}
		if (board != x) {
			q.push(make_tuple(x, x, _count + 1));
		}
	}
}

int main() {
	fastio;

	int64 S;
	cin >> S;
	BFS(1, 0, S);

	return EXIT_SUCCESS;
}