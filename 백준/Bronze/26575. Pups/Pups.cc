#include<iostream>
#include<string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using ll = long long;



int main() {

	fastio;

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        double a, b, c; cin >> a >> b >> c;

        double cost = a * b * c;
        cout.setf(ios::fixed); cout.precision(2);
        cout << "$" << cost << "\n";
    }

    return 0;

}