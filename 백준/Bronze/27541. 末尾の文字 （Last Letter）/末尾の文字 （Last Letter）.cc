#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  string S;
  cin >> S;

  if (S[N - 1] == 'G') {
    for (int i = 0; i < N - 1; i++) cout << S[i];
  } else {
    cout << S << "G";
  }
  
  return 0;
}