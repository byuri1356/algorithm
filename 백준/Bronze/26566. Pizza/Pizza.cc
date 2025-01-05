#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    double A1, P1;
    cin >> A1 >> P1;

    double R1, P2;
    cin >> R1 >> P2;

    if (A1 / P1 > (R1 * R1 * 3.1415926535) / P2) {
      cout << "Slice of pizza\n";
    } else {
      cout << "Whole pizza\n";
    }
  }

  return 0;
}