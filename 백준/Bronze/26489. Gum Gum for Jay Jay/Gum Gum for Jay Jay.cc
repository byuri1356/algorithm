#include<iostream>
#include<string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int n = 0;
	string s;

	while (getline(cin, s)) {
		n++;
	}
	
	cout << n;

}