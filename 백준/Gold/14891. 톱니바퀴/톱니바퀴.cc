#include <iostream>
#include<vector>
#include<string>
using namespace std;
using int64 = int64_t;

int64 ans;
int64 arr[5][8];

/*
int64 arr[5][8] = { {0,0,0,0,0,0,0,0},
					{1,0,0,1,0,0,1,1},
					{0,1,0,1,0,0,1,1},
					{1,1,1,0,0,0,1,1},
					{0,1,0,1,0,1,0,1} };
					*/
					

/*
int64 arr[5][8] = { {0,0,0,0,0,0,0,0},
					{1,0,0,0,1,0,1,1},
					{1,0,0,0,0,0,1,1},
					{0,1,0,1,1,0,1,1},
					{0,0,1,1,1,1,0,1} };
					*/
					

/*
int64 arr[5][8] = { {0,0,0,0,0,0,0,0},
					{1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1} };
					*/
					

/*
int64 arr[5][8] = {	{0,0,0,0,0,0,0,0},
					{1,0,1,0,1,1,1,1},
					{0,1,1,1,1,1,0,1},
					{1,1,0,0,1,1,1,0},
					{0,0,0,0,0,0,1,0} };
					*/
					
					

inline void rotate(int64 st, int64 vec) {
	if (vec == 1) {
		int64 arr1[8];
		int64 save = arr[st][7];
		for (int64 i = 0; i < 7;) {
			arr1[i + 1] = arr[st][i];
			++i;
		}
		arr1[0] = save;
		for (int64 i = 0; i < 8;) {
			arr[st][i] = arr1[i];
			++i;
		}
	}
	else if (vec == -1) {
		int64 arr1[8];
		int64 save = arr[st][0];
		for (int64 i = 7; i > 0;) {
			arr1[i - 1] = arr[st][i];
			--i;
		}
		arr1[7] = save;
		for (int64 i = 0; i < 8;) {
			arr[st][i] = arr1[i];
			++i;
		}
	}
}

inline void solve(int64 num, int64 vec, bool right, bool root) {
	if ((num == 4) && right) {
		rotate(num, vec);
		return;
	}
	else if ((num == 0) && !right) {
		rotate(num, vec);
		return;
	}
	else if (right) {
		if (arr[num][2] != arr[num + 1][6]) {
			right = true;
			solve(num + 1, -vec, right, false);
		}
	}
	else if (!right) {
		if (arr[num][6] != arr[num - 1][2]) {
			right = false;
			solve(num - 1, -vec, right, false);
		}
	}

	if (!root) {
		rotate(num, vec);
	}
}

int main(void){
	ios::sync_with_stdio;
	cin.tie(nullptr); cout.tie(nullptr);

	
	char c[5][8];
	for (int64 i = 1; i < 5;) {
		for (int64 j = 0; j < 8;) {
			cin >> c[i][j];
			arr[i][j] = (int64)c[i][j] - 48;
			++j;
		}
		++i;
	}
	
	int64 T;
	cin >> T;

	int64 num, vec;
	for (int64 i = 0; i < T;) {
		cin >> num >> vec;
		if (num == 1) {
			solve(num, vec, true, true);
		}
		else if (num == 4) {
			solve(num, vec, false, true);
		}
		else {
			solve(num, vec, true, true);
			solve(num, vec, false, true);
		}
		rotate(num, vec);
		
		++i;
	}

	if (arr[1][0]) {
		ans += 1;
	}
	if (arr[2][0]) {
		ans += 2;
	}
	if (arr[3][0]) {
		ans += 4;
	}
	if (arr[4][0]) {
		ans += 8;
	}

	cout << ans;

	return EXIT_SUCCESS;
}
