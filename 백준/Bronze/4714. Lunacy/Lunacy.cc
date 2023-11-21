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
        double x;
        cin >> x;
        if (x < 0) break;
        printf("Objects weighing %.2f on Earth will weigh %.2f on the moon.\n", x, x * 0.167);
    }
}