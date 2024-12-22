#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  double volume = 0;
  for (int i = 0; i < n; i++) {
    double c;
    cin >> c;
    volume += pow(c, 3);
  }

  cout.precision(6);
  cout << fixed;
  cout << pow(volume, 1.0 / 3);

  return 0;
}