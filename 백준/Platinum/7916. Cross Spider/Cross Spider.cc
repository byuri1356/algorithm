#include<iostream>
using namespace std;
using int64 = int64_t;

typedef struct {
    int64 x, y, z;
}SpaceDot;

SpaceDot SD[1'000'00];

inline SpaceDot MakeVector(SpaceDot v1, SpaceDot v2) {
    SpaceDot temp;
    temp.x = v2.x - v1.x;
    temp.y = v2.y - v1.y;
    temp.z = v2.z - v1.z;
    return temp;
}

inline SpaceDot CrossVector(SpaceDot v1, SpaceDot v2) {
    SpaceDot temp;
    temp.x = v1.y * v2.z - v1.z * v2.y;
    temp.y = v1.z * v2.x - v1.x * v2.z;
    temp.z = v1.x * v2.y - v1.y * v2.x;
    return temp;
}

inline int64 PlaneVector(SpaceDot Cross, SpaceDot v) {
    int64 temp = Cross.x * v.x + Cross.y * v.y + Cross.z * v.z;
    return temp;
}

inline SpaceDot PlaneEqual(SpaceDot v1, SpaceDot v2, SpaceDot v3) {
    SpaceDot temp, tmp;
    temp = MakeVector(v1, v2);
    tmp = MakeVector(v2, v3);

    return CrossVector(temp, tmp);
}

inline void solve() {
    int64 C;

    cin >> C;
    for (int64 count = 0; count < C;) {
        cin >> SD[count].x >> SD[count].y >> SD[count].z;
        ++count;
    }

    SpaceDot result;
    int64 num = 0;
    for (int64 count = 0; count < C - 2;) {
        result = PlaneEqual(SD[count], SD[count + 1], SD[count + 2]);
        num = count;
        if (result.x != 0 || result.y != 0 || result.z != 0) {
            num = count;
            break;
        }
        ++count;
    }

    int64 dis = PlaneVector(result, SD[num]);
    int64 include = 0;
    for (int64 count = 0; count < C; ) {
        if (PlaneVector(result, SD[count]) - dis == 0) {
            include++;
        }
        ++count;
    }
    if (C <= 3) {
        cout << "TAK" << "\n";
    }
    else if (include == C) {
        cout << "TAK" << "\n";
    }
    else {
        cout << "NIE" << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}