#include<iostream>
using namespace std;

int main() {

    int a, b, c, d; cin >> a >> b >> c >> d;
    if ((c <= b && d <= a * 2) || d <= b && c <= a * 2) cout << "YES";
    else cout << "NO";
}