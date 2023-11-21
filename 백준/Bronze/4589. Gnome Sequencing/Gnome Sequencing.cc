#include<iostream>
#include<string>
#include<vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int t;  cin >> t;
	cout << "Gnomes:\n";
	while (t--) {
		vector <int> beard(3);
		for (int i = 0; i < 3; i++) cin >> beard[i];
		if ((beard[1] - beard[0]) * (beard[2] - beard[1]) > 0) cout << "Ordered\n";
		else cout << "Unordered\n";
	}
}