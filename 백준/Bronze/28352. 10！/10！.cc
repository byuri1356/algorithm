#include<iostream>

using namespace std;
using ll = long long;

int main() {

  int n; cin >> n;
  ll p[18] = {1};

  for(int i=1; i<=17; ++i) p[i] = p[i - 1] * i;

  cout << p[n]/p[10]*6 << "\n";

  return 0;
}