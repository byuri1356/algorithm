#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cntCase = 1;
  while (true) {
    int n; cin >> n;
    if (n == 0) break ;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    double median = 0;
    if (n % 2 == 0) median = (v[(n / 2) - 1] + v[n / 2]) / 2.0;
    else median = v[(n - 1) / 2];

    cout.setf(ios::fixed); cout.precision(1);
    cout << "Case " << cntCase << ": " << median << "\n";

    cntCase++;
  }

  return 0;
}