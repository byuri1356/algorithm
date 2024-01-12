#include <iostream>
using namespace std;
int main() {
    int c, n, m;
    cin>>c>>n>>m;
    int ans = (c*n)-m;
    if (ans > 0)
        cout<<ans;
    else
        cout<<"0";
    return 0;
}