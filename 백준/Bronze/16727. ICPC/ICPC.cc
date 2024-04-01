#include <iostream>
using namespace std;
int main() {
    int a[4];
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    if (a[0] + a[3] > a[1] + a[2]) cout << "Persepolis\n";
    else if (a[0] + a[3] < a[1] + a[2])cout << "Esteghlal\n";
    else
    {
        if(a[1] == a[3])
            cout << "Penalty\n";
        else
        {
            if(a[1]<a[3])
                cout << "Persepolis\n";
            else
                cout << "Esteghlal\n";
        }
    }
}