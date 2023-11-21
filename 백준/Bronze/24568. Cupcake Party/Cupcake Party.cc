#include<iostream>
#include<ctime>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int a, b, ans;
	cin >> a >> b;
	ans = a * 8 + b * 3 - 28;
	if (ans < 0) ans = 0;
	cout << ans;

}