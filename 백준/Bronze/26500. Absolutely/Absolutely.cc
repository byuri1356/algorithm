#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;

  for (int i = 0; i < n; i++) {
    double a, b; cin >> a >> b;

    double absDist = abs(a - b);

    cout.setf(ios::fixed); cout.precision(1);
    cout << absDist << "\n";
  }

  return 0;
}