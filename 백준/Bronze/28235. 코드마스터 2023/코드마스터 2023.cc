#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

	string s; cin >> s;

	if (s == "SONGDO") cout << "HIGHSCHOOL";
	else if (s == "CODE") cout << "MASTER";
	else if (s == "2023") cout << "0611";
	else cout << "CONTEST";

}