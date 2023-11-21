#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int l, a, b, c, d, homeworkday;

	cin >> l >> a >> b >> c >> d;
	if (a % c == 0)
		homeworkday = a / c;
	else
		homeworkday = a / c + 1;

	if (b % d == 0)
		homeworkday = max(homeworkday, b / d);
	else
		homeworkday = max(homeworkday, b / d + 1);

	cout << l - homeworkday << "\n";
}