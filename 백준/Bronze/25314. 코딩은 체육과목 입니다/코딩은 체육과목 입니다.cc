#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;
	
	int N;
	cin >> N;

	for (int i = N; i != 0; i -= 4) {
		cout << "long" << " ";
	}

	cout << "int";

	return 0;
}