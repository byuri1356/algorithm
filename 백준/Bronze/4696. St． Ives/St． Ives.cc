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

    while (1) {
        double a; cin >> a;
        if (a == 0) break;
        printf("%.2f\n", 1 + a + pow(a, 2) + pow(a, 3) + pow(a, 4));
    }
}