#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;

int64 arr[100][100], arr1[100][100], dir, N, M, R;
vector<int64> v[4];
deque<int64> deq, pos;

inline void makeArr() {
    int64 cnt = 0;

    if (deq[0] == 0) {
        if (deq[1] == 1) {
            for (int64 i = 0, cnt = 0; i < N / 2; ++i) {
                for (int64 j = 0; j < M / 2; ++j) {
                    arr1[i][j] = v[pos[0]][cnt];
                    cnt++;
                }
            }
            for (int64 i = 0, cnt = 0; i < N / 2; ++i) {
                for (int64 j = M / 2; j < M; ++j) {
                    arr1[i][j] = v[pos[1]][cnt];
                    cnt++;
                }
            }
            for (int64 i = N / 2, cnt = 0; i < N; ++i) {
                for (int64 j = 0; j < M / 2; ++j) {
                    arr1[i][j] = v[pos[3]][cnt];
                    cnt++;
                }
            }
            for (int64 i = N / 2, cnt = 0; i < N; ++i) {
                for (int64 j = M / 2; j < M; ++j) {
                    arr1[i][j] = v[pos[2]][cnt];
                    cnt++;
                }
            }
        }
        else {
            dir = 1;
            int64 tmp;
            tmp = N;
            N = M;
            M = tmp;
            for (int64 i = 0, cnt = 0; i < M / 2; ++i) {
                for (int64 j = 0; j < N / 2; ++j) {
                    arr1[j][i] = v[pos[0]][cnt];
                    cnt++;
                }
            }
            for (int64 i = 0, cnt = 0; i < M / 2; ++i) {
                for (int64 j = N / 2; j < N; ++j) {
                    arr1[j][i] = v[pos[3]][cnt];
                    cnt++;
                }
            }
            for (int64 i = M / 2, cnt = 0; i < M; ++i) {
                for (int64 j = 0; j < N / 2; ++j) {
                    arr1[j][i] = v[pos[1]][cnt];
                    cnt++;
                }
            }
            for (int64 i = M / 2, cnt = 0; i < M; ++i) {
                for (int64 j = N / 2; j < N; ++j) {
                    arr1[j][i] = v[pos[2]][cnt];
                    cnt++;
                }
            }
        }
    }

    if (deq[1] == 0) {
        if (deq[0] == 1) {
            for (int64 i = 0, cnt = 0; i < N / 2; ++i) {
                for (int64 j = M - 1; j >= M / 2; --j) {
                    arr1[i][j] = v[pos[1]][cnt];
                    cnt++;
                }
            }
            for (int64 i = 0, cnt = 0; i < N / 2; ++i) {
                for (int64 j = M / 2 - 1; j >= 0; --j) {
                    arr1[i][j] = v[pos[0]][cnt];
                    cnt++;
                }
            }
            for (int64 i = N / 2, cnt = 0; i < N; ++i) {
                for (int64 j = M - 1; j >= M / 2; --j) {
                    arr1[i][j] = v[pos[2]][cnt];
                    cnt++;
                }
            }
            for (int64 i = N / 2, cnt = 0; i < N; ++i) {
                for (int64 j = M / 2 - 1; j >= 0; --j) {
                    arr1[i][j] = v[pos[3]][cnt];
                    cnt++;
                }
            }
        }
        else {
            dir = 1;
            int64 tmp;
            tmp = N;
            N = M;
            M = tmp;
            for (int64 i = M / 2 - 1, cnt = 0; i >= 0; --i) {
                for (int64 j = 0; j < N / 2; ++j) {
                    arr1[j][i] = v[pos[0]][cnt];
                    cnt++;
                }
            }
            for (int64 i = M - 1, cnt = 0; i >= M / 2; --i) {
                for (int64 j = 0; j < N / 2; ++j) {
                    arr1[j][i] = v[pos[1]][cnt];
                    cnt++;
                }
            }
            for (int64 i = M - 1, cnt = 0; i >= M / 2; --i) {
                for (int64 j = N / 2; j < N; ++j) {
                    arr1[j][i] = v[pos[2]][cnt];
                    cnt++;
                }
            }
            for (int64 i = M / 2 - 1, cnt = 0; i >= 0; --i) {
                for (int64 j = N / 2; j < N; ++j) {
                    arr1[j][i] = v[pos[3]][cnt];
                    cnt++;
                }
            }
        }
    }

    if (deq[2] == 0) {
        if (deq[1] == 1) {
            dir = 1;
            int64 tmp;
            tmp = N;
            N = M;
            M = tmp;
            for (int64 i = M / 2 - 1, cnt = 0; i >= 0; --i) {
                for (int64 j = N / 2 - 1; j >= 0; --j) {
                    arr1[j][i] = v[pos[0]][cnt];
                    cnt++;
                }
            }
            for (int64 i = M - 1, cnt = 0; i >= M / 2; --i) {
                for (int64 j = N / 2 - 1; j >= 0; --j) {
                    arr1[j][i] = v[pos[1]][cnt];
                    cnt++;
                }
            }
            for (int64 i = M - 1, cnt = 0; i >= M / 2; --i) {
                for (int64 j = N - 1; j >= N / 2; --j) {
                    arr1[j][i] = v[pos[2]][cnt];
                    cnt++;
                }
            }
            for (int64 i = M / 2 - 1, cnt = 0; i >= 0; --i) {
                for (int64 j = N - 1; j >= N / 2; --j) {
                    arr1[j][i] = v[pos[3]][cnt];
                    cnt++;
                }
            }
        }
        else {
            for (int64 i = N / 2 - 1, cnt = 0; i >= 0; --i) {
                for (int64 j = M / 2 - 1; j >= 0; --j) {
                    arr1[i][j] = v[pos[0]][cnt];
                    cnt++;
                }
            }
            for (int64 i = N / 2 - 1, cnt = 0; i >= 0; --i) {
                for (int64 j = M - 1; j >= M / 2; --j) {
                    arr1[i][j] = v[pos[1]][cnt];
                    cnt++;
                }
            }
            for (int64 i = N - 1, cnt = 0; i >= N / 2; --i) {
                for (int64 j = M - 1; j >= M / 2; --j) {
                    arr1[i][j] = v[pos[2]][cnt]; deq[0]; pos[0];
                    cnt++;
                }
            }
            for (int64 i = N - 1, cnt = 0; i >= N / 2; --i) {
                for (int64 j = M / 2 - 1; j >= 0; --j) {
                    arr1[i][j] = v[pos[3]][cnt];
                    cnt++;
                }
            }
        }
    }

    if (deq[3] == 0) {
        if (deq[0] == 1) {
            dir = 1;
            int64 tmp;
            tmp = N;
            N = M;
            M = tmp;
            for (int64 i = 0, cnt = 0; i < M / 2; ++i) {
                for (int64 j = N / 2 - 1; j >= 0; --j) {
                    arr1[j][i] = v[pos[0]][cnt];
                    cnt++;
                }
            }
            for (int64 i = M / 2, cnt = 0; i < M; ++i) {
                for (int64 j = N / 2 - 1; j >= 0; --j) {
                    arr1[j][i] = v[pos[1]][cnt];
                    cnt++;
                }
            }
            for (int64 i = M / 2, cnt = 0; i < M; ++i) {
                for (int64 j = N - 1; j >= N / 2; --j) {
                    arr1[j][i] = v[pos[2]][cnt];
                    cnt++;
                }
            }
            for (int64 i = 0, cnt = 0; i < M / 2; ++i) {
                for (int64 j = N - 1; j >= N / 2; --j) {
                    arr1[j][i] = v[pos[3]][cnt];
                    cnt++;
                }
            }
        }
        else {
            for (int64 i = N / 2 - 1, cnt = 0; i >= 0; --i) {
                for (int64 j = 0; j < M / 2; ++j) {
                    arr1[i][j] = v[pos[0]][cnt];
                    cnt++;
                }
            }
            for (int64 i = N / 2 - 1, cnt = 0; i >= 0; --i) {
                for (int64 j = M / 2; j < M; ++j) {
                    arr1[i][j] = v[pos[1]][cnt];
                    cnt++;
                }
            }
            for (int64 i = N - 1, cnt = 0; i >= N / 2; --i) {
                for (int64 j = M / 2; j < M; ++j) {
                    arr1[i][j] = v[pos[2]][cnt];
                    cnt++;
                }
            }
            for (int64 i = N - 1, cnt = 0; i >= N / 2; --i) {
                for (int64 j = 0; j < M / 2; ++j) {
                    arr1[i][j] = v[pos[3]][cnt];
                    cnt++;
                }
            }
        }
    }

}

int main() {
    fastio;

    for (int64 i = 0; i < 4; ++i) {
        deq.push_back(i);
        pos.push_back(i);
    }

    cin >> N >> M >> R;

    for (int64 i = 0; i < N; ++i) {
        for (int64 j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int64 i = 0; i < N / 2; ++i) {
        for (int64 j = 0; j < M / 2; ++j) {
            v[0].push_back(arr[i][j]);
        }
    }
    for (int64 i = 0; i < N / 2; ++i) {
        for (int64 j = M / 2; j < M; ++j) {
            v[1].push_back(arr[i][j]);
        }
    }
    for (int64 i = N / 2; i < N; ++i) {
        for (int64 j = 0; j < M / 2; ++j) {
            v[3].push_back(arr[i][j]);
        }
    }
    for (int64 i = N / 2; i < N; ++i) {
        for (int64 j = M / 2; j < M; ++j) {
            v[2].push_back(arr[i][j]);
        }
    }

    for (int64 i = 0; i < R; ++i) {
        int64 r, a = deq[0], b = deq[1], c = deq[2], d = deq[3], A = pos[0], B = pos[1], C = pos[2], D = pos[3];
        cin >> r;

        if (r == 1) {
            deq[0] = d;
            deq[1] = c;
            deq[2] = b;
            deq[3] = a;
            pos[0] = D;
            pos[1] = C;
            pos[2] = B;
            pos[3] = A;
        }
        else if (r == 2) {
            deq[0] = b;
            deq[1] = a;
            deq[2] = d;
            deq[3] = c;
            pos[0] = B;
            pos[1] = A;
            pos[2] = D;
            pos[3] = C;
        }
        else if (r == 3) {
            deq.pop_back();
            deq.push_front(d);
            pos.pop_back();
            pos.push_front(D);
        }
        else if (r == 4) {
            deq.pop_front();
            deq.push_back(a);
            pos.pop_front();
            pos.push_back(A);
        }
        else if (r == 5) {
            pos.pop_back();
            pos.push_front(D);
        }
        else if (r == 6) {
            pos.pop_front();
            pos.push_back(A);
        }
    }

    makeArr();

    for (int64 i = 0; i < N; ++i) {
        for (int64 j = 0; j < M; ++j) {
            cout << arr1[i][j] << ' ';
        }
        cout << "\n";
    }

    return EXIT_SUCCESS;
}