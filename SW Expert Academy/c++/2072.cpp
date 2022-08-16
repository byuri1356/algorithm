#include<iostream>
using namespace std;

int main(int argc, char** argv) {
	int case_number;
	int a[100][10];
	int sum = 0;

	cin >> case_number;

	for (int i = 1; i <= case_number; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= case_number; i++) {
		cout << "#" << i << ' ';
		for (int j = 0; j < 10; j++) {
			if (a[i][j] % 2 != 0)
				sum += a[i][j];
		}
		cout << sum << endl;
		sum = 0;
	}

	return 0;
}