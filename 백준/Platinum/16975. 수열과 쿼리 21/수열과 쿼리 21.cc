#include<iostream>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

int N, M;
vector<int64> fT;

int64 find(int i) {
	int64 sum = 0;
	while (i > 0) {
		sum += fT[i];
		i -= i & -i;
	}
	return sum;
}

void update(int i, int dif) {
	while (i <= N) {
		fT[i] += dif;
		i += i & -i;
	}
}

int main() {

	fastio;

	cin >> N;

	fT.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		int64 n;
		cin >> n;

		update(i, n);
		update(i + 1, -n);
	}

	cin >> M;
	while (M--) {
		int a, b, c, d;
		cin >> a >> b;
		switch (a) {
		case 1:
			cin >> c >> d;
			update(b, d);
			update(c + 1, -d);
			break;
		case 2:
			cout << find(b) << "\n";
			break;
		}
	}

	return EXIT_SUCCESS;
}