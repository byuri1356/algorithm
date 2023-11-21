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

	int burger[3], drink[2], price = 0;
	cin >> burger[0] >> burger[1] >> burger[2] >> drink[0] >> drink[1];
	cout << min(burger[0], min(burger[1], burger[2])) + min(drink[0], drink[1]) - 50;
}