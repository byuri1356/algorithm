#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int a, b, n, x, y; cin >> a >> b >> n >> x >> y;
    int xx = a / x, yy = b / y;
    cout << (xx && yy ? (int)ceil((double)n / (xx * yy)) : -1);
}