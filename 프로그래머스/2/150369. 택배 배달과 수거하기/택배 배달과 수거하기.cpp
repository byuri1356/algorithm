#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    ll answer = 0;
    int didx = n - 1, pidx = n - 1;
    
    while((didx > -1) || (pidx > -1)){
        while((didx > -1) && (deliveries[didx] == 0)) didx--;
        while((pidx > -1) && (pickups[pidx] == 0)) pidx--;
        
        answer += (max(didx, pidx) + 1) * 2;
        
        int pack = cap;
        while(didx > -1 && pack > 0){
            int dumy = deliveries[didx];
            deliveries[didx] = max(0, deliveries[didx] - pack);
            pack -= dumy;
            if(deliveries[didx] == 0) didx--;
        }
        
        pack = cap;
        while(pidx > -1 && pack > 0){
            int dumy = pickups[pidx];
            pickups[pidx] = max(0, pickups[pidx] - pack);
            pack -= dumy;
            if(pickups[pidx] == 0) pidx--;
        }
    }
    
    return answer;
}