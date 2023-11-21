#include<iostream>
#include<queue>
#include<tuple>
#include<cstring>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF_ BUFSIZ);
using namespace std;

int N, M;
char arr[50][50];
int bitmask[50][50];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool loop;
queue<tuple<int, int, int, int>> q;

inline bool isValid(int x, int y) {
    return (x >= 0 && x < N&& y >= 0 && y < M);
}

inline bool isCheck(int x, int y, int bt) {
    if (bitmask[x][y] == -1) return true;
    if (bitmask[x][y] != bt && (bitmask[x][y] & bt) != bt) return true;
    return false;
}

inline void bfs() {
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int bt = get<2>(q.front());
        int t = get<3>(q.front());

        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (isValid(nextX, nextY) && isCheck(nextX, nextY, bt) ) {
                if (arr[nextX][nextY] == '.') {
                    bitmask[nextX][nextY] = bt;
                    q.push({ nextX, nextY, bt, t + 1 });
                    continue;
                }
                else if (arr[nextX][nextY] == '1') {
                    cout << t + 1;
                    loop = true;
                    return;
                }
                else {
                    for (int j = 0; j < 6; ++j) {
                        if (arr[nextX][nextY] == char('a' + j)) {
                            bitmask[nextX][nextY] = bt | 1 << j;
                            q.push({ nextX, nextY, bitmask[nextX][nextY], t + 1 });
                            break;
                        }
                        else if (arr[nextX][nextY] == char('A' + j)) {
                            if ((bt & 1 << j) == 1 << j) {
                                bitmask[nextX][nextY] = bt;
                                q.push({ nextX, nextY, bt, t + 1 });
                            }
                            break;
                        }
                    }
                }

            }
        }
    }
}

int main() {

    memset(bitmask, -1, sizeof(bitmask));

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == '0') {
                bitmask[i][j] = 0;
                q.push({ i, j, 0, 0 });
                arr[i][j] = '.';
            }
        }
    }

    bfs();

    if (!loop) cout << "-1";

    return EXIT_SUCCESS;
}

