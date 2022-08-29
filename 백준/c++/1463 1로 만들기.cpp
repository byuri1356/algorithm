#include <iostream>
#include<vector>
using namespace std;
using int64 = int64_t;

int64 arr[1'000'000];
int64 ans;


int main(void){
	ios::sync_with_stdio;
	cin.tie(nullptr); cout.tie(nullptr);

	int64 num;
	cin >> num;
	
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	int64 min = 0;
	int64 compare1, compare2, compare3;
	for (int64 i = 4; i <= num;) {
		compare1 = 1000000;
		compare2 = 1000000;
		compare3 = 1000000;
		if ((i % 3) == 0) {
			compare3 = arr[i/3] +1;
		}
		if ((i % 2) == 0) {
			compare2 = arr[i/2] +1;
		}
		compare1 = arr[i - 1] +1;

		if (compare3 <= compare2) {
			min = compare3;
		}
		else {
			min = compare2;
		}
		if (compare1 <= min) {
			min = compare1;
		}
		arr[i] = min;
		++i;
	}

	cout << arr[num];

	return EXIT_SUCCESS;
}
