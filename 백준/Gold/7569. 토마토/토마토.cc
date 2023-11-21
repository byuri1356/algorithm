#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using int64 = int64_t;

typedef struct {
    int64 z;
    int64 x;
    int64 y;
} coordinate;

queue<coordinate> q;

vector<int64> arr_map[101][101] = {};
int64 arr_visit[101][101][101] = {};
bool arr_bool[101][101][101];
int64 ans;

inline void BFS(int64 N, int64 M, int64 H) {
    int64 z,x,y;
    int Count = 0;
    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        z = q.front().z;
        Count = arr_visit[z][x][y]+1;
        q.pop();
        if (x + 1 < N) {
            if (!arr_bool[z][x+1][y]) {
                arr_bool[z][x + 1][y] = true;
                arr_visit[z][x + 1][y] = Count;
                q.push({ z, x+1, y });
            }
        }
        if (x - 1 >=0) {
            if (!arr_bool[z][x - 1][y]) {
                arr_bool[z][x - 1][y] = true;
                arr_visit[z][x - 1][y] = Count;
                q.push({ z, x - 1, y });
            }
        }
        if (y + 1 < M) {
            if (!arr_bool[z][x][y+1]) {
                arr_bool[z][x][y + 1] = true;
                arr_visit[z][x][y + 1] = Count;
                q.push({ z , x, y+1 });
            }
        }
        if (y - 1 >=0) {
            if (!arr_bool[z][x][y - 1]) {
                arr_bool[z][x][y - 1] = true;
                arr_visit[z][x][y - 1] = Count;
                q.push({ z , x, y - 1 });
            }
        }
        if (z + 1 < H) {
            if (!arr_bool[z+1][x][y]) {
                arr_bool[z + 1][x][y] = true;
                arr_visit[z + 1][x][y] = Count;
                q.push({ z+1 , x , y });
            }
        }
        if (z - 1 >= 0) {
            if (!arr_bool[z - 1][x][y]) {
                arr_bool[z - 1][x][y] = true;
                arr_visit[z - 1][x][y] = Count;
                q.push({ z - 1 , x , y });
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int64 M, N, H, n;
    cin >> M >> N >> H;
    for (int64 k = 0; k < H; ) {
        for (int64 i = 0; i < N; ) {
            for (int64 j = 0; j < M; ) {
                cin >> n;
                arr_map[k][i].push_back(n);
                if (arr_map[k][i][j] == 1) {
                    q.push({ k,i,j });
                    arr_bool[k][i][j] = true;
                    arr_visit[k][i][j] = 0;
                }
                else if (arr_map[k][i][j] == -1) {
                    arr_bool[k][i][j] = true;
                }
                ++j;
            }
            ++i;
        }
        ++k;
    }
    
   
    BFS(N, M, H);

    for (int k = 0; k < H; ) {
        for (int64 i = 0; i < N; ) {
            for (int64 j = 0; j < M; ) {
                if ((arr_map[k][i][j] == 0) && arr_visit[k][i][j] == 0) {
                    ans = -1;
                    break;
                }
                else  if (ans < arr_visit[k][i][j]) {
                    ans = arr_visit[k][i][j];
                }
                ++j;
            }
            if (ans == -1) {
                break;
            }
            ++i;
        }
        if (ans == -1) {
            break;
        }
        ++k;
    }    

    cout << ans;

    return EXIT_SUCCESS;
}
