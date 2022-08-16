#include<iostream>
using namespace std;
using int64 = int64_t;

int64 A[1'000'000];
int64 B[1'000'000];

inline void calc() {
    int64 C;
    cin >> C;
    for (int64 count = 0; count < C;) {
        cin >> A[count]; count++;
    }

    B[C - 1] = A[C - 1];
    for (int64 count = C - 1; count > 0;) {
        B[count - 1] = max(B[count], A[count - 1]); count--;
    }

    int64 Sum = 0;
    for (int64 count = 0; count < C;) {
        Sum += B[count] - A[count]; count++;
    }

    cout << Sum << '\n';
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int64 T;

    cin >> T;
    for (int64 test_case = 1; test_case <= T;)
    {
        cout << '#' << test_case << ' '; calc(); ++test_case;
    }
    return EXIT_SUCCESS;
}