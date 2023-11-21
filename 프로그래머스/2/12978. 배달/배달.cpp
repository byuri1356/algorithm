#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1e9

vector<int> dist;
vector<pair<int, int>> adj[51];
priority_queue<pair<int, int>> pq;

void dijkstra(){
    dist[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        int d = -pq.top().first;
        int c = pq.top().second;
        
        pq.pop();
        
        if(dist[c] < d) continue;
        
        for(int i=0; i<adj[c].size(); ++i){
            int n = adj[c][i].first;
            int nd = adj[c][i].second;
            if(d + nd < dist[n] ){
                dist[n] = d + nd;
                pq.push({-(d + nd), n});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    dist.resize(N + 1, 1e9);

    for(auto& v: road){
        int a = v[0], b = v[1], d = v[2];
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }
    
    dijkstra();
    
    for(int i=1; i<=N; ++i){
        if(dist[i]<=K) answer++;
    }

    return answer;
}