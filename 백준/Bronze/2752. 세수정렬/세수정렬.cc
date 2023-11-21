#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	vector<int> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(a.begin(), a.end());
	cout << a[0] << " " << a[1] << " " << a[2];



}