#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;  

    int ammo_count = 0;
    int last_save = 0;
    bool has_save = false;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "ammo") {
            ammo_count += k;
        } else if (s == "save") {
            last_save = ammo_count;
            has_save = true;
        } else if (s == "shoot") {
            if (ammo_count > 0) ammo_count--;
        } else if (s == "load") {
            ammo_count = has_save ? last_save : 0;
        }

        cout << ammo_count << "\n";
    }

    return 0;
}