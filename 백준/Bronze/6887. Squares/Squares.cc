#include<bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int n;
	cin >> n;
	int i = 1;
	while (i * i <= n) i++;
	cout << "The largest square has side length " << i - 1 << ".";

}