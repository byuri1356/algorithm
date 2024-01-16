#include <iostream>
using namespace std;

int main(){
    int n, temp, count = 0;
    cin>>n;
    for(int t = 0; t < 5; t++){
        cin>>temp;
        if(temp == n){
            count += 1;
        }
    }
    cout<<count;
    return 0;
}