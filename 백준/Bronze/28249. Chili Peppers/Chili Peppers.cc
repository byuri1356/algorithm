#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  int T = 0;
  while (N--) {
    string s;
    cin >> s;

    if (s == "Poblano") T += 1500;
    else if (s == "Mirasol") T += 6000;
    else if (s == "Serrano") T += 15500;
    else if (s == "Cayenne") T += 40000;
    else if (s == "Thai") T += 75000;
    else if (s == "Habanero") T += 125000;
  }

  cout << T;
  
  return 0;
}