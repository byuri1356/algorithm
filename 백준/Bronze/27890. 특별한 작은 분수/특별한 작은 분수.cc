#include <iostream>
using namespace std;

int main() {
  int x0, N;
  cin >> x0 >> N;

  for (int i = 0; i < N; i++) {
    if (x0 % 2 == 0) {
      x0 = ((x0 / 2) ^ 6);
    } else {
      x0 = ((2 * x0) ^ 6);
    }
  }

  cout << x0;

  return 0;
}