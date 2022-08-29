#include<iostream>
using namespace std;
using int64 = int64_t;

int64 solve(int64 number, int64 squared, int64 div) {

	if (squared == 1) {
		return number % div;
	}

	int64 split = solve(number, squared / 2, div) % div;

	if ((squared % 2) == 1) {
		return split * split % div * number % div;
	}
	else {
		return split * split % div;
	}

}

int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int64 number, squared, div;
	cin >> number >> squared >> div;

	cout << solve(number, squared, div);

	return EXIT_SUCCESS;
}