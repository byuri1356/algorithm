#include<iostream>
#include<algorithm>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;



int main() {

	fastio;

	double N;
	cin >> N;

	cout << (int)ceil(N / 5);

	return EXIT_SUCCESS;
}