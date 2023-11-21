#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using int64 = int64_t;

typedef struct {
    int64 x;
    int64 y;
} coordinate;

queue<coordinate> q;

/*
vector<int64> arr_map[1001] = {
                                {0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 1}
                                };
                                */

vector<int64> arr_map[1001] = {};
int64 arr_visit[1001][1001] = {};
bool arr_bool[1001][1001];
int64 ans;
int64 _total;
 

inline void BFS(int64 N, int64 M) {
    int64 x, y;
    int Count = 0;
    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        Count = arr_visit[x][y]+1;
        q.pop();
        if (x + 1 < N) {
            if (!arr_bool[x + 1][y]) {
                arr_bool[x + 1][y] = true;
                arr_visit[x + 1][y] = Count;
                q.push({ x + 1, y });
            }
        }
        if (x - 1 >=0) {
            if (!arr_bool[x - 1][y]) {
                arr_bool[x - 1][y] = true;
                arr_visit[x - 1][y] = Count;
                q.push({ x - 1, y });
            }
        }
        if (y + 1 < M) {
            if (!arr_bool[x][y+1]) {
                arr_bool[x][y+1] = true;
                arr_visit[x][y+1] = Count;
                q.push({ x , y+1 });
            }
        }
        if (y - 1 >=0) {
            if (!arr_bool[x][y - 1]) {
                arr_bool[x][y - 1] = true;
                arr_visit[x][y - 1] = Count;
                q.push({ x , y - 1 });
            }
        }
        
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int64 M, N, n;
    cin >> M >> N;
    for (int64 i = 0; i < N; ) {
        for (int64 j = 0; j < M; ) {
            cin >> n;
            arr_map[i].push_back(n);
            if (arr_map[i][j] == 1) {
                q.push({ i,j });
                arr_bool[i][j] = true;
                arr_visit[i][j] = 0;
            }
            else if (arr_map[i][j] == -1) {
                arr_bool[i][j] = true;
                _total++;
            }
            ++j;
        }
        ++i;
    }
   
    BFS(N, M);

    int64 _max = 0;
    for (int64 i = 0; i < N; ) {
        for (int64 j = 0; j < M; ) {
            if (ans < arr_visit[i][j]) {
                ans = arr_visit[i][j];
            }
            ++j;
        }
        ++i;
    }

    for (int64 i = 0; i < N; ) {
        for (int64 j = 0; j < M; ) {
            if ((arr_map[i][j] == 0) && arr_visit[i][j] == 0) {
                ans = -1;
            }
            ++j;
        }
        ++i;
    }

    cout << ans;

    return EXIT_SUCCESS;
}