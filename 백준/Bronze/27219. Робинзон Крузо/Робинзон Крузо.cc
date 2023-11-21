#include<iostream>
#include<string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

    int n; cin >> n;

    int a = n / 5, b = n % 5;

    while (a--) {
        cout << "V";
    }

    while (b--) {
        cout << "I";
    }

    return 0;

}