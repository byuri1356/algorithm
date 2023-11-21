#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;



int main() {
	fastio;

    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    cout << t->tm_year + 1900 << "-";

    cout.width(2);
    cout.fill('0');
    cout << t->tm_mon + 1 << "-";

    cout.width(2);
    cout.fill('0');
    cout << t->tm_mday;

	return EXIT_SUCCESS;
}