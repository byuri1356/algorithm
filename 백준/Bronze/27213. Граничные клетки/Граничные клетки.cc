#include <iostream>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;

  if (m == 1 || n == 1) {
    cout << m * n;
    return 0;
  }

  cout << m * 2 + n * 2 - 4;

  return 0;
}