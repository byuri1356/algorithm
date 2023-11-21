#include<iostream>
#include<string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	int N; string input;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; ++i)
	{
		getline(cin, input);
		cin.clear();
		cout << i + 1 << ". " << input << endl;
	}
}