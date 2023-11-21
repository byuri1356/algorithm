#include<bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;



int main() {

	fastio;

	vector<int> v(3);

	cin >> v[0] >> v[1] >> v[2];
	sort(v.begin(), v.end());
	cout << v[1];

	return EXIT_SUCCESS;
}