#include<bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;

int a, b, c;

int main() {

	fastio;

	double w, h; cin >> w >> h;

	double bmi = w / pow(h, 2);

	string ans = "";
	if (bmi < 18.5) ans = "Underweight";
	else if (bmi >= 18.5 && bmi < 25) ans = "Normal weight";
	else if (bmi >= 25) ans = "Overweight";

	cout << ans << "\n";

}