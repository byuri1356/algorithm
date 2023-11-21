#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int N, A, B; cin >> N >> A >> B;

	if (A < B) cout << "Bus";
	else if (B < A) cout << "Subway";
	else cout << "Anything";

}