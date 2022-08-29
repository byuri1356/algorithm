#include <iostream>

using namespace std;
using int64 = int64_t;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int a;
    int b;
    cin >> a >> b;

    for (int64 i = 0; i < b;) {
        for (int64 j = 0; j < a;) {
            cout << "*";
            ++j;
        }
        cout << "\n";
        ++i;
    }
    return 0;
}