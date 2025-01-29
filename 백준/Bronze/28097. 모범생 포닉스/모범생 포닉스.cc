#include <iostream>
using namespace std;
int main()
{
    int N, T, R = 0;
    cin >> N;
    R += (N - 1) * 8;
    for (int i = 0; i < N; i++) {
        cin >> T;
        R += T;
    }
    cout << R / 24 << " " << R % 24;
    return 0;
}