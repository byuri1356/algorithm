#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;



int main() {

	fastio;

	vector<int64> v(3);
	while (true) {
		cin >> v[0] >> v[1] >> v[2];
		if (!(v[0] && v[1] && v[2])) break;

		sort(v.begin(), v.end());

		if (v[2] * v[2] == v[1] * v[1] + v[0] * v[0]) cout << "right"<<"\n";
		else cout << "wrong"<<"\n";
	}

	return EXIT_SUCCESS;
}