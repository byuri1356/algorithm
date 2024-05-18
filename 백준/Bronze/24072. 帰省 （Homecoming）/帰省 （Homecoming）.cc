#include<iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (c < a || b <= c)
        cout << 0;
    else
        cout << 1;
    return 0;
}