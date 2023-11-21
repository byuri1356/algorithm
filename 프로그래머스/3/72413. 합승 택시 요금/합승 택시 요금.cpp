#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF INT32_MAX
using namespace std;
using int64 = int64_t;

int64 dist[3][201];
vector<pair<int64, int64>> vp[201];
priority_queue<pair<int64, int64>> pq; 

void Dijkstra(int n, int st){
    dist[n][st] = 0;
    pq.push({0, st});
    
    while(!pq.empty()){
        int64 dis = -pq.top().first;
        int64 cur = pq.top().second;
        
        pq.pop();
        
        if(dist[n][cur] < dis) continue;
        
        for(int i=0; i<vp[cur].size(); ++i){
            int64 next_d = vp[cur][i].first + dis;
            int64 next_c = vp[cur][i].second;
            
            if(dist[n][next_c] > next_d){
                dist[n][next_c] = next_d;
                pq.push({-next_d, next_c});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int64 answer = INF;
    
    for(int i = 0; i<3; ++i){
        for(int j=1; j<201; ++j){
            dist[i][j] = INF;
        }
    }
    
    for(auto iter : fares){
        vp[iter[0]].push_back({iter[2], iter[1]});
        vp[iter[1]].push_back({iter[2], iter[0]});
    }
    
    Dijkstra(0,s);  
    Dijkstra(1,a);
    Dijkstra(2,b);
    
   for(int i=1; i<=n; ++i){
       answer = min(answer, dist[0][i] + dist[1][i] + dist[2][i]);
   }
    
    return answer;
}