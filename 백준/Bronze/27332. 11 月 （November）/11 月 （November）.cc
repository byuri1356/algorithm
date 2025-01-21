#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    if (A + B * 7 >= 31) cout << "0";
    else cout << "1";
    
    return 0;
}