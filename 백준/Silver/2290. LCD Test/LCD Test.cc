#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF 2147483647
using namespace std;
using int64 = int64_t;



int main() {
    fastio;

    int64 s;
    string n;
    cin >> s >> n;

    for (int64 i = 0; i < n.length(); ++i) {
        if (n[i] == '0' || n[i] == '2' || n[i] == '3' || n[i] == '5' || n[i] == '6' || n[i] == '7' || n[i] == '8' || n[i] == '9') {
            cout << ' ';
            for (int64 j = 0; j < s; ++j) {
                cout << '-';
            }
            cout << ' ' << ' ';
        }
       
        else {
            cout << ' ';
            for (int64 j = 0; j < s; ++j) {
                cout << ' ';
            }
            cout << ' ' << ' ';
        }
    }
    cout << "\n";

    for (int64 j = 0; j < s; ++j) {
        for (int64 i = 0; i < n.length(); ++i) {
            if (n[i] == '4' || n[i] == '5' || n[i] == '6' || n[i] == '8' || n[i] == '9' || n[i] == '0') {
                cout << '|';
            }
            else {
                cout << ' ';
            }
            for (int64 i = 0; i < s; ++i) {
                cout << ' ';
            }
            if (n[i] == '1' || n[i] == '2' || n[i] == '3' || n[i] == '4' || n[i] == '7' || n[i] == '8' || n[i] == '9' || n[i] == '0') {
                cout << '|';
            }
            else {
                cout << ' ';
            }
            cout << ' ';
        }
        cout << "\n";
    }
  
    for (int64 i = 0; i < n.length(); ++i) {
        if (n[i] == '2' || n[i] == '3' || n[i] == '4' || n[i] == '5' || n[i] == '6' || n[i] == '8' || n[i] == '9') {
            cout << ' ';
            for (int64 j = 0; j < s; ++j) {
                cout << '-';
            }
            cout << ' ' << ' ';
        }

        else {
            cout << ' ';
            for (int64 j = 0; j < s; ++j) {
                cout << ' ';
            }
            cout << ' ' << ' ';
        }
    }
    cout << "\n";

    for (int64 j = 0; j < s; ++j) {
        for (int64 i = 0; i < n.length(); ++i) {
            if (n[i] == '2' || n[i] == '6' || n[i] == '8' || n[i] == '0') {
                cout << '|';
            }
            else {
                cout << ' ';
            }
            for (int64 i = 0; i < s; ++i) {
                cout << ' ';
            }
            if (n[i] == '1' || n[i] == '3' || n[i] == '4' || n[i] == '5' || n[i] == '6' || n[i] == '7' || n[i] == '8' || n[i] == '9' || n[i] == '0') {
                cout << '|';
            }
            else {
                cout << ' ';
            }
            cout << ' ';
        }
        cout << "\n";
    }

    for (int64 i = 0; i < n.length(); ++i) {
        if (n[i] == '2' || n[i] == '3' || n[i] == '5' || n[i] == '6' || n[i] == '8' || n[i] == '9' || n[i] == '0') {
            cout << ' ';
            for (int64 j = 0; j < s; ++j) {
                cout << '-';
            }
            cout << ' ' << ' ';
        }

        else {
            cout << ' ';
            for (int64 j = 0; j < s; ++j) {
                cout << ' ';
            }
            cout << ' ' << ' ';
        }
    }

    return EXIT_SUCCESS;
}